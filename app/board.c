#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "snake.h"

int *snake_board_ptr;
int board_size;

void initialize_board(int size) {
    printf("Board initializing with size: %d\n", size);

    board_size = size;

    snake_board_ptr = (int *)malloc(size * size * sizeof(int));
    if (snake_board_ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                snake_board_ptr[i * size + j] = 1;
            } else {
                snake_board_ptr[i * size + j] = 0;
            }
        }
    }
}

int check_tile(struct pos pos) {
    printf("Checking tile: %d - %d\n", pos._x, pos._y);

    if (pos._x < 0 || pos._x >= board_size || pos._y < 0 || pos._y >= board_size) {
        printf("Invalid tile position: (%d, %d)\n", pos._x, pos._y);
        return -1;
    }

    return snake_board_ptr[pos._x * board_size + pos._y];
}

void set_tile(struct pos pos, int type) {
    printf("Setting tile: %d - %d to type: %d\n", pos._x, pos._y, type);

    if (pos._x <= 0 || pos._x >= board_size - 1 || pos._y <= 0 || pos._y >= board_size - 1) {
        printf("Invalid tile position: (%d, %d)\n", pos._x, pos._y);
        exit(1);
    }

    if (type < 0 || type >= 4) {
        printf("Invalid type. %d\n", type);
        exit(1);
    }

    snake_board_ptr[pos._x * board_size + pos._y] = type;
}

void print_board_state() {
    printf("Printing board state: \n");

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (j == board_size - 1) {
                printf("%d\n", snake_board_ptr[i * board_size + j]);
            } else {
                printf("%d", snake_board_ptr[i * board_size + j]);
            }
        }
    }
}

void free_board() {
    free(snake_board_ptr);
}
