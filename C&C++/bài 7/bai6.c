#include<stdio.h>

int main(){
	int n;
	int soDaoNguoc = 0;
	int chuSoCuoi;
	printf("Chu so nguyen n:");
	scanf("%d", &n);
	while (n!=0){
	chuSoCuoi= n % 10;
	soDaoNguoc= soDaoNguoc * 10 + chuSoCuoi;
	n = n/10;
}
    printf("Chu so dao nguoc: %d\n", soDaoNguoc);
    return 0;
}
