# include <stdio.h>
#include <string.h> 

struct Student {
	int id; 
	char name[50];
	int age ;
	char phoneNumber[15]; 
}; 
	 
int main (){
		struct Student sv[50];
	for (int i=0;i<5;i++){
		sv[i].id =i+1; 
		fflush(stdin); 
		printf ("Sinh vien thu %d: ",i+1);
		fgets (sv[i].name,sizeof(sv[i].name),stdin);
		sv[i].name[strcspn(sv[i].name, "\n")] = '\0';
	    printf ("Age: ");
	    scanf ("%d",&sv[i].age);
		fflush(stdin);
	    printf ("SDT: ");
	    scanf ("%s",&sv[i].phoneNumber); 
	} 
	
	printf ("\nThong tin sinh vien\n") ;
	printf ("\n%-3s|%-25s | %-5s | %-15s |\n","ID","NAME","AGE","SDT");

	for (int i=0;i<5;i++){
	    printf ("\n%-3d|%-25s | %-5d | %-15s |\n",sv[i].id,sv[i].name,sv[i].age,sv[i].phoneNumber); 
	} 
	
};
