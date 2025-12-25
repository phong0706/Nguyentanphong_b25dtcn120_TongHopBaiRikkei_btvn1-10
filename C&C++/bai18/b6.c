#include <stdio.h>

int findElement(int *array, int size, int valueToFind) {
    for (int i = 0; i < size; i++) {
        if (*(array + i) == valueToFind) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {1, 2, 4, 5, 6, 7};
    int valueToFind = 7;
    
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Mang dau vao: [1, 2, 4, 5, 6, 7]\n");
    printf("Gia tri can tim: %d\n", valueToFind);

    int index = findElement(numbers, size, valueToFind);

    if (index != -1) {
        printf("Output: %d\n", index);
    } else {
        printf("Khong tim thay %d trong mang.\n", valueToFind);
    }

    return 0;
}
