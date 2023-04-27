#include <stdio.h>
#include <stdlib.h>

struct item {
    int weight;
    int value;
};

int compare(const void *a, const void *b) {
    struct item *itemA = (struct item *)a;
    struct item *itemB = (struct item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    if (ratioA < ratioB) {
        return 1;
    } else if (ratioA > ratioB) {
        return -1;
    } else {
        return 0;
    }
}

double fractional_knapsack(int capacity, struct item items[], int num_items) {
    double max_value = 0.0;
    int i;
    qsort(items, num_items, sizeof(struct item), compare);
    for (i = 0; i < num_items; i++) {
        if (capacity == 0) {
            return max_value;
        }
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            max_value += items[i].value;
        } else {
            max_value += ((double)capacity / items[i].weight) * items[i].value;
            capacity = 0;
        }
    }
    return max_value;
}

int main() {
    int capacity, num_items, i;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    struct item items[num_items];
    for (i = 0; i < num_items; i++) {
        printf("Enter the weight and value of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    double max_value = fractional_knapsack(capacity, items, num_items);
    printf("Maximum value in knapsack = %f\n", max_value);
    return 0;
}
