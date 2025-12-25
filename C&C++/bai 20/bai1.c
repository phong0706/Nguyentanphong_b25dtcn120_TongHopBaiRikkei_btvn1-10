#include <stdio.h>
#include <string.h> 
struct Student {
	char name[50];
	int age;
	char phoneNumber[15]; 
}; 
int main (){
	struct Student sv;
	strcpy(sv.name,"NGUYEN TAN FONG");
	sv.age= 18;
	strcpy(sv.phoneNumber,"034207001655");
	printf ("Thong tin sinh vien\n");
	printf ("Name: %s\n",sv.name);
	printf ("Age: %d\n",sv.age) ;
	printf ("Phone: %s\n",sv.phoneNumber) ;
	return 0; 
	 
} 
