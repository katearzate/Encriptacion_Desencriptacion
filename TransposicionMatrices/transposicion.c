#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80

void matriz(char mensaje[MAX], int dim1); 

int main(){

	//LEER MENSAJE
	
	char mensaje[MAX];
	printf("\nMensaje: ");
	fgets(mensaje, MAX, stdin);
	mensaje[strcspn(mensaje, "\r\n")] = 0;

	int dim1;
	printf("Ingresar dimension de columnas de matriz (3,4 ó 5)");
	scanf("%d", &dim1);
	
	matriz(mensaje, dim1);
	return 0;
}


void matriz(char mensaje[MAX], int dim1){
	int i = 0, dim2;
	
	while(mensaje[i]){
		char caracter = mensaje[i];
		if (!isalpha(caracter)){ //si no es letra
			//mensaje[i]
		}
		i++;
	}
	dim2 = (i / dim1); //COLOCAR CONDICIONAL 
	if((i%dim1) != 0){
		dim2+=1;
	}
	printf("caracteres: %d\n", i);
	printf("la dimension: %d", dim2);
}
