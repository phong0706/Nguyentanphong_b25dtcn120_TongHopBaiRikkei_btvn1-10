#include <stdio.h>

int inputArray(int arr[], int n) {
    int i;
    printf("Nhap so phan tu can nhap: ");
    scanf("%d", &n);
    if (n > 100) {
        printf("So phan tu vuot qua 100, tu dong giam xuong 100\n");
        n = 100;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

int printArray(int arr[], int n) {
    int i;
    printf("Cac phan tu hien co: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int addElement(int arr[], int n) {
    int pos, val, i;
    if (n >= 100) {
        printf("Mang da day\n");
        return n;
    }
    printf("Nhap vi tri can them (0-%d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("Vi tri khong hop le\n");
        return n;
    }
    printf("Nhap gia tri can them: ");
    scanf("%d", &val);
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    return n;
}

int editElement(int arr[], int n) {
    int pos, val;
    printf("Nhap vi tri can sua (0-%d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le\n");
        return n;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &val);
    arr[pos] = val;
    return n;
}

int deleteElement(int arr[], int n) {
    int pos, i;
    printf("Nhap vi tri can xoa (0-%d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le\n");
        return n;
    }
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    return n;
}

int sortAsc(int arr[], int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    return n;
}

int sortDesc(int arr[], int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    return n;
}

int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int n = 0;
    int choice;
    int x, kq;
    char ch;

    do {
        printf("\n------------MENU------------\n");
        printf("1. Nhap mang\n");
        printf("2. In mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Sap xep\n");
        printf("7. Tim kiem\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = inputArray(arr, n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                n = addElement(arr, n);
                break;
            case 4:
                n = editElement(arr, n);
                break;
            case 5:
                n = deleteElement(arr, n);
                break;
            case 6:
                printf("a. Giam dan\nb. Tang dan\nChon: ");
                scanf(" %c", &ch);
                if (ch == 'a') {
                    sortDesc(arr, n);
                } else if (ch == 'b') {
                    sortAsc(arr, n);
                } else {
                    printf("Lua chon khong hop le\n");
                }
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                printf("a. Tuyen tinh\nb. Nhi phan\nChon: ");
                scanf(" %c", &ch);
                if (ch == 'a') {
                    kq = linearSearch(arr, n, x);
                } else if (ch == 'b') {
                    sortAsc(arr, n);
                    kq = binarySearch(arr, n, x);
                } else {
                    printf("Lua chon khong hop le\n");
                    break;
                }
                if (kq != -1) {
                    printf("Tim thay %d o vi tri %d\n", x, kq);
                } else {
                    printf("Khong tim thay %d\n", x);
                }
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (choice != 8);

    return 0;
}


