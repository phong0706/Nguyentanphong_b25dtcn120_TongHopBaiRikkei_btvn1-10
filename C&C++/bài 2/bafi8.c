#include <stdio.h>

int main(main) {
    int number = 12345;
    int result = 0;

    printf("So chua doi: %d\n", number);

    while (number > 0) {
        int lastDigit = number % 10;
        result = result * 10 + lastDigit;
        number = number / 10;
    }

    printf("So da doi: %d\n", result);
   
    system("color 0E");

    return 0;
}
