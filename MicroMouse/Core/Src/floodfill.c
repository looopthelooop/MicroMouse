#include "floodfill.h"
#include <stdlib.h>

static uint8_t walls[MAZE_SIZE][MAZE_SIZE];
static uint8_t flood[MAZE_SIZE][MAZE_SIZE];

static uint8_t pos_x = 0;
static uint8_t pos_y = 0;
static Direction heading = DIR_NORTH;

static uint8_t goal_x = MAZE_SIZE / 2;
static uint8_t goal_y = MAZE_SIZE / 2;

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

            // Set boundary walls (y=0 is bottom, y increases upward)
            if (y == 0) walls[y][x] |= (1 << DIR_SOUTH);           // Bottom boundary blocks south
            if (y == MAZE_SIZE - 1) walls[y][x] |= (1 << DIR_NORTH); // Top boundary blocks north
            if (x == 0) walls[y][x] |= (1 << DIR_WEST);            // Left boundary blocks west
            if (x == MAZE_SIZE - 1) walls[y][x] |= (1 << DIR_EAST); // Right boundary blocks east
        }
    }
    pos_x = 0;
    pos_y = 0;
    heading = DIR_NORTH;
}

static void set_wall(uint8_t x, uint8_t y, Direction dir) {
    if (x >= MAZE_SIZE || y >= MAZE_SIZE) return;
    walls[y][x] |= (1 << dir);
}

static void set_wall_both(uint8_t x, uint8_t y, Direction dir) {
    set_wall(x, y, dir);
    uint8_t nx = x, ny = y;

    // Move to neighboring cell based on absolute direction (y=0 at bottom)
    if (dir == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
    else if (dir == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
    else if (dir == DIR_SOUTH && ny > 0) ny--;
    else if (dir == DIR_WEST && nx > 0) nx--;
    else return;

    // Set opposite wall in neighboring cell
    set_wall(nx, ny, (dir + 2) % 4);
}

void floodfill_update_walls(uint8_t front, uint8_t left, uint8_t right) {
    if (front) set_wall_both(pos_x, pos_y, heading);
    if (left) set_wall_both(pos_x, pos_y, (heading + 3) % 4);
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
                    // Move based on absolute direction (y=0 at bottom)
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

// Helper function to move robot position based on absolute direction (y=0 at bottom)
static void move_robot(Direction absolute_dir) {
    uint8_t new_x = pos_x, new_y = pos_y;

    if (absolute_dir == DIR_NORTH && new_y + 1 < MAZE_SIZE) new_y++;
    else if (absolute_dir == DIR_EAST && new_x + 1 < MAZE_SIZE) new_x++;
    else if (absolute_dir == DIR_SOUTH && new_y > 0) new_y--;
    else if (absolute_dir == DIR_WEST && new_x > 0) new_x--;
    else return; // Invalid move, don't update position

    pos_x = new_x;
    pos_y = new_y;
}

Direction floodfill_next_move(void) {
    uint8_t min = 255;
    Direction best_absolute_dir = heading;

    // Find the absolute direction with lowest flood value
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
            best_absolute_dir = d;
        }
    }

    if (min == 255) return DIR_NORTH; // No valid moves, return forward

    // Convert absolute direction to relative command
    if (best_absolute_dir == heading) {
        // Move forward in current heading
        move_robot(heading);
        return DIR_NORTH; // Command: move forward
    }
    else if (best_absolute_dir == (heading + 2) % 4) {
        // Move backward (opposite to current heading)
        move_robot(best_absolute_dir);
        return DIR_SOUTH; // Command: move backward
    }
    else if (best_absolute_dir == (heading + 1) % 4) {
        // Need to turn right
        heading = best_absolute_dir;
        return DIR_EAST; // Command: turn right (no position change)
    }
    else if (best_absolute_dir == (heading + 3) % 4) {
        // Need to turn left
        heading = best_absolute_dir;
        return DIR_WEST; // Command: turn left (no position change)
    }

    // Fallback
    return DIR_NORTH;
}

