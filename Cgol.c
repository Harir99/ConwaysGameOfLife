#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
#include "game.h"

int main(int argc, char const *argv[]) {
    FILE *f1;
    char string[100];
    char formattedString[100];
    char fileName[100];
    int row = 20;
    int col = 40;
    int i = 0;
    int j = 0;
    int match = 0;
    int change = 1;
    int alive = 0;
    char gameBoard[ROWS][COLUMN];
    char NewgameBoard[ROWS][COLUMN];
    char *c;
    int Numtick = 0;
    int tickincrement = 0;
    int valid = 0;
    char choice[5];
    int loooped_k = 0;
    system("clear");
    strcpy(fileName,argv[1]);
    if ( (f1 = fopen(argv[1], "r")) != NULL ) {

        while (fgets(string, 100, f1) != NULL) {
            removeSpace(string, formattedString);

            formattedString[strlen(formattedString)] = '\0';

            c = formattedString;

            j = 0;
            if (i < row) {

                while ( *c!= '\0') {

                    if (*c == '0' || *c == '1') {
                        gameBoard[i][j] = *c;
                        j++;
                    }
                    c++;
                }
            }
            i++;

        }

    } else {
             printf ( "Cannot open %s\n",fileName);
             return ( -2 );
    }

    if (argc == 5){
        tickincrement = atoi(argv[2]);
        row = atoi(argv[3]);
        col = atoi(argv[4]);

    } if (argc == 3){
        tickincrement = atoi(argv[2]);
    }
    if (argc == 2){
        tickincrement = 5;
    }


        replaceChar(gameBoard);
        printGameBoard(gameBoard, Numtick, tickincrement);

        printf("Start? (y or n)");
        scanf("%s",choice);
        if (strcmp(choice,"y") == 0){
            valid = 1;
            printf("\t\t%d\n", tickincrement);

            while (valid == 1){

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {

                            NewgameBoard[i][j] = gameBoard[i][j];
                        }
                    }


                

                while (loooped_k < tickincrement)
                {
                    Numtick++;
                    match = 0;
                    printGameBoard(NewgameBoard, Numtick, tickincrement);
                    system("sleep 0.25");
                    system("clear");

                    for (i = 0; i < row; i++) {
                        for (j = 0; j < col; j++) {
                            alive = 0;
                            if(i > 0 && j > 0 && gameBoard[i-1][j-1]== 'x'){
                              alive++;
                            }

                            if(i > 0 && gameBoard[i-1][j]== 'x'){
                              alive++;
                            }

                          if(i > 0 && j < col &&  gameBoard[i-1][j+1]== 'x'){
                              alive++;
                          }
                          if(j < col && gameBoard[i][j+1]== 'x'){
                              alive++;
                          }

                          if(j > 0 && gameBoard[i][j-1]== 'x'){
                              alive++;
                          }

                          if(j > 0 && i < row && gameBoard[i+1][j-1]== 'x'){
                              alive++;
                          }

                          if(i < row && j < col && gameBoard[i+1][j+1]== 'x'){
                              alive++;
                          }

                          if(i < row && gameBoard[i+1][j]== 'x'){
                              alive++;
                          }


                        if(gameBoard[i][j] == 'x'){
                                   if (alive == 2 || alive == 3){
                                       NewgameBoard[i][j] = 'x';
                                   }

                                   else {
                                       NewgameBoard[i][j] = ' ';

                                   }

                           } if (gameBoard[i][j] == ' '){
                                   if ( alive == 3){
                                       NewgameBoard[i][j] = 'x';

                                   }
                               }

                         }
                     }
                     for (i = 0; i < row; i++) {
                         for (j = 0; j < col; j++) {
                                 if (gameBoard[i][j] == NewgameBoard[i][j]){

                                     match++;

                                 }
                             }

                         }

                    if (match == row*col) {
                        change = 0;
                        i = row;
                        j = col;
                        loooped_k = tickincrement;
                        break;
                    }
                     for (i = 0; i < row; i++) {
                         for (j = 0; j < col; j++) {
                                 gameBoard[i][j] = NewgameBoard[i][j];
                             }
                         }
                    loooped_k++;
                }

                loooped_k = 0;

                if (change) {

                    printGameBoard(NewgameBoard, Numtick, tickincrement);
                    printf("Continue? (y or n) ");
                    scanf("%s",choice);
                    if (strcmp(choice,"y") == 0){
                        valid = 1;
                    }
                    else if (strcmp(choice,"n") == 0){
                        valid = 0;
                    }
                }
                else{
                    printGameBoard(NewgameBoard, Numtick, tickincrement);
                    valid = 0;
                }
        }
    }


    return 0;
}
