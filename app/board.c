#include <stdio.h>
#include <stdlib.h>
#include "board.h"

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

int check_tile(int x, int y) {
    printf("Checking tile: %d - %d\n", x, y);

    if (x < 0 || x >= board_size || y < 0 || y >= board_size) {
        printf("Invalid tile position: (%d, %d)\n", x, y);
        return -1;
    }

    return snake_board_ptr[x * board_size + y];
}

void set_tile(int x, int y, int type) {
    printf("Setting tile: %d - %d to type: %d\n", x, y, type);

    if (x <= 0 || x >= board_size - 1 || y <= 0 || y >= board_size - 1) {
        printf("Invalid tile position: (%d, %d)\n", x, y);
        exit(1);
    }

    if (type < 0 || type >= 4) {
        printf("Invalid type. %d\n", type);
        exit(1);
    }

    snake_board_ptr[x * board_size + y] = type;
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
