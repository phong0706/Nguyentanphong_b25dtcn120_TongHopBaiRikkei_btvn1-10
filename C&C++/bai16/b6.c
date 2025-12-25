#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello RKEI Edu! Day la bai tap so 6.";
    int count = 0;

    printf("Chuoi goc: \"%s\"\n", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }

    printf("So ky tu la chu cai trong chuoi: %d\n", count);

    return 0;
}
