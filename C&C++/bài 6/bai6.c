#include <stdio.h>

int main() {
    double num1, num2;
    int choice;

    printf("Nhap so thu nhat: ");
    scanf("%lf", &num1);
    printf("Nhap so thu hai: ");
    scanf("%lf", &num2);

    do {
        printf("\n--- MENU CHUC NANG ---\n");
        printf("1. Tong 2 so\n");
        printf("2. Hieu 2 so\n");
        printf("3. Tich 2 so\n");
	        printf("4. Thuong 2 so\n");
	        printf("5. Thoat\n");
	        printf("------------------------\n");
	        printf("Lua chon cua ban: ");
	        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Tong: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("Hieu: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("Tich: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Loi: Khong the chia cho 0!\n");
                } else {
                    printf("Thuong: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                }
                break;
            case 5:
                printf("BAI BAII! Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon tu 1 den 5.\n");
        }
    } while (choice != 5);

    return 0;
}
