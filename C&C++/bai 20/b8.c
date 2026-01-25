#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};

void printLine() {
    printf("+-------+---------------------------+-------+-----------------+\n");
}

int main() {
    struct Student students[50] = {
        {1, "Nguyen Duong Khanh Linh", 30, "0901234567"},
        {2, "Bui Nguyen Thanh An", 50, "0902345678"},
        {3, "Dang Ngoc Thai", 10, "0903456789"},
        {4, "Nguyen Tan Phong", 18, "0904567890"},
        {5, "Lam Tung Duong", 21, "0905678901"}
    };

    int currentCount = 5;
    int position;

    printf("\nDANH SACH SINH VIEN HIEN TAI:\n");
    printLine();
    printf("| %-5s | %-25s | %-5s | %-15s |\n", "ID", "Ho va Ten", "Tuoi", "So Dien Thoai");
    printLine();
    for (int i = 0; i < currentCount; i++) {
        printf("| %-5d | %-25s | %-5d | %-15s |\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
    printLine();

    if (currentCount >= 50) {
        printf("Mang da day, khong the chen them!\n");
        return 0;
    }

    printf("\nNhap vi tri muon chen (0 - %d): ", currentCount);
    scanf("%d", &position);

    if (position < 0 || position > currentCount) {
        printf("Vi tri khong hop le!\n");
    } else {
        
        for (int i = currentCount; i > position; i--) {
            students[i] = students[i - 1];
        }

        printf("Nhap ID: ");
        scanf("%d", &students[position].id);
        
        getchar(); 

        printf("Nhap Ten: ");
        fgets(students[position].name, sizeof(students[position].name), stdin);
        students[position].name[strcspn(students[position].name, "\n")] = 0;

        printf("Nhap Tuoi: ");
        scanf("%d", &students[position].age);
        
        getchar();

        printf("Nhap SDT: ");
        fgets(students[position].phoneNumber, sizeof(students[position].phoneNumber), stdin);
        students[position].phoneNumber[strcspn(students[position].phoneNumber, "\n")] = 0;

        currentCount++;

        printf("\n--> Da chen thanh cong!\n");
    }

    printf("\nDANH SACH SINH VIEN SAU KHI CHEN:\n");
    printLine();
    printf("| %-5s | %-25s | %-5s | %-15s |\n", "ID", "Ho va Ten", "Tuoi", "So Dien Thoai");
    printLine();
    for (int i = 0; i < currentCount; i++) {
        printf("| %-5d | %-25s | %-5d | %-15s |\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
    printLine();

    return 0;
}
