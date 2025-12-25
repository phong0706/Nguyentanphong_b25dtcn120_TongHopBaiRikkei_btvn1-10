#include <stdio.h>

int i; 
int factorial(int number) {
    int resultat = 1;
    for(i = 1; i <= nombre; i++) {
        resultat *= i;
    }
    return resultat;
}

int main() {
    int nombre;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &number);
    if(nombre < 0) {
        printf("Khong tinh giai thua so am duoc\n");
    } else {
        printf("Giai thua cua %d la: %d\n", nombre, factorial(number));
    }

    return 0;
}
