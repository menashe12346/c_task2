#include <stdio.h>

#define weight 20
#define size 5

int knapSack(int weights[], int values[], int selected_bool[]) {
    // Create a 2D array to store the maximum profit for each capacity
    int dp[size + 1][weight + 1];

    // Initialize the DP table
    for (int i = 0; i <= size; i++) {
        for (int w = 0; w <= weight; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ? 
                           (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Trace back to find the selected items
    int w = weight;
    for (int i = size; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_bool[i - 1] = 1; // Item is included
            w -= weights[i - 1];
        }
    }

    // Return the maximum value
    return dp[size][weight];
}

int main() {
    int values[size];
    int weights[size];

    for (int i = 0; i < 5; i++) {
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    int selected_bool[size];

    // Call the knapSack function
    int max_value = knapSack(weights, values, selected_bool);
    printf("Maximum profit: %d\n", max_value);

    char items[] = {'a', 'b', 'c', 'd', 'e'};

    // Print the selected items
    printf("Selected items:");
    for (int i = size-1; i >=0; i--) {
        if (selected_bool[i]) {
            printf(" %c", items[i]);
        }
    }
    printf("\n");

    return 0;
}
