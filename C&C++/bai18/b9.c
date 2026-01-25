#include <stdio.h>
#define MAX_CAPACITY 100

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void insertElement(int *array, int *size, int value, int index) {
    if (*size >= MAX_CAPACITY) {
        printf("Loi: Mang da day, khong the them.\n");
        return;
    }
    
    if (index < 0 || index > *size) {
        printf("Loi: Vi tri chen khong hop le.\n");
        return;
    }

    for (int i = *size; i > index; i--) {
        *(array + i) = *(array + i - 1);
    }

    *(array + index) = value;

    (*size)++; 
}

int main() {
    int numbers[MAX_CAPACITY] = {10, 20, 30, 40, 50};
    int currentSize = 5;

    int newValue = 99;
    int insertIndex = 2; 

    printf("Mang ban dau: ");
    printArray(numbers, currentSize);

    insertElement(numbers, &currentSize, newValue, insertIndex);

    printf("Mang sau khi chen %d vao vi tri %d: ", newValue, insertIndex);
    printArray(numbers, currentSize);
    
    return 0;
}
