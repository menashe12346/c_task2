#include <stdio.h>
#include "my_mat.h"
#include <limits.h> // for INT_MAX

#define ROWS 10
#define COLS 10
#define INFINITY_VALUE INT_MAX

int main() {

    int Array[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Array[i][j] = INFINITY_VALUE;
        }
    }
    char c = ' ';
    int i;
    int j;

    while (c != 'D' && c != EOF) {
        scanf("%c", &c); 

        if (c == 'A') {
            A(Array);
        } else if (c == 'B') {
            scanf(" %d %d ", &i, &j);
            printf("%s\n", B(i, j, Array)? "True" : "False");        
            } else if (c == 'C') {
            scanf(" %d %d ", &i, &j);
            printf("%d\n", C(i, j, Array));
        }
    }

    return 0;
}
