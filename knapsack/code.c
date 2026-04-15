#include <stdio.h>


struct Item {
    int value;
    int weight;
};


void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}


void sortItems(struct Item items[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            float r1 = (float)items[j].value / items[j].weight;
            float r2 = (float)items[j + 1].value / items[j + 1].weight;

            if (r1 < r2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, int W) {
    sortItems(items, n);

    float totalValue = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += items[i].value * ((float)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, i, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    float maxValue = fractionalKnapsack(items, n, W);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
