#ifndef SNAKE_H
#define SNAKE_H
#define MAX_SIZE 200

struct pos {
    int _x;
    int _y;
};

// NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3

void initialize_snake(struct pos start_position);
void set_direction(int direction);
int get_direction();
struct pos advance();
void eat();
void free_snake();

#endif
