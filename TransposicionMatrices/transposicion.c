#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80


int main(){

	//LEER MENSAJE
	
	char mensaje[MAX];
	printf("\nMensaje: ");
	fgets(mensaje, MAX, stdin);
	mensaje[strcspn(mensaje, "\r\n")] = 0;

	int DIM;
	printf("Ingresar dimension de columnas de matriz (3,4 ó 5)");
	scanf("%d", &DIM);
	
	int i = 0, tot;
	while(mensaje[i]){
		i++;
	}
	tot = (i / DIM); //COLOCAR CONDICIONAL 
	if((i%DIM) != 0){
		tot+=1;
	}
	printf("caracteres: %d\n", i);
	printf("la dimension: %d", tot);
	
	return 0;
}

