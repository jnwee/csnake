#ifndef SNAKE_H
#define SNAKE_H
#define MAX_SIZE = 200;

struct pos {
    int _x;
    int _y;

    void set_x(int x) {
        _x = x;
    };

    void set_y(int y) {
        _y = y;
    };

    void set(int x, int y) {
        _x = x;
        _y = y;
    };
};

// NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3

void initialize_snake(struct pos start_position);
void set_direction(int direction);
int get_direction();
void advance();
void eat();
struct pos get_tail_pos();
struct pos get_head_pos();
void free_snake();

#endif
