#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};

int main() {
    struct Student students[50] = {
        {1, "Nguyen Duong Khanh Linh", 30, "0901234567"},
        {2, "Bui Nguyen Thanh An", 50, "0902345678"},
        {3, "Dang Ngoc Thai", 10, "0903456789"},
        {4, "Nguyen Tan Phong", 18, "0904567890"},
        {5, "Lam Tung Duong", 21, "0905678901"}
    };
    
    int currentCount = 5;
    int searchId;
    int foundIndex = -1;

    printf("--- Danh sach ban dau ---\n");
    for(int i = 0; i < currentCount; i++) {
        printf("ID: %d | Ten: %s | Tuoi: %d | SDT: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &searchId);

    for (int i = 0; i < currentCount; i++) {
        if (students[i].id == searchId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Khong tim thay sinh vien co ID = %d\n", searchId);
    } else {
        printf("Da tim thay sinh vien: %s\n", students[foundIndex].name);
        
        getchar(); 

        printf("Nhap ten moi: ");
        fgets(students[foundIndex].name, sizeof(students[foundIndex].name), stdin);
        students[foundIndex].name[strcspn(students[foundIndex].name, "\n")] = 0;

        printf("Nhap tuoi moi: ");
        scanf("%d", &students[foundIndex].age);

        printf("--> Cap nhat thanh cong!\n");
    }

    printf("\n--- Danh sach sinh vien sau khi chinh sua ---\n");
    for(int i = 0; i < currentCount; i++) {
        printf("ID: %d | Ten: %s | Tuoi: %d | SDT: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    return 0;
};
