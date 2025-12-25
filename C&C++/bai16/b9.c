#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char charToDelete;
    int j = 0;

    printf("Nhap vao chuoi: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    printf("Nhap ky tu can xoa: ");
    scanf(" %c", &charToDelete);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != charToDelete) {
            str[j] = str[i];
            j++;
        }
    }
    
    str[j] = '\0';

    printf("Chuoi sau khi xoa: %s\n", str);

    return 0;
}
