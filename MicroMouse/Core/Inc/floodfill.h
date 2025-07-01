#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <stdint.h>

#define MAZE_SIZE 4

typedef enum {
    DIR_NORTH = 0,
    DIR_EAST,
    DIR_SOUTH,
    DIR_WEST
} Direction;

// Initialize flood map and pose
void floodfill_init(void);

// Set new goal (call before floodfill_init)
void floodfill_set_goal(uint8_t goal_x, uint8_t goal_y);

// Update walls from sensors (0 = open, 1 = wall)
void floodfill_update_walls(uint8_t front, uint8_t left, uint8_t right);

// Propagate distances
void floodfill_step(void);


// Decide next move + update pose
Direction floodfill_next_move(void);

#endif
