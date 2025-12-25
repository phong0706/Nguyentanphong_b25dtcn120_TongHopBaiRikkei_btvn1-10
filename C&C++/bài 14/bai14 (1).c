#include <stdio.h>

int calculerSomme(int a, int b) {
    int somme = a + b; 
    return somme;   
}

int main() {
    int nombreA;
    int nombreB;
    printf("Entrez le premier nombre: "); 
    scanf("%d", &nombreA); 
    printf("Entrez le deuxieme nombre: "); 	
    scanf("%d", &nombreB);
    int resultat;	//ket qua
    resultat = calculerSomme(nombreA, nombreB);
    printf("La somme de %d et %d est : %d\n", nombreA, nombreB, resultat);
    return 0;
}
