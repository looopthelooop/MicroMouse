#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <stdint.h>

#define MAZE_SIZE 16

typedef enum {
    DIR_NORTH = 0,
    DIR_EAST  = 1,
    DIR_SOUTH = 2,
    DIR_WEST  = 3
} Direction;

typedef struct {
    uint8_t x;
    uint8_t y;
} Cell;

uint8_t floodfill_is_goal_reached(void);

void floodfill_init(void);
void floodfill_set_goal(uint8_t gx, uint8_t gy);

void floodfill_update_walls(uint8_t front, uint8_t left, uint8_t right);
void floodfill_step(void);

uint8_t floodfill_next_motor_targets(float *pos_target_R, float *pos_target_L);
void floodfill_extract_path_back(void);
uint8_t floodfill_replay_motor_targets(float *pos_target_R, float *pos_target_L);

int8_t floodfill_get_path_index(void); // exposes path_index safely

uint8_t floodfill_get_pos_x(void);
uint8_t floodfill_get_pos_y(void);
Direction floodfill_get_heading(void);

#endif
