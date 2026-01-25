#include <stdio.h>
#include <string.h>

int main() {
    char originalString[] = "HocLapTrinhC";
    int length;

    length = strlen(originalString);

    printf("Chuoi ban dau: %s\n", originalString);
    printf("Chuoi dao nguoc: ");

    for (int i = length - 1; i >= 0; i--) {
        printf("%c", originalString[i]);
    }

    printf("\n");

    return 0;
}
