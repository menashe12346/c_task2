#include <stdio.h>

#define ROWS 10
#define COLS 10

int min(int a, int b){
if(a<b){
    return a;
}
return b;
}

void A(int Array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter weight for edge (%d, %d): ", i, j);
            scanf("%d", &Array[i][j]);
        }
    }

    for (int k = 0; k < ROWS; k++) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < ROWS; j++) {
                Array[i][j] = min(Array[i][j], Array[i][k] + Array[k][j]);
            }
        }
    }
}

int B(int row, int col, int Array[ROWS][COLS]){
    if(Array[row][col]!=0){
        return 1;
    }
    return 0;
}

int C(int row, int col, int Array[ROWS][COLS]){
    return Array[row][col]==0? -1 : Array[row][col];
}

