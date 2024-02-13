#include <stdio.h>
#include <limits.h> // for INT_MAX

#define ROWS 10
#define COLS 10
#define INFINITY_VALUE INT_MAX

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void A(int Array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf(" %d", &Array[i][j]);
            if (Array[i][j] == 0 && i != j) { 
                Array[i][j] = INFINITY_VALUE;
            }
        }
    }
                    scanf(" ");
    //make the shourtestPath array
    for (int k = 0; k < ROWS; k++) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (Array[i][k] != INFINITY_VALUE && Array[k][j] != INFINITY_VALUE) {
                    Array[i][j] = (Array[i][j] == INFINITY_VALUE) ? Array[i][k] + Array[k][j] : min(Array[i][j], Array[i][k] + Array[k][j]);
                }
            }
        }
    }
}

//check if there is a path
int B(int row, int col, int Array[ROWS][COLS]) {
    if(row >= 0 && row<10 && col>=0 && col<10){
        return (Array[row][col] != INFINITY_VALUE && Array[row][col] != 0);
    }
    return 0;
}

//print the length of the path
int C(int row, int col, int Array[ROWS][COLS]) {
    if(row >= 0 && row<10 && col>=0 && col<10){
        return (Array[row][col] == INFINITY_VALUE || Array[row][col] == 0) ? -1 : Array[row][col];
    }
    return -1;
}