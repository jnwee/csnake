#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

#define MAX_SIZE 200

// *snake_ptr[0] = HEAD, [length - 1] = TAIL
struct pos *snake_ptr;
int head;
int tail;
int _direction;

void initialize_snake(struct pos start_position) {
    printf("Initializing snake with start position: %d - %d\n", start_position._x, start_position._y);

    snake_ptr = (struct pos *)malloc(MAX_SIZE * sizeof(struct pos));

    if (snake_ptr == NULL) {
        printf("ERROR: Memory for snake couldn't be allocated. Exiting now.");
        exit(1);
    }

    snake_ptr[0]._x = start_position._x;
    snake_ptr[0]._y = start_position._y;
    head = 0;
    tail = 0;
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

struct pos advance() {
    printf("Advancing snake towards direction: %d\n", _direction);

    struct pos head_pos = snake_ptr[head];
    switch (_direction) {
        case 0:
            snake_ptr[head + 1]._y = head_pos._y - 1;
        case 1:
            snake_ptr[head + 1]._x = head_pos._x + 1;
        case 2:
            snake_ptr[head + 1]._y = head_pos._y + 1;
        case 3:
            snake_ptr[head + 1]._x = head_pos._x - 1;
    }
    if (head == MAX_SIZE - 1) {
        printf("Max size of snake reached, resetting to 0... \n");
        head = -1;
    }
    if (tail == MAX_SIZE - 1) {
        printf("Tail reached max size of snake, resetting to 0... \n");
        tail = -1;
    }
    head++;
    tail++;

    return snake_ptr[head];
}

void eat() {
    printf("Snake grows in size\n");

    tail--;
    if (tail < 0) {
        printf("Tail reached negative, resetting to MAX_SIZE - 1...");
        tail = MAX_SIZE - 1;
    }
}

void free_snake() {
    free(snake_ptr);
}
