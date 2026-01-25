#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    int count = 0;
    int in_word = 0; 

    printf("Nhap vao mot chuoi: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            in_word = 0;
        } else {
            if (in_word == 0) {
                in_word = 1;
                count++;
            }
        }
    }

    printf("So tu trong chuoi: %d\n", count);

    return 0;
}
