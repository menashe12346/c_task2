#include <stdio.h>
#include "my_mat.h"

#define ROWS 10
#define COLS 10

int main() {

    int Array[ROWS][COLS];
    char c = ' ';
    int i;
    int j;

    while (c != 'D' && c != EOF) {
        scanf(" %c", &c); 

        if (c == 'A') {
            A(Array);
        } else if (c == 'B') {
            scanf("%d", &i);
            scanf("%d", &j);
            printf("%s\n", B(i, j, Array) == 1 ? "TRUE" : "FALSE");        
            } else if (c == 'C') {
            scanf("%d", &i);
            scanf("%d", &j);
            printf("%d\n", C(i, j, Array));
        }
    }

    return 0;
}
