#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello my gmail is test123@gmail.com";
    
    int countChuCai = 0;
    int countChuSo = 0;
    int countDacBiet = 0;

    printf("Chuoi goc: \"%s\"\n", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            countChuCai++;
        } else if (isdigit(str[i])) {
            countChuSo++;
        } else {
            countDacBiet++;
        }
    }

    printf("So ky tu la chu cai: %d\n", countChuCai);
    printf("So ky tu la chu so: %d\n", countChuSo);
    printf("So ky tu la ky tu dac biet: %d\n", countDacBiet);

    return 0;
}
