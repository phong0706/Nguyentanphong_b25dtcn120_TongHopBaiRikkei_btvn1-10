#include <stdio.h>
#include <string.h>

int main() {
    char myString[] = "DayLaMotChuoi";
    int length;

    length = strlen(myString);

    printf("Chuoi da khai bao: %s\n", myString);
    printf("Cac ky tu trong chuoi:\n");

    for (int i = 0; i < length; i++) {
        printf("%c ", myString[i]);
    }

    printf("\n");

    return 0;
}
