#include <stdio.h>
#include<string.h>
#include "game.h"

void removeSpace(char string[100], char stringNew[100]) {

    int i, j;

    for (i = 0, j=0; i < strlen(string); i++, j++) {
        if(string[i]  == ' ') {
            i++;
        }
        stringNew[j] = string[i];

    }
}
