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
    int deleteId;
    int foundIndex = -1;

    printf("\nDANH SACH SINH VIEN HIEN TAI:\n");
    printLine();
    printf("| %-5s | %-25s | %-5s | %-15s |\n", "ID", "Ho va Ten", "Tuoi", "So Dien Thoai");
    printLine();
    for (int i = 0; i < currentCount; i++) {
        printf("| %-5d | %-25s | %-5d | %-15s |\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
    printLine();

    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < currentCount; i++) {
        if (students[i].id == deleteId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nThong bao: Khong tim thay sinh vien co ID = %d\n", deleteId);
    } else {
        for (int i = foundIndex; i < currentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        currentCount--;
        printf("\nThong bao: Da xoa thanh cong sinh vien co ID = %d\n", deleteId);
    }

    printf("\nDANH SACH SINH VIEN SAU KHI XOA:\n");
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
