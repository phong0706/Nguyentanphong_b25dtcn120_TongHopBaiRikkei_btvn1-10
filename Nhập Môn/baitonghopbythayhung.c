#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int lua_chon;
    int i;
    int vi_tri, gia_tri;
    char xac_nhan;

    do {
        printf("+---Chuong trinh quan ly danh sach so nguyen---+\n");
        printf("|--------------------MENU----------------------|\n");
        printf("|1. Khoi tao mang ban dau\n");
        printf("|2. Hien thi danh sach phan tu\n");
        printf("|3. Chen them 1 so vao vi tri nhap vao\n");
        printf("|4. Xoa theo vi tri\n");
        printf("|5. Cap nhat gia tri theo vi tri\n");
        printf("|6. Thoat chuong trinh\n");
        printf("+----------------------------------------------+\n");
        printf("->> Moi ban nhap chuc nang : ");
        
        scanf("%d", &lua_chon);

        if (lua_chon == 1) {
            printf("---------------------#1#------------------------\n");
            printf("Nhap so luong phan tu can khoi tao : ");
            scanf("%d", &n);

            if (n > MAX_SIZE || n < 0) {
                printf("So luong khong hop le (phai < %d va > 0).\n", MAX_SIZE);
                n = 0;
            } else {
                for (i = 0; i < n; i++) {
                    printf("----------------Phan tu %d-----------------------\n", i + 1);
                    printf("Nhap gia tri phan tu : ");
                    scanf("%d", &arr[i]);
                }
                printf("\n<<--- Nhap thanh cong %d phan tu vao mang --->>\n", n);
            }
            
        } else if (lua_chon == 2) {
            printf("---------------------#2#------------------------\n");
            printf("\n-------DANH SACH CAC PHAN TU TRONG MANG---------\n");
            if (n == 0) {
                printf("[]\n");
            } else {
                printf("[");
                for (i = 0; i < n; i++) {
                    printf("%d", arr[i]);
                    if (i < n - 1) {
                        printf(" ");
                    }
                }
                printf("]\n");
            }
            
        } else if (lua_chon == 3) {
            printf("---------------------#3#------------------------\n");
            if (n == MAX_SIZE) {
                printf("Mang da day, khong the them.\n");
            } else {
                printf("Nhap vi tri can them phan tu : ");
                scanf("%d", &vi_tri);
                printf("Nhap gia tri can them tai vi tri %d : ", vi_tri);
                scanf("%d", &gia_tri);

                if (vi_tri < 0 || vi_tri > n) {
                    printf("Vi tri chen khong hop le.\n");
                } else {
                    for (i = n; i > vi_tri; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[vi_tri] = gia_tri;
                    n++;
                    printf("\n<<--Them thanh cong so %d vao vi tri index %d-->>\n", gia_tri, vi_tri);
                }
            }
            
        } else if (lua_chon == 4) {
            printf("---------------------#4#------------------------\n");
            if (n == 0) {
                printf("Mang rong, khong co gi de xoa.\n");
            } else {
                printf("Nhap vao vi tri can xoa phan tu : ");
                scanf("%d", &vi_tri);

                if (vi_tri < 0 || vi_tri >= n) {
                    printf("Vi tri xoa khong hop le.\n");
                } else {
                    printf("Ban co chac chan muon xoa phan tu nay khong(Y/N)?\n");
                    scanf(" %c", &xac_nhan);

                    if (xac_nhan == 'Y' || xac_nhan == 'y') {
                        for (i = vi_tri; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        printf("\n<<--Da xoa thanh cong phan tu tai vi tri %d!!-->>\n", vi_tri);
                    } else {
                        printf("Huy xoa.\n");
                    }
                }
            }
            
        } else if (lua_chon == 5) {
            printf("---------------------#5#------------------------\n");
            printf("Nhap vao vi tri phan tu can cap nhat : ");
            scanf("%d", &vi_tri);

            if (vi_tri < 0 || vi_tri >= n) {
                printf("Vi tri cap nhat khong hop le.\n");
            } else {
                printf("Nhap vao gia tri moi (gia tri cu(%d)): ", arr[vi_tri]);
                scanf("%d", &gia_tri);
                arr[vi_tri] = gia_tri;
                printf("\n<<Da cap nhat thanh cong phan tu tai vi tri %d>>\n", vi_tri);
            }
            
        } else if (lua_chon == 6) {
            printf("Tam biet!\n");
        } else {
            printf("Lua chon khong hop le. Vui long chon tu 1 den 6.\n");
        }
        
        if (lua_chon != 6) {
            printf("---------------------###------------------------\n\n");
        }

    } while (lua_chon != 6);

    return 0;
};
