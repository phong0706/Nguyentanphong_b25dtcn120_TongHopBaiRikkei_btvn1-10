# include <stdio.h>
struct Student {
	char name[50];
	int age ;
	char phoneNumber[15]; 
}; 
int main (){
	struct Student sv;
	printf ("Nhap thong tin sinh vien\n");
	fflush(stdin);	
	printf ("Name: ") ;
	fgets (sv.name,sizeof(sv.name),stdin);
	printf ("Age: ");
	scanf ("%d",&sv.age);
	fflush(stdin);	
	printf ("SDT: ");
    fgets(sv.phoneNumber, sizeof(sv.phoneNumber), stdin);
	printf ("\nThong tin sinh vien\n");
	printf ("Name: %s",sv.name);
	printf ("Age: %d\n",sv.age) ;
	printf ("SDT: %s\n",sv.phoneNumber) ;
	return 0; 
} 