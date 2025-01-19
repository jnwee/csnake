#include <stdbool.h>
#include <stdio.h>
#include "board.h"
#include "snake.h"

#define BOARD_SIZE 15

bool running = false;

void *game_loop() {
    struct pos start_pos;
    start_pos._x = BOARD_SIZE / 2;
    start_pos._y = BOARD_SIZE / 2;
    initialize_snake(start_pos);
    set_tile(start_pos, 3);

    while(running) {
        struct pos new_pos = advance();
        switch (check_tile(new_pos)) {
            case 0:
                set_tile(new_pos, 3);
                break;
            case 1:
                printf("Snake died to wall. \n");
                running = false;
                break;
            case 2:
                printf("Snake ate. \n");
                eat();
                break;
            case 3:
                printf("Snake died to itself. \n");
                running = false;
                break;
        }
    }
}

int main() {

    printf("<====== START =======> \n\n");

    initialize_board(15);

    print_board_state();

    free_snake();
    free_board();
    return 0;
}
