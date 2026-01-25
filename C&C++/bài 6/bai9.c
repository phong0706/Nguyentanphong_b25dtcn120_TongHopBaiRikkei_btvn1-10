#include <stdio.h>

int main() {
    int n1, n2, n3;
    int choice;
    int daNhapSo = 0; 
    
    int tong;
    double trungBinh;
    int min, max;

    do {
        printf("\n--- MENU CHUC NANG ---\n");
        printf("1. Nhap 3 so\n");
        printf("2. Tong 3 so\n");
        printf("3. Trung binh cong 3 so\n");
        printf("4. So nho nhat\n");
        printf("5. So lon nhat\n");
        printf("6. Thoat\n");
        printf("------------------------\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so thu nhat: ");
                scanf("%d", &n1);
                printf("Nhap so thu hai: ");
                scanf("%d", &n2);
                printf("Nhap so thu ba: ");
                scanf("%d", &n3);
                printf("Da nhap 3 so: %d, %d, %d\n", n1, n2, n3);
                daNhapSo = 1;
                break;
            case 2:
                if (daNhapSo == 0) {
                    printf("Loi: Vui long nhap 3 so truoc!\n");
                } else {
                    tong = n1 + n2 + n3;
                    printf("Tong 3 so: %d + %d + %d = %d\n", n1, n2, n3, tong);
                }
                break;
            case 3:
                if (daNhapSo == 0) {
                    printf("Loi: Vui long nhap 3 so truoc!\n");
                } else {
                    tong = n1 + n2 + n3;
                    trungBinh = (double)tong / 3.0;
                    printf("Trung binh cong: (%.2f / 3) = %.2f\n", (double)tong, trungBinh);
                }
                break;
            case 4:
                if (daNhapSo == 0) {
                    printf("Loi: Vui long nhap 3 so truoc!\n");
                } else {
                    min = n1;
                    if (n2 < min) {
                        min = n2;
                    }
                    if (n3 < min) {
                        min = n3;
                    }
                    printf("So nho nhat trong (%d, %d, %d) la: %d\n", n1, n2, n3, min);
                }
                break;
            case 5:
                if (daNhapSo == 0) {
                    printf("Loi: Vui long nhap 3 so truoc!\n");
                } else {
                    max = n1;
                    if (n2 > max) {
                        max = n2;
                    }
                    if (n3 > max) {
                        max = n3;
                    }
                    printf("So lon nhat trong (%d, %d, %d) la: %d\n", n1, n2, n3, max);
                }
                break;
            case 6:
                printf("Tam biet! Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon tu 1 den 6.\n");
        }
    } while (choice != 6);

    return 0;
}
