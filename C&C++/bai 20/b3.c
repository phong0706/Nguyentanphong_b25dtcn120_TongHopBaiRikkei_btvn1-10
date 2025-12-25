# include <stdio.h>
#include <string.h>
 
struct Student {
	char name[50];
	int age ;
	char phoneNumber[15]; 
}; 
int main (){
	struct Student sv[5];
	for (int i=0;i<5;i++){
		fflush(stdin); 
		printf ("Name : ");
		fgets (sv[i].name,sizeof(sv[i].name),stdin);
		sv[i].name[strcspn(sv[i].name, "\n")] = '\0';
	    printf ("Age: ");
	    scanf ("%d",&sv[i].age);	
	    fflush(stdin);
	    printf ("SDT: ");
        fgets(sv[i].phoneNumber, sizeof(sv[i].phoneNumber), stdin);

	} 
	printf ("\nThong tin sinh vien\n") ;
	printf ("\n%-25s | %-5s | %-15s |\n","NAME","AGE","SDT");

	for (int i=0;i<5;i++){
	    printf ("\n%-25s | %-5d | %-15s |\n",sv[i].name,sv[i].age,sv[i].phoneNumber); 
	} 
	return 0; 
};
