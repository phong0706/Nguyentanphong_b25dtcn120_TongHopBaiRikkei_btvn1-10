#include<stdio.h>
#include<math.h>

int main(){
	int a = 3;
	int b = 5;
	int c = 3;
	double S = sqrt(a*a + b*b) / (c + 1) + (double)(a*b) / c - sqrt(abs(a - b) + c*c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("Ket qua S = %.2f\n", S);
	printf("Phong CNTT6");
	system("color 0B");
	
	return 0;

}
