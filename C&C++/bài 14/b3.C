#include <stdio.h>

int tinhTong(int so_a, int so_b);

int main() {
    int so_thu_nhat, so_thu_hai;
    int ket_qua_tong;

    printf("--- CHUONG TRINH TINH TONG 2 SO ---\n");
    
    printf("Nhap so thu nhat (so nguyen): ");
    scanf("%d", &so_thu_nhat);
    
    printf("Nhap so thu hai (so nguyen): ");
    scanf("%d", &so_thu_hai);

    ket_qua_tong = tinhTong(so_thu_nhat, so_thu_hai);

    printf("\nKet qua:\n");
    printf("%d + %d = %d\n", so_thu_nhat, so_thu_hai, ket_qua_tong);
    
    return 0;
}

int tinhTong(int so_a, int so_b) {
    int tong = so_a + so_b;
    return tong;
}
