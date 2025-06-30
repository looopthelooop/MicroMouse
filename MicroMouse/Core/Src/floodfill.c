#include "floodfill.h"

// Flood distances
static uint8_t flood[MAZE_SIZE][MAZE_SIZE];

// Wall bits: bit0=N, bit1=E, bit2=S, bit3=W
static uint8_t walls[MAZE_SIZE][MAZE_SIZE];

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
        }
    }
    pos_x = 0;
    pos_y = 0;
    heading = DIR_NORTH;
}

void floodfill_update_walls(uint8_t front, uint8_t left, uint8_t right) {
    uint8_t *w = &walls[pos_y][pos_x];
    if (front) *w |= (1 << heading);
    if (left)  *w |= (1 << ((heading + 3) % 4));
    if (right) *w |= (1 << ((heading + 1) % 4));
}

void floodfill_step(void) {
    uint8_t changed = 1;
    while (changed) {
        changed = 0;
        for (uint8_t y = 0; y < MAZE_SIZE; y++) {
            for (uint8_t x = 0; x < MAZE_SIZE; x++) {
                uint8_t min = 255;
                for (uint8_t d = 0; d < 4; d++) {
                    if (walls[y][x] & (1 << d)) continue;

                    int nx = x, ny = y;
                    if (d == DIR_NORTH && ny + 1 < MAZE_SIZE) ny++;
                    else if (d == DIR_EAST && nx + 1 < MAZE_SIZE) nx++;
                    else if (d == DIR_SOUTH && ny > 0) ny--;
                    else if (d == DIR_WEST && nx > 0) nx--;
                    else continue;

                    if (flood[ny][nx] < min) min = flood[ny][nx];
                }
                if (min + 1 < flood[y][x]) {
                    flood[y][x] = min + 1;
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

    if (best == DIR_NORTH) pos_y++;
    else if (best == DIR_EAST) pos_x++;
    else if (best == DIR_SOUTH) pos_y--;
    else if (best == DIR_WEST) pos_x--;

    heading = best;

    return best;
}
