#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

void timKiemSinhVien(struct Student list[], char tenCanTim[]) {
    int timThay = 0;
    int i;
    
    for(i = 0; i < 5; i++) {
        if(strcmp(list[i].name, tenCanTim) == 0) {
            printf("\nTim thay sinh vien:\n");
            printf("Ten: %s\n", list[i].name);
            printf("Tuoi: %d\n", list[i].age);
            printf("Diem: %.2f\n", list[i].grade);
            timThay = 1;
        }
    }

    if(timThay == 0) {
        printf("\nKhong tim thay sinh vien co ten: %s\n", tenCanTim);
    }
}

int main() {
    struct Student students[5];
    int i;
    char tenTimKiem[50];

    for(i = 0; i < 5; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        
        printf("Nhap ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap diem: ");
        scanf("%f", &students[i].grade);
        getchar();
    }

    printf("\nNhap ten sinh vien can tim: ");
    fgets(tenTimKiem, sizeof(tenTimKiem), stdin);
    tenTimKiem[strcspn(tenTimKiem, "\n")] = '\0';

    timKiemSinhVien(students, tenTimKiem);

    return 0;
};
