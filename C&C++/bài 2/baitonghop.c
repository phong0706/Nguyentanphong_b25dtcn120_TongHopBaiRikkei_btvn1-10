#include<stdio.h>
#include<math.h>

int main(){
	int a = 5;
	int b = 3;
	int c = 7;
	double double_a = a;
    double double_b = b;
    double double_c = c;
	double term1 = (pow(double_a, 2) + sqrt(pow(double_b, 2) + 4 * double_a * double_c)) / (2 * double_a);
	double term2 = pow(double_b, 3) / pow(double_c, 2);
	double term3 = sqrt(abs(double_a - double_b));
	double S = term1 - term2 + term3;
	printf("Voi gia tri cua a,b,c");
	printf(" thi gia tri cua S= %f\n", S);
	printf("Phong cntt6");
	system("color 0E");
	return 0;	
}
