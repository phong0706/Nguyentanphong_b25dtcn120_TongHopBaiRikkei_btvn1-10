#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", arr + i);
    }
}

void hienThiMang(int *arr, int n) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void hienThiDoDai(int n) {
    printf("Do dai cua mang la: %d\n", n);
}

void tinhTong(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    printf("Tong cac phan tu: %d\n", sum);
}

void hienThiMax(int *arr, int n) {
    if (n <= 0) return;
    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    printf("Phan tu lon nhat: %d\n", max);
}

int main() {
    int *arr = (int *)malloc(100 * sizeof(int));
    int n = 0;
    int choice;

    do {
        printf("\n--------------------MENU------------------------\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("\n-------------------------------------------------\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                hienThiDoDai(n);
                break;
            case 4:
                tinhTong(arr, n);
                break;
            case 5:
                hienThiMax(arr, n);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);

    free(arr);
    return 0;
}
