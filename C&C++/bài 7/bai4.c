#include <stdio.h>

int main() {
    int m, n;
    int i, j;

    printf("Nhap chieu dai m (so dong): ");
    scanf("%d", &m);
    printf("Nhap chieu rong n (so cot): ");
    scanf("%d", &n);

    for (i = 0; i < m; i++) {
        
        for (j = 0; j < n; j++) {
            
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        
        printf("\n");
    }

    return 0;
}
