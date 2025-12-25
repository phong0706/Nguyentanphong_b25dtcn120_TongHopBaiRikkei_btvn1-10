#include<stdio.h>
	
//	int num = 10;
//	
//	printf("%d\n",num);
//	printf("%p", &num);
//	
//	num = 120;
//	
//	printf("\n%d\n",num);
//	printf("%p", &num);
//	
//	int *p = &num;
//	printf("\n%d\n", *p);
//	printf("\%p", *p);

//void swap(int *a, int *b){
//	int temp = *b;
//	*b = *a;
//	*a = temp;
//	
//	printf("Trong ham: %d va %d\n", *a,*b);
//}
//
//int main(){
//	int a = 10;
//	int b = 20;
//	
//	swap(&a,&b);
//	printf("%d va %d", a,b);
//}


void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
	
	printf("trong ham: %d va %d\n", *a,*b);
	
}

void sumOfElement(int *a, int *b, int *result){
	*result = *a + *b;
}

int main(){
	int arr[] = {9,2,6,11,25,54,223,52};
	int n = sizeof(arr) / sizeof(arr[0]);
	for(int i =0; i<n; i++){
		printf("%d ", *(arr+i));
	}
}
