#include <stdio.h>
#include <string.h>

struct Dish {
    int id;
    char name[50];
    int price;
};

int main() {
    struct Dish menu[100] = {
        {1, "Com Rang", 30000},
        {2, "Pho Bo", 45000},
        {3, "Bun Cha", 40000},
        {4, "Banh My", 20000},
        {5, "Lam Tung Kuong", 5000}
    };

    int n = 5;
    int choice, subChoice;
    int position, searchId;
    char searchName[50];
    int found = 0;
    int left, right, mid;

    do {
        printf("\n=== MENU QUAN LY MON AN ===\n");
        printf("1. In danh sach mon an\n");
        printf("2. Them mon an vao vi tri\n");
        printf("3. Sua mon an o vi tri\n");
        printf("4. Xoa mon an o vi tri\n");
        printf("5. Sap xep mon an\n");
        printf("6. Tim kiem mon an\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDANH SACH MON AN:\n");
                printf("+-----+----------------------+----------+\n");
                printf("| %-3s | %-20s | %-8s |\n", "ID", "Ten Mon", "Gia");
                printf("+-----+----------------------+----------+\n");
                for (int i = 0; i < n; i++) {
                    printf("| %-3d | %-20s | %-8d |\n", menu[i].id, menu[i].name, menu[i].price);
                }
                printf("+-----+----------------------+----------+\n");
                break;

            case 2:
                printf("Nhap vi tri muon them (0 - %d): ", n);
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = n; i > position; i--) {
                        menu[i] = menu[i - 1];
                    }
                    printf("Nhap ID: "); scanf("%d", &menu[position].id);
                    getchar();
                    printf("Nhap Ten: "); fgets(menu[position].name, sizeof(menu[position].name), stdin);
                    menu[position].name[strcspn(menu[position].name, "\n")] = 0;
                    printf("Nhap Gia: "); scanf("%d", &menu[position].price);
                    n++;
                    printf("Them thanh cong!\n");
                }
                break;

            case 3:
                printf("Nhap vi tri muon sua (0 - %d): ", n - 1);
                scanf("%d", &position);
                if (position < 0 || position >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    printf("Sua mon: %s\n", menu[position].name);
                    printf("Nhap ID moi: "); scanf("%d", &menu[position].id);
                    getchar();
                    printf("Nhap Ten moi: "); fgets(menu[position].name, sizeof(menu[position].name), stdin);
                    menu[position].name[strcspn(menu[position].name, "\n")] = 0;
                    printf("Nhap Gia moi: "); scanf("%d", &menu[position].price);
                    printf("Sua thanh cong!\n");
                }
                break;

            case 4:
                printf("Nhap vi tri muon xoa (0 - %d): ", n - 1);
                scanf("%d", &position);
                if (position < 0 || position >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = position; i < n - 1; i++) {
                        menu[i] = menu[i + 1];
                    }
                    n--;
                    printf("Xoa thanh cong!\n");
                }
                break;

            case 5:
                printf("  a. Giam dan theo price (Nhap 1)\n");
                printf("  b. Tang dan theo price (Nhap 2)\n");
                printf("  Lua chon: ");
                scanf("%d", &subChoice);

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        int condition = (subChoice == 1) ? (menu[j].price < menu[j + 1].price) : (menu[j].price > menu[j + 1].price);
                        if (condition) {
                            struct Dish temp = menu[j];
                            menu[j] = menu[j + 1];
                            menu[j + 1] = temp;
                        }
                    }
                }
                printf("Da sap xep xong!\n");
                break;

            case 6:
                printf("  a. Tim kiem tuyen tinh (Nhap 1)\n");
                printf("  b. Tim kiem nhi phan (Nhap 2)\n");
                printf("  Lua chon: ");
                scanf("%d", &subChoice);

                getchar();
                printf("Nhap ten mon can tim: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = 0;
                found = 0;

                if (subChoice == 1) {
                    for (int i = 0; i < n; i++) {
                        if (strcmp(menu[i].name, searchName) == 0) {
                            printf("Tim thay tai vi tri %d: ID %d - %s - %d\n", i, menu[i].id, menu[i].name, menu[i].price);
                            found = 1;
                        }
                    }
                } else {
                    left = 0; right = n - 1;
                    while (left <= right) {
                        mid = (left + right) / 2;
                        int res = strcmp(menu[mid].name, searchName);
                        if (res == 0) {
                            printf("Tim thay tai vi tri %d: ID %d - %s - %d\n", mid, menu[mid].id, menu[mid].name, menu[mid].price);
                            found = 1;
                            break;
                        }
                        if (res < 0) left = mid + 1;
                        else right = mid - 1;
                    }
                }

                if (!found) printf("Khong tim thay mon nao ten la %s\n", searchName);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);

    return 0;
};
