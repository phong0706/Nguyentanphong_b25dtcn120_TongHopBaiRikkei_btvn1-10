#include <stdio.h>

int i; 
int table(int tab[], int n) {
    printf("Cac phan tu trong mang: ");
    for(i = 0; i <n ;i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    int n,i ;
    int table[100];
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    printf("Nhap cac phan tu:\n");
    for( i = 0; i <n; i++) {
        scanf("%d", &table[i]);
    }
    afficherTableau(table,n);
    return 0;
}
