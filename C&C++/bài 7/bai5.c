#include <stdio.h>
#include <math.h> 

int main() {
    int n, originalNum, tempNum, remainder;
    int digitCount = 0;
    double sum = 0.0; 

    printf("Nhap vao so nguyen n: ");
    scanf("%d", &n);

    originalNum = n;
    tempNum = n;

    if (tempNum == 0) {
        digitCount = 1;
    } else {
        while (tempNum > 0) {
            tempNum /= 10;
            digitCount++;
        }
    }
    
    tempNum = n; 

    while (tempNum > 0) {
        remainder = tempNum % 10;
        sum = sum + pow(remainder, digitCount);
        tempNum /= 10;
    }

    if ((int)sum == originalNum) {
        printf("%d la so Armstrong.\n", originalNum);
    } else {
        printf("%d khong phai la so Armstrong.\n", originalNum);
    }

    return 0;
}
