#ifndef BOARD_H
#define BOARD_H

// 0 = GRASS, 1 = WALL, 2 = FOOD, 3 = SNAKE

void initialize_board(int size);
int check_tile(int x, int y);
void set_tile(int x, int y, int type);
void print_board_state();
void free_board();

#endif
