#ifndef BOARD_H
#define BOARD_H
#include "snake.h"
// 0 = GRASS, 1 = WALL, 2 = FOOD, 3 = SNAKE

void initialize_board(int size);
int check_tile(struct pos pos);
void set_tile(struct pos pos, int type);
void print_board_state();
void free_board();

#endif
