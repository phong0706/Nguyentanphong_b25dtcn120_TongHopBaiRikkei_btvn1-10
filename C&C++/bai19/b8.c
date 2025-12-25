#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kiemTraNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void hoanDoi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nhapMang(int *arr, int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", arr + i);
    }
}

void inSoChan(int *arr, int n) {
    printf("Cac so chan trong mang: ");
    int coSoChan = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
            coSoChan = 1;
        }
    }
    if (coSoChan == 0) printf("Khong co");
    printf("\n");
}

void inSoNguyenTo(int *arr, int n) {
    printf("Cac so nguyen to trong mang: ");
    int coSNT = 0;
    for (int i = 0; i < n; i++) {
        if (kiemTraNguyenTo(*(arr + i))) {
            printf("%d ", *(arr + i));
            coSNT = 1;
        }
    }
    if (coSNT == 0) printf("Khong co");
    printf("\n");
}

void daoNguocMang(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        hoanDoi(start, end);
        start++;
        end--;
    }
    printf("Da dao nguoc mang xong.\n");
}

void sapXepTang(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                hoanDoi(arr + i, arr + j);
            }
        }
    }
    printf("Da sap xep tang dan.\n");
}

void sapXepGiam(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) < *(arr + j)) {
                hoanDoi(arr + i, arr + j);
            }
        }
    }
    printf("Da sap xep giam dan.\n");
}

void timKiem(int *arr, int n) {
    int x, found = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    printf("Tim thay tai vi tri: ");
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == x) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (found == 0) printf("Khong tim thay");
    printf("\n");
}

void hienThiMang(int *arr, int n) {
    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int *arr = (int *)malloc(100 * sizeof(int));
    int n = 0;
    int choice, subChoice;

    do {
        printf("\n--------------- MENU ----------------------\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang (Tang/Giam)\n");
        printf("6. Nhap vao mot phan tu va tim kiem\n");
        printf("7. Thoat\n");
        printf("\n--------------------------------------------\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inSoChan(arr, n);
                break;
            case 3:
                inSoNguyenTo(arr, n);
                break;
            case 4:
                daoNguocMang(arr, n);
                hienThiMang(arr, n);
                break;
            case 5:
                printf("\n--------------- MENU CON (SAP XEP) ----------------\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon sap xep: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sapXepTang(arr, n);
                } else if (subChoice == 2) {
                    sapXepGiam(arr, n);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                if (subChoice == 1 || subChoice == 2) hienThiMang(arr, n);
                break;
            case 6:
                timKiem(arr, n);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    free(arr);
    return 0;
};
