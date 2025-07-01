#include "floodfill.h"

static uint8_t walls[MAZE_SIZE][MAZE_SIZE];
static uint8_t flood[MAZE_SIZE][MAZE_SIZE];

// Robot state
static uint8_t pos_x = 0;
static uint8_t pos_y = 0;
static Direction heading = DIR_NORTH;

// Goal
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
            uint8_t dx = (x > goal_x) ? x - goal_x : goal_x - x;
            uint8_t dy = (y > goal_y) ? y - goal_y : goal_y - y;
            flood[y][x] = dx + dy;
            walls[y][x] = 0;

            if (y == 0)                   walls[y][x] |= (1 << DIR_SOUTH);
            if (y == MAZE_SIZE - 1)       walls[y][x] |= (1 << DIR_NORTH);
            if (x == 0)                   walls[y][x] |= (1 << DIR_WEST);
            if (x == MAZE_SIZE - 1)       walls[y][x] |= (1 << DIR_EAST);
        }
    }
    pos_x = 0;
    pos_y = 0;
    heading = DIR_NORTH;
}

static void set_wall(uint8_t x, uint8_t y, Direction dir)
{
    if (x >= MAZE_SIZE || y >= MAZE_SIZE)
        return;
    walls[y][x] |= (1 << dir);
}

void floodfill_update_walls(uint8_t front, uint8_t left, uint8_t right) {
    if (front) {
        set_wall(pos_x, pos_y, heading);
        uint8_t nx = pos_x, ny = pos_y;
        if (heading == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
        else if (heading == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
        else if (heading == DIR_SOUTH && ny > 0) ny--;
        else if (heading == DIR_WEST && nx > 0) nx--;
        set_wall(nx, ny, (heading + 2) % 4);
    }
    if (left) {
        Direction dir = (heading + 3) % 4;
        set_wall(pos_x, pos_y, dir);
        uint8_t nx = pos_x, ny = pos_y;
        if (dir == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
        else if (dir == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
        else if (dir == DIR_SOUTH && ny > 0) ny--;
        else if (dir == DIR_WEST && nx > 0) nx--;
        set_wall(nx, ny, (dir + 2) % 4);
    }
    if (right) {
        Direction dir = (heading + 1) % 4;
        set_wall(pos_x, pos_y, dir);
        uint8_t nx = pos_x, ny = pos_y;
        if (dir == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
        else if (dir == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
        else if (dir == DIR_SOUTH && ny > 0) ny--;
        else if (dir == DIR_WEST && nx > 0) nx--;
        set_wall(nx, ny, (dir + 2) % 4);
    }
}

void floodfill_step(void) {
    uint8_t changed = 1;
    while (changed) {
        changed = 0;
        for (uint8_t y = 0; y < MAZE_SIZE; y++) {
            for (uint8_t x = 0; x < MAZE_SIZE; x++) {
                uint8_t new_val = flood[y][x];
                for (uint8_t d = 0; d < 4; d++) {
                    if (walls[y][x] & (1 << d)) continue;

                    int nx = x, ny = y;
                    if (d == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
                    else if (d == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
                    else if (d == DIR_SOUTH && ny > 0) ny--;
                    else if (d == DIR_WEST && nx > 0) nx--;
                    else continue;

                    uint8_t cand = flood[ny][nx] + 1;
                    if (cand < new_val) new_val = cand;
                }
                if (new_val != flood[y][x]) {
                    flood[y][x] = new_val;
                    changed = 1;
                }
            }
        }
    }
}

Direction floodfill_next_move(void) {
    uint8_t min = 255;
    Direction best = heading;

    for (uint8_t d = 0; d < 4; d++) {
        if (walls[pos_y][pos_x] & (1 << d)) continue;

        int nx = pos_x, ny = pos_y;

        if (d == DIR_NORTH && ny + 1 < MAZE_SIZE) {
            ny++;
        } else if (d == DIR_EAST) {
            // turn in place — no nx++
        } else if (d == DIR_SOUTH && ny > 0) {
            ny--;
        } else if (d == DIR_WEST) {
            // turn in place — no nx--
        } else {
            continue;
        }

        if (flood[ny][nx] < min) {
            min = flood[ny][nx];
            best = d;
        }
    }

    if (min != 255) {
        if (best == DIR_NORTH) {
            pos_y++;
            heading = DIR_NORTH;
        } else if (best == DIR_EAST) {
            heading = DIR_EAST;
        } else if (best == DIR_SOUTH) {
            pos_y--;
            // keep heading unchanged for backward move
        } else if (best == DIR_WEST) {
            heading = DIR_WEST;
        }
    }

    return best;
}

