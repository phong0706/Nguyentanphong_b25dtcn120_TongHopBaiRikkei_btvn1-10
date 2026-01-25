#include <stdio.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void deleteElement(int *array, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Loi: Vi tri xoa khong hop le.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        *(array + i) = *(array + i + 1);
    }

    (*size)--;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int currentSize = 5;

    int indexToDelete = 2;

    printf("Mang ban dau: ");
    printArray(numbers, currentSize);

    deleteElement(numbers, &currentSize, indexToDelete);

    printf("Mang sau khi xoa phan tu tai vi tri %d: ", indexToDelete);
    printArray(numbers, currentSize);
    
    printf("PHONG SIEU NHAN GAOOOOO");

    return 0;
}
