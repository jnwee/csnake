#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

// *snake_ptr[0] = HEAD, [length - 1] = TAIL
struct pos *snake_ptr;
int _length;
int _direction;

void initialize_snake(struct pos start_position) {
    printf("Initializing snake with start position: %d - %d\n", start_position._x, start_position._y);

    snake_ptr[0].set(start_position._x, start_position._y);
    _length = 1;
    _direction = 3;
}

void set_direction(int direction) {
    printf("Setting direction from: %d to: %d\n", _direction, direction);

    if (direction < 0 || direction > 3) {
        printf("Invalid direction: %d!\n", _direction);
        exit(1);
    }

    _direction = direction;
}

int get_direction() {
    printf("Getting direction: %d\n", _direction);

    return _direction;
}

void advance() {
    printf("Advancing snake towards direction: %d\n", _direction);

    switch (_direction) {

    }
}
