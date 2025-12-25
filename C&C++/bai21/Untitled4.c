#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book books[3];
    int i;

    for(i = 0; i < 3; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        
        printf("Ten sach: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        getchar(); 
    }

    printf("\n--- DANH SACH SACH ---\n");
    for(i = 0; i < 3; i++) {
        printf("Sach %d: Ten: %s - Tac gia: %s - Gia: %.2f\n", 
               i + 1, books[i].title, books[i].author, books[i].price);
    }

    return 0;
};
