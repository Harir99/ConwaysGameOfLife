#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "game.h"


void printGameBoard(char gameBoard[ROWS][COLUMN], int Numtick, int Increment ) {
    int row = 20;
    int col = 40;
    int b1 = 0;
    int b2 = 0;
    int j = 0;
    int i = 0;
    for(b1=0; b1<42; b1++)
    {
        if ( b1 == 0 || b1 == 41){
            printf(" ");
        }
        else{
           printf("-");
        }
    }
    printf("\n");

    printf("|");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {

            printf("%c", gameBoard[i][j]);

        }


        if(i<row)
        {
            printf("|");
        }
        printf("\n");
        if(i<19)
        {
            printf("|");
        }

    }

    for(b2=0; b2<42; b2++)
    {
        if ( b2 == 0){
            printf(" ");
        }

        else if(b2 == 41){
            
            printf("%d", Numtick);
        }
        else {
           printf("-");
        }
    }
    printf("\n");

}
