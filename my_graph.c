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
    char c;
    int i;
    int j;

    scanf("%c", &c); 

    while (c != 'D' && c != EOF) {

        if (c == 'A') {
            A(Array);
        } else if (c == 'B') {
            scanf("%d", &i);
            scanf("%d", &j);            
            printf("%s\n", B(i, j, Array)? "True" : "False");        
            } else if (c == 'C') {
            scanf("%d", &i);
            scanf("%d", &j);  
            printf("%d\n", C(i, j, Array));
        }

        scanf("%c", &c); 
    }

    return 0;
}
