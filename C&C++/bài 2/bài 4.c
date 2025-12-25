#include <stdio.h>
#include <math.h>

int main(){
	int height = 30;
	int width = 40;
	int sum = height + width;
	int sub = height - width;
	int multi = height * width;
	int div = height / width;
	int div2 = height % width;
	printf("Tong = %d\n", sum);
	printf("Hieu = %d\n", sub);
	printf("Nhan = %d\n", multi);
	printf("Chia = %d\n", div);
	printf("Chia lay phand du = %d\n", div2);
}
