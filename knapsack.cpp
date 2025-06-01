#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int weights[], int values[], int n, int W) {
    int dp[MAX][MAX];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Print maximum value
    printf("\nMaximum value that can be carried: %d\n", dp[n][W]);

    // Trace the items included
    printf("Items included (1-based index): ");
    int w = W;
    for (int i = n; i > 0 && dp[i][w] > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= weights[i - 1];
        }
    }
    printf("\n");
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[MAX], values[MAX];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    knapsack(weights, values, n, W);

    return 0;
}

