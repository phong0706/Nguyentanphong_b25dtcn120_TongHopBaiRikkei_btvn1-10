#include <stdio.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void updateElement(int *array, int value, int index) {
    array[index] = value;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int newValue = 99;
    int indexToUpdate = 2;

    printf("Mang Goc: ");
    printArray(numbers, size);

    updateElement(numbers, newValue, indexToUpdate);

    printf("Mang da cap nhat: ");
    printArray(numbers, size);

    return 0;
}
