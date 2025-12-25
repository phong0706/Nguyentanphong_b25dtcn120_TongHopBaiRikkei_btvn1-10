#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];
    int length;

    printf("Moi ban nhap vao mot chuoi: ");
    fgets(inputString, sizeof(inputString), stdin);

    inputString[strcspn(inputString, "\n")] = '\0';

    length = strlen(inputString);

    printf("Chuoi ban vua nhap la: %s\n", inputString);
    printf("Do dai cua chuoi la: %d\n", length);

    return 0;
}
