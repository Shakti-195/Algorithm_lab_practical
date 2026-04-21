#include <stdio.h>

struct Item {
    float weight, profit, ratio;
};

int main() {
    int n, i, j;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &items[i].weight, &items[i].profit);
        items[i].ratio = items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sorting items based on profit/weight ratio (descending)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Greedy selection
    for(i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}
