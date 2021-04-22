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
	int dim2, i, j;
	size_t tamanoMen = 0;
	//Definir tamaño de dim2 (renglones)
	tamanoMen = strlen(mensaje);
	dim2 = (tamanoMen / dim1); 
	if((tamanoMen%dim1) != 0){
		dim2+=1;
	}
	
	//concatenar relleno del mensaje
	int resto = (dim1 * dim2) - strlen(mensaje);
	const char* relleno = "&";
	for (i = 0; i < resto; i++)
		strncat(mensaje, relleno, (strlen(mensaje)+i+1));
	
	//crear espacio de memoria para matriz
	char** arreglo = (char**)malloc(sizeof(char) * dim2);
	for (i = 0; i < dim1; i++)
	{
		arreglo[i] = (char*)malloc(sizeof(char) * dim1);
		//strncpy(arreglo[i], msg, strlen(msg));
	}
	
	//recorrer y llenar matriz
	int posicion = 0;
	for (i = 0; i < dim2; i++)
	{
		for (j = 0; j < dim1; j++)
		{
			if(mensaje[posicion] == ' ') 
				mensaje[posicion] = '%';
			arreglo[i][j] = mensaje[posicion];
			printf("%c", arreglo[i][j]);
			posicion++;
		}
		printf("\n");
	}
	
	
}
