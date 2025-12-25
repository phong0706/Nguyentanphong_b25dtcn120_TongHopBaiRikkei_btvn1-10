#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];
    char reverseString[100];

    printf("Nhap mot chuoi: ");
    fgets(inputString, sizeof(inputString), stdin);

    inputString[strcspn(inputString, "\n")] = '\0';

    int length = strlen(inputString);
    
    char *ptrStart = inputString;
    char *ptrEnd = inputString + length - 1;
    char *ptrReverse = reverseString;
    int i = 0;

    while (i < length) {
        *(ptrReverse + i) = *(ptrEnd - i);
        i++;
    }
    
    *(ptrReverse + length) = '\0';

    printf("Chuoi goc: %s\n", inputString);
    printf("Chuoi dao nguoc: %s\n", reverseString);

    return 0;
}
