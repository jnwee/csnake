#include <stdio.h>
#include "board.h"
#include "snake.h"

int main() {

    printf("<====== START =======> \n\n");

    initialize_board(15);

    set_tile(5, 5, 2);

    printf("Wall tile on 0, 0:\n-> %d\n", check_tile(0, 0));

    printf("Wall tile on 14, 14:\n-> %d\n", check_tile(14, 14));

    printf("Food tile on 5, 5:\n-> %d\n", check_tile(5, 5));

    print_board_state();

    free_snake();
    free_board();
    return 0;
}
