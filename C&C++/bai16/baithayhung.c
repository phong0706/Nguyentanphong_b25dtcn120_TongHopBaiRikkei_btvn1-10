#include <stdio.h>
#include <string.h>

void xoaKyTuXuongDong(char str[]) {
    str[strcspn(str, "\n")] = 0;
}

int main() {
    char danhSach[100][50];
    int soLuongSV = 0;
    int choice;

    do {
        printf("\n======= QUAN LY DANH SACH SINH VIEN (C) =======\n");
        printf("--------------------MENU--------------------\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them moi 1 sinh vien\n");
        printf("3. Chinh sua ten sinh vien\n");
        printf("4. Xoa 1 sinh vien\n");
        printf("5. Tim kiem sinh vien theo ten (Chinh xac)\n");
        printf("6. Sap xep danh sach sinh vien theo tu A - Z\n");
        printf("7. Thoat\n");
        printf("--------------------------------------------\n");
        printf("Lua chon cua ban (1-7): ");
        
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            if (soLuongSV == 0) {
                printf("Danh sach rong.\n");
            } else {
                printf("\n--- Danh Sach Sinh Vien (Tong so: %d) ---\n", soLuongSV);
                for (int i = 0; i < soLuongSV; i++) {
                    printf("STT %d: %s\n", i + 1, danhSach[i]);
                }
            }
        } 
        
        else if (choice == 2) {
            if (soLuongSV >= 100) {
                printf("Loi: Danh sach da day.\n");
            } else {
                printf("Nhap ten sinh vien moi: ");
                fgets(danhSach[soLuongSV], 50, stdin);
                xoaKyTuXuongDong(danhSach[soLuongSV]);
                soLuongSV++;
                printf("Da them sinh vien.\n");
            }
        } 
        
        else if (choice == 3) {
            if (soLuongSV == 0) {
                printf("Danh sach rong, khong co gi de sua.\n");
                continue;
            }
            int index;
            printf("Nhap STT sinh vien can sua (1-%d): ", soLuongSV);
            scanf("%d", &index);
            getchar(); 
            index--; 

            if (index < 0 || index >= soLuongSV) {
                printf("STT khong hop le.\n");
            } else {
                printf("Ten hien tai: %s\n", danhSach[index]);
                printf("Nhap ten moi: ");
                fgets(danhSach[index], 50, stdin);
                xoaKyTuXuongDong(danhSach[index]);
                printf("Da cap nhat ten sinh vien.\n");
            }
        } 
        
        else if (choice == 4) {
            if (soLuongSV == 0) {
                printf("Danh sach rong, khong co gi de xoa.\n");
                continue;
            }
            int index;
            printf("Nhap STT sinh vien can xoa (1-%d): ", soLuongSV);
            scanf("%d", &index);
            getchar(); 
            index--; 

            if (index < 0 || index >= soLuongSV) {
                printf("STT khong hop le.\n");
            } else {
                for (int i = index; i < soLuongSV - 1; i++) {
                    strcpy(danhSach[i], danhSach[i + 1]);
                }
                soLuongSV--; 
                printf("Da xoa sinh vien.\n");
            }
        } 
        
        else if (choice == 5) {
             if (soLuongSV == 0) {
                printf("Danh sach rong.\n");
                continue;
            }
            
            char tenTim[50];
            printf("Nhap ten can tim (chinh xac): ");
            fgets(tenTim, 50, stdin);
            xoaKyTuXuongDong(tenTim);

            int found = -1;
            for (int i = 0; i < soLuongSV; i++) {
                if (strcmp(danhSach[i], tenTim) == 0) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                printf("Tim thay: STT %d - %s\n", found + 1, danhSach[found]);
            } else {
                printf("Khong tim thay sinh vien nao co ten '%s'.\n", tenTim);
            }
        } 
        
        else if (choice == 6) {
            if (soLuongSV < 2) {
                printf("Danh sach qua ngan de sap xep.\n");
            } else {
                char temp[50];
                for (int i = 0; i < soLuongSV - 1; i++) {
                    for (int j = 0; j < soLuongSV - i - 1; j++) {
                        if (strcmp(danhSach[j], danhSach[j + 1]) > 0) {
                            strcpy(temp, danhSach[j]);
                            strcpy(danhSach[j], danhSach[j + 1]);
                            strcpy(danhSach[j + 1], temp);
                        }
                    }
                }
                printf("Da sap xep danh sach theo A-Z.\n");
            }
        } 
        
        else if (choice == 7) {
            printf("Tam biet! Hen gap lai.\n");
        } 
        
        else {
            printf("Lua chon khong hop le. Vui long chon lai (1-7).\n");
        }

    } while (choice != 7);

    return 0;
}
