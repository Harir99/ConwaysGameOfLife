#include <stdio.h>
#include "game.h"

void replaceChar(char gameBoard[ROWS][COLUMN]){
    int row = 20;
    int col = 40;
    int j = 0;
    int i =0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (gameBoard[i][j] == '0') {
                gameBoard[i][j] = ' ';
            } else {
                gameBoard[i][j] = 'x';
            }
        }
    }
}
