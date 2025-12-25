#include <stdio.h>

struct SanPham {
    int ma_san_pham;
    int gia_ban;     
};

int binarySearch(struct SanPham arr[], int n, int ma_can_tim) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid].ma_san_pham == ma_can_tim) {
            return mid; 
        }

        if (arr[mid].ma_san_pham < ma_can_tim) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}

void bubbleSort(struct SanPham arr[], int n) {
    int i, j;
    struct SanPham temp; 
    int check;

    for (i = 0; i < n - 1; i++) {
        check = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].gia_ban > arr[j + 1].gia_ban) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                check = 1;
            }
        }
        if (check == 0) {
            break;
        }
    }
}

void inDanhSach(struct SanPham arr[], int n) {
    int i;
    printf("--- DANH SACH SAN PHAM ---\n");
    printf("Ma SP\tGia Ban\n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", arr[i].ma_san_pham, arr[i].gia_ban);
    }
    printf("---------------------------\n");
}

int main() {
    int n = 5;
    int i;
    
    struct SanPham danh_sach[5] = {
        {101, 500},
        {102, 200},
        {103, 800},
        {104, 150},
        {105, 300}
    };

    printf("Danh sach san pham ban dau (da sap xep theo Ma SP):\n");
    inDanhSach(danh_sach, n);

    int ma_tim = 104;
    printf("\nDang tim kiem san pham co ma: %d\n", ma_tim);
    int ket_qua_tim = binarySearch(danh_sach, n, ma_tim);
    
    if (ket_qua_tim != -1) {
        printf(">> Tim thay! San pham co gia: %d\n", danh_sach[ket_qua_tim].gia_ban);
    } else {
        printf(">> Khong tim thay san pham co ma %d\n", ma_tim);
    }

    printf("\n...Dang sap xep danh sach theo Gia ban...\n");
    bubbleSort(danh_sach, n);
    
    printf("Danh sach sau khi sap xep theo Gia ban (tang dan):\n");
    inDanhSach(danh_sach, n);

    getchar();
    
    return 0;
}
