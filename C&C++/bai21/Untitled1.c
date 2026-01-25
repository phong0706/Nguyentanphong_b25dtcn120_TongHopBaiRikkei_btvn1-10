#include <stdio.h>
#include <string.h>

struct Car {
    char model[50];
    int year;
    float price;
};

int main() {
    struct Car myCar = {"Toyota Camry", 2024, 35000.5};

    printf("Thong tin xe myCar:\n");
    printf("Mau xe: %s\n", myCar.model);
    printf("Nam san xuat: %d\n", myCar.year);
    printf("Gia tien: %.2f\n", myCar.price);

    return 0;
};
