#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 80
#define CGRN "\x1B[32m"


void encriptarMat(char mensaje[MAX], int dim1, int dim2); 
void desencriptarMat(char mensaje[MAX], int dim1, int dim2); 
void imprimir(char* mensaje);

int main(){
	char mensaje[MAX];
	printf("\nMensaje: ");
	fgets(mensaje, MAX, stdin);
	mensaje[strcspn(mensaje, "\r\n")] = 0;
	int dim1, dim2, op;
	printf("Ingresar dimension de columnas de matriz: ");
	scanf("%d", &dim1);
	
	size_t tamanoMen = 0;
	tamanoMen = strlen(mensaje);	//Definir tamaño de dim2 (renglones)
	dim2 = (tamanoMen / dim1); 
	if((tamanoMen%dim1) != 0){
		dim2+=1;
	}
	
	Eleccion:
	printf("1: Cifrar \n2: Descifrar\n");
	scanf("%d", &op);
	switch(op){
		case 1:
			encriptarMat(mensaje, dim1, dim2);
			break;
		case 2: 
			desencriptarMat(mensaje, dim1, dim2);
			break;
		default: 
			printf("No se eligió bien");
			goto Eleccion;
	}
	return 0;
}

//************************* ENCRIPTAR ****************************
void encriptarMat(char mensaje[MAX], int dim1, int dim2){
	int i, j;
	
	//concatenar relleno del mensaje
	int resto = abs((dim1 * dim2) - strlen(mensaje));
	const char* relleno = "&";
	for (i = 0; i < resto; i++)
		strncat(mensaje, relleno, (strlen(mensaje)+i+1));
	
	//crear espacio de memoria para matriz
	char** arreglo = (char**)malloc(sizeof(char*) * dim2);
	for (i = 0; i < dim2; i++)
		arreglo[i] = (char*)malloc(sizeof(char) * dim1);
	
	//recorrer y llenar matriz con el mensaje de r a c
	int posicion = 0;
	printf("\nMatriz original:\n");
	for (i = 0; i < dim2; i++)
	{
		for (j = 0; j < dim1; j++)
		{
			if(mensaje[posicion] == ' ') 
				mensaje[posicion] = '%';
			arreglo[i][j] = mensaje[posicion];
			printf("%c ", arreglo[i][j]);
			posicion++;
		}
		printf("\n");
	}
		
	//Matriz transpuesta *********
	printf("\nMatriz transpuesta:\n");	
	char mensajeEnc[(dim1*dim2) + 1];
	int posicionEnc = 0;
	for (i = 0; i < dim1; i++)
	{
		for (j = 0; j < dim2; j++)
		{
			mensajeEnc[posicionEnc] = arreglo[j][i];
			printf("%c ", arreglo[j][i]);
			posicionEnc++;
		}
		printf("\n");
	}
	mensajeEnc[(dim1*dim2)] = '\0'; 
	printf("\nTAMANO MENSAJE: %ld\n", strlen(mensajeEnc));

	
	printf("\nMensaje transpuesto:\n");	
	imprimir(mensajeEnc);
	
}

//************************* DESENCRIPTAR ****************************
void desencriptarMat(char mensaje[MAX], int dim1, int dim2){
	int i, j, posicion = 0;
	
	char** arreglo = (char**)malloc(sizeof(char*) * dim1);
	for (i = 0; i < dim1; i++)
		arreglo[i] = (char*)malloc(sizeof(char) * dim2);
	
	printf("\nMatriz original:\n");
	for (i = 0; i < dim1; i++)
	{
		for (j = 0; j < dim2; j++)
		{
			if((mensaje[posicion] == '%') | (mensaje[posicion] == '&')) 
				mensaje[posicion] = ' ';
			arreglo[i][j] = mensaje[posicion];
			printf("%c", arreglo[i][j]);
			posicion++;
		}
		printf("\n");
	}
	
	printf("\nMatriz descifrada:\n");
	char mensajeEnc[(dim1*dim2) + 1];
	int posicionEnc = 0;
	for (i = 0; i < dim2; i++)
	{
		for (j = 0; j < dim1; j++)
		{
			mensajeEnc[posicionEnc] = arreglo[j][i];
			printf("%c ", arreglo[j][i]);
			posicionEnc++;
		}
		printf("\n");
	}
	mensajeEnc[(dim1*dim2)] = '\0'; 
	printf("\nMensaje transpuesto:\n");	
	imprimir(mensajeEnc);
}

//************************* IMPRIMIR ****************************
void imprimir(char* mensaje){
	int i = 0;
	while (mensaje[i]) {
		printf("%c", (mensaje[i]));
		i++;
	}
}
