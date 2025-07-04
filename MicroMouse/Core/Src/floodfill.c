#include "floodfill.h"
#include <stdlib.h>

static uint8_t walls[MAZE_SIZE][MAZE_SIZE];
static uint8_t flood[MAZE_SIZE][MAZE_SIZE];

static uint8_t pos_x = 0;
static uint8_t pos_y = 0;
static Direction heading = DIR_NORTH;

static uint8_t goal_x = MAZE_SIZE / 2;
static uint8_t goal_y = MAZE_SIZE / 2;

// Path planning for return journey
static uint8_t return_path[MAZE_SIZE * MAZE_SIZE][2];  // [x, y] coordinates
static uint8_t path_length = 0;
static uint8_t path_index = 0;
static uint8_t goal_reached = 0;
static uint8_t return_mode = 0;

void floodfill_set_goal(uint8_t gx, uint8_t gy) {
    if (gx < MAZE_SIZE && gy < MAZE_SIZE) {
        goal_x = gx;
        goal_y = gy;
    }
}

void floodfill_init(void) {
    for (uint8_t y = 0; y < MAZE_SIZE; y++) {
        for (uint8_t x = 0; x < MAZE_SIZE; x++) {
            flood[y][x] = abs(x - goal_x) + abs(y - goal_y);
            walls[y][x] = 0;

            // Set boundary walls
            if (y == 0) walls[y][x] |= (1 << DIR_SOUTH);
            if (y == MAZE_SIZE - 1) walls[y][x] |= (1 << DIR_NORTH);
            if (x == 0) walls[y][x] |= (1 << DIR_WEST);
            if (x == MAZE_SIZE - 1) walls[y][x] |= (1 << DIR_EAST);
        }
    }
    pos_x = 0;
    pos_y = 0;
    heading = DIR_NORTH;
    goal_reached = 0;
    return_mode = 0;
    path_length = 0;
    path_index = 0;
}

static void set_wall(uint8_t x, uint8_t y, Direction dir) {
    if (x >= MAZE_SIZE || y >= MAZE_SIZE) return;
    walls[y][x] |= (1 << dir);
}

static void set_wall_both(uint8_t x, uint8_t y, Direction dir) {
    set_wall(x, y, dir);
    uint8_t nx = x, ny = y;

    if (dir == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
    else if (dir == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
    else if (dir == DIR_SOUTH && ny > 0) ny--;
    else if (dir == DIR_WEST && nx > 0) nx--;
    else return;

    set_wall(nx, ny, (dir + 2) % 4);
}

void floodfill_update_walls(uint8_t front, uint8_t left, uint8_t right) {
    if (front) set_wall_both(pos_x, pos_y, heading);
    if (left)  set_wall_both(pos_x, pos_y, (heading + 3) % 4);
    if (right) set_wall_both(pos_x, pos_y, (heading + 1) % 4);
}

void floodfill_step(void) {
    flood[goal_y][goal_x] = 0;
    uint8_t changed;
    do {
        changed = 0;
        for (uint8_t y = 0; y < MAZE_SIZE; y++) {
            for (uint8_t x = 0; x < MAZE_SIZE; x++) {
                if (x == goal_x && y == goal_y) continue;
                uint8_t min_val = 255;
                for (uint8_t d = 0; d < 4; d++) {
                    if (walls[y][x] & (1 << d)) continue;

                    uint8_t nx = x, ny = y;
                    if (d == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
                    else if (d == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
                    else if (d == DIR_SOUTH && ny > 0) ny--;
                    else if (d == DIR_WEST && nx > 0) nx--;
                    else continue;

                    if (flood[ny][nx] < min_val) min_val = flood[ny][nx];
                }
                uint8_t new_val = min_val + 1;
                if (new_val != flood[y][x]) {
                    flood[y][x] = new_val;
                    changed = 1;
                }
            }
        }
    } while (changed);
}

// Calculate complete optimal path from current position to start
static void calculate_return_path(void) {
    // Save current heading to preserve robot's actual orientation
    Direction saved_heading = heading;

    // Set goal to start position and recalculate flood fill
    floodfill_set_goal(0, 0);
    floodfill_step();

    // Restore the actual heading
    heading = saved_heading;

    // Build path by following flood fill gradient
    path_length = 0;
    uint8_t cx = pos_x, cy = pos_y;

    while ((cx != 0 || cy != 0) && path_length < (MAZE_SIZE * MAZE_SIZE - 1)) {
        uint8_t best_x = cx, best_y = cy;
        uint8_t min_flood = flood[cy][cx];

        // Find neighboring cell with lowest flood value
        for (Direction d = 0; d < 4; d++) {
            if (walls[cy][cx] & (1 << d)) continue;

            uint8_t nx = cx, ny = cy;
            if (d == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
            else if (d == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
            else if (d == DIR_SOUTH && ny > 0) ny--;
            else if (d == DIR_WEST && nx > 0) nx--;
            else continue;

            if (flood[ny][nx] < min_flood) {
                min_flood = flood[ny][nx];
                best_x = nx;
                best_y = ny;
            }
        }

        if (best_x == cx && best_y == cy) break; // Stuck

        // Add to path
        return_path[path_length][0] = best_x;
        return_path[path_length][1] = best_y;
        path_length++;

        cx = best_x;
        cy = best_y;
    }

    path_index = 0;
}

// Get direction needed to move from current position to target position
static Direction get_move_direction(uint8_t from_x, uint8_t from_y, uint8_t to_x, uint8_t to_y) {
    if (to_x > from_x) return DIR_EAST;
    if (to_x < from_x) return DIR_WEST;
    if (to_y > from_y) return DIR_NORTH;
    if (to_y < from_y) return DIR_SOUTH;
    return DIR_NORTH; // Should not happen
}

uint8_t floodfill_next_motor_targets(float *pos_target_R, float *pos_target_L) {
    // Check if we've reached the original goal
    if (!goal_reached && pos_x == goal_x && pos_y == goal_y) {
        goal_reached = 1;
        return_mode = 1;
        calculate_return_path();
    }

    // Exploration mode - allow forward, backward, left, right (NO U-TURN)
    if (!return_mode) {
        uint8_t min = 255;
        Direction best = heading;

        // Find best direction (all 4 directions allowed)
        for (uint8_t d = 0; d < 4; d++) {
            if (walls[pos_y][pos_x] & (1 << d)) continue;

            uint8_t nx = pos_x, ny = pos_y;
            if (d == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
            else if (d == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
            else if (d == DIR_SOUTH && ny > 0) ny--;
            else if (d == DIR_WEST && nx > 0) nx--;
            else continue;

            if (flood[ny][nx] < min) {
                min = flood[ny][nx];
                best = d;
            }
        }

        if (min == 255) return 0;

        // Execute movement based on required direction vs current heading
        if (best == heading) {
            // Move forward
            *pos_target_R = 21.0f;
            *pos_target_L = 21.0f;
            if (heading == DIR_NORTH) pos_y++;
            else if (heading == DIR_EAST) pos_x++;
            else if (heading == DIR_SOUTH) pos_y--;
            else if (heading == DIR_WEST) pos_x--;
        } else if (best == (heading + 1) % 4) {
            // Turn right (90° clockwise)
            *pos_target_R = -7.0f;
            *pos_target_L = 7.0f;
            heading = best;
        } else if (best == (heading + 3) % 4) {
            // Turn left (90° counter-clockwise)
            *pos_target_R = 7.0f;
            *pos_target_L = -7.0f;
            heading = best;
        } else if (best == (heading + 2) % 4) {
            // Backward movement (NO heading change, just reverse motors)
            *pos_target_R = -21.0f;
            *pos_target_L = -21.0f;
            // Update position but keep same heading
            if (heading == DIR_NORTH) pos_y--;
            else if (heading == DIR_EAST) pos_x--;
            else if (heading == DIR_SOUTH) pos_y++;
            else if (heading == DIR_WEST) pos_x++;
        }
        return 1;
    }

    // Return mode - follow calculated path (allow backward movement, no U-turn)
    if (path_index >= path_length) return 0;

    uint8_t target_x = return_path[path_index][0];
    uint8_t target_y = return_path[path_index][1];

    // Get required direction for this move
    Direction required_dir = get_move_direction(pos_x, pos_y, target_x, target_y);

    // Calculate multi-cell movement variables
    uint8_t cells_to_move = 1;
    uint8_t final_x = target_x;
    uint8_t final_y = target_y;
    uint8_t temp_index = path_index + 1;

    // Look ahead for consecutive moves in same direction
    while (temp_index < path_length) {
        uint8_t next_target_x = return_path[temp_index][0];
        uint8_t next_target_y = return_path[temp_index][1];
        Direction next_dir = get_move_direction(final_x, final_y, next_target_x, next_target_y);

        if (next_dir == required_dir) {
            cells_to_move++;
            final_x = next_target_x;
            final_y = next_target_y;
            temp_index++;
        } else {
            break;
        }
    }

    // Determine movement type
    if (heading == required_dir) {
        // Move forward
        *pos_target_R = 21.0f * cells_to_move;
        *pos_target_L = 21.0f * cells_to_move;
    } else if (required_dir == (heading + 2) % 4) {
        // Move backward (no heading change)
        *pos_target_R = -21.0f * cells_to_move;
        *pos_target_L = -21.0f * cells_to_move;
    } else {
        // Need to turn first (left or right only)
        int turn_diff = (required_dir - heading + 4) % 4;

        if (turn_diff == 1) {
            // Turn right
            *pos_target_R = -7.0f;
            *pos_target_L = 7.0f;
            heading = required_dir;
        } else if (turn_diff == 3) {
            // Turn left
            *pos_target_R = 7.0f;
            *pos_target_L = -7.0f;
            heading = required_dir;
        }
        return 1;
    }

    // Update position and path index
    pos_x = final_x;
    pos_y = final_y;
    path_index = temp_index;

    return 1;
}

uint8_t floodfill_get_pos_x(void) { return pos_x; }
uint8_t floodfill_get_pos_y(void) { return pos_y; }
Direction floodfill_get_heading(void) { return heading; }
uint8_t floodfill_get_goal_x(void) { return goal_x; }
uint8_t floodfill_get_goal_y(void) { return goal_y; }
uint8_t floodfill_is_goal_reached(void) { return goal_reached; }
