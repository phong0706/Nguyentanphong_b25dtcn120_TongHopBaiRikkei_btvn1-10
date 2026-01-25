#include <stdio.h>
#include <string.h>

struct Book {
    char id[20];
    char name[50];
    char author[50];
    float price;
    char category[50];
};

int main() {
    struct Book books[100];
    int n = 0;
    int choice;
    int i, j, found, k;
    char searchId[20];
    char searchName[50];
    struct Book temp;
    int sortChoice;

    do {
        printf("\n========== MENU QUAN LY SACH =============\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("\n===========================================\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Nhap so luong sach: ");
                int num;
                scanf("%d", &num);
                for(i = 0; i < num; i++) {
                    printf("\nNhap sach thu %d:\n", n + 1);
                    getchar();
                    
                    printf("Ma sach: ");
                    fgets(books[n].id, sizeof(books[n].id), stdin);
                    books[n].id[strcspn(books[n].id, "\n")] = '\0';

                    printf("Ten sach: ");
                    fgets(books[n].name, sizeof(books[n].name), stdin);
                    books[n].name[strcspn(books[n].name, "\n")] = '\0';

                    printf("Tac gia: ");
                    fgets(books[n].author, sizeof(books[n].author), stdin);
                    books[n].author[strcspn(books[n].author, "\n")] = '\0';

                    printf("Gia tien: ");
                    scanf("%f", &books[n].price);
                    getchar();

                    printf("The loai: ");
                    fgets(books[n].category, sizeof(books[n].category), stdin);
                    books[n].category[strcspn(books[n].category, "\n")] = '\0';
                    
                    n++;
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Danh sach trong!\n");
                } else {
                    printf("\n--- DANH SACH SACH ---\n");
                    for(i = 0; i < n; i++) {
                        printf("ID: %s | Ten: %s | Gia: %.2f | TG: %s | TL: %s\n", 
                               books[i].id, books[i].name, books[i].price, books[i].author, books[i].category);
                    }
                }
                break;

            case 3:
                printf("Nhap vi tri muon them (0 den %d): ", n);
                int pos;
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for(i = n; i > pos; i--) {
                        books[i] = books[i-1];
                    }
                    getchar();
                    printf("Nhap thong tin sach moi:\n");
                    
                    printf("Ma sach: ");
                    fgets(books[pos].id, sizeof(books[pos].id), stdin);
                    books[pos].id[strcspn(books[pos].id, "\n")] = '\0';

                    printf("Ten sach: ");
                    fgets(books[pos].name, sizeof(books[pos].name), stdin);
                    books[pos].name[strcspn(books[pos].name, "\n")] = '\0';

                    printf("Tac gia: ");
                    fgets(books[pos].author, sizeof(books[pos].author), stdin);
                    books[pos].author[strcspn(books[pos].author, "\n")] = '\0';

                    printf("Gia tien: ");
                    scanf("%f", &books[pos].price);
                    getchar();

                    printf("The loai: ");
                    fgets(books[pos].category, sizeof(books[pos].category), stdin);
                    books[pos].category[strcspn(books[pos].category, "\n")] = '\0';
                    
                    n++;
                    printf("Them thanh cong!\n");
                }
                break;

            case 4:
                printf("Nhap ma sach muon xoa: ");
                getchar();
                fgets(searchId, sizeof(searchId), stdin);
                searchId[strcspn(searchId, "\n")] = '\0';
                
                found = 0;
                for(i = 0; i < n; i++) {
                    if(strcmp(books[i].id, searchId) == 0) {
                        for(j = i; j < n - 1; j++) {
                            books[j] = books[j+1];
                        }
                        n--;
                        found = 1;
                        printf("Da xoa sach co ma %s\n", searchId);
                        break;
                    }
                }
                if(found == 0) printf("Khong tim thay ma sach!\n");
                break;

            case 5:
                printf("Nhap ma sach can cap nhat: ");
                getchar();
                fgets(searchId, sizeof(searchId), stdin);
                searchId[strcspn(searchId, "\n")] = '\0';
                
                found = 0;
                for(i = 0; i < n; i++) {
                    if(strcmp(books[i].id, searchId) == 0) {
                        printf("Tim thay sach. Nhap thong tin moi:\n");
                        
                        printf("Ten sach: ");
                        fgets(books[i].name, sizeof(books[i].name), stdin);
                        books[i].name[strcspn(books[i].name, "\n")] = '\0';

                        printf("Tac gia: ");
                        fgets(books[i].author, sizeof(books[i].author), stdin);
                        books[i].author[strcspn(books[i].author, "\n")] = '\0';

                        printf("Gia tien: ");
                        scanf("%f", &books[i].price);
                        getchar();

                        printf("The loai: ");
                        fgets(books[i].category, sizeof(books[i].category), stdin);
                        books[i].category[strcspn(books[i].category, "\n")] = '\0';
                        
                        found = 1;
                        printf("Cap nhat thanh cong!\n");
                        break;
                    }
                }
                if(found == 0) printf("Khong tim thay sach!\n");
                break;

            case 6:
                printf("1. Tang dan\n2. Giam dan\nChon: ");
                scanf("%d", &sortChoice);
                
                for(i = 0; i < n - 1; i++) {
                    for(j = i + 1; j < n; j++) {
                        if(sortChoice == 1) {
                            if(books[i].price > books[j].price) {
                                temp = books[i];
                                books[i] = books[j];
                                books[j] = temp;
                            }
                        } else {
                            if(books[i].price < books[j].price) {
                                temp = books[i];
                                books[i] = books[j];
                                books[j] = temp;
                            }
                        }
                    }
                }
                printf("Da sap xep xong!\n");
                break;

            case 7:
                printf("Nhap ten sach can tim: ");
                getchar();
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';
                
                found = 0;
                printf("\nKet qua tim kiem:\n");
                for(i = 0; i < n; i++) {
                    if(strstr(books[i].name, searchName) != NULL) {
                        printf("ID: %s | Ten: %s | Gia: %.2f\n", books[i].id, books[i].name, books[i].price);
                        found = 1;
                    }
                }
                if(found == 0) printf("Khong tim thay sach nao!\n");
                break;

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choice != 8);

    return 0;
}
