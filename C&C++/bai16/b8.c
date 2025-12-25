#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[200];

    printf("Nhap vao chuoi: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0) {
            str[i] = toupper(str[i]);
        } else if (isspace(str[i - 1])) {
            str[i] = toupper(str[i]);
        }
    }

    printf("Output: %s\n", str);

    return 0;
}
