#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 80
#define CCYN "\x1B[36m"
#define CWHT "\x1B[37m"

typedef struct matriz{
	unsigned filas;
	unsigned cols;
	char** datos;
}Matriz; 

void cifrar(char mensaje[MAX], char clave[MAX], Matriz* mat);
void imprimir(char* mensaje);

int main(){
	printf("%s \t********** CIFRADO POR MATRIZ TRANSPUESTA ************ \n", CCYN);
	
	char clave[MAX], mensaje[MAX];
	
	printf("\n%sClave: ", CWHT);
	fgets(clave, MAX, stdin);
	clave[strcspn(clave, "\r\n")] = 0;

	printf("\nMensaje: ");
	fgets(mensaje, MAX, stdin);
	mensaje[strcspn(mensaje, "\r\n")] = 0;

	Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
	matriz->cols = strlen(clave); 	//tamaño de las columnas
	size_t tamanoMen = 0;
	tamanoMen = strlen(mensaje);	//tamaño de los renglones
	matriz->filas = ((tamanoMen / matriz->cols) + 1); 		//+1 es para agregar la clave
	if((tamanoMen % matriz->cols) != 0){
		matriz->filas+=1;
	}
	
	cifrar(mensaje, clave, matriz);
}

void cifrar(char mensaje[MAX], char clave[MAX], Matriz* mat){
	int i, j = 0;
	strncat(clave, mensaje, (strlen(mensaje)));
	
	int resto = abs((mat->cols * mat->filas) - strlen(clave));
	const char* relleno = "&";
	for (i = 0; i < resto; i++)
		strncat(clave, relleno, (strlen(clave)+i));

	imprimir(clave);
	
	//Crear espacio para la matriz
	mat->datos = (char**)malloc(sizeof(char*) * mat->filas);
	for (i = 0; i < mat->filas; i++)
		mat->datos[i] = (char*)malloc(sizeof(char) * mat->cols);
		
	//recorrer y llenar matriz con el mensaje de r a c
	int posicion = 0;
	printf("\nMatriz original:\n");
	for (i = 0; i < mat->filas; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			if(clave[posicion] == ' ') 
				clave[posicion] = '%';
			mat->datos[i][j] = clave[posicion];
			printf("%c ", mat->datos[i][j]);
			posicion++;
		}
		printf("\n");
	}
			
	//acomodar alfabeticamente la clave y reordenar matriz
	char caracter;
	printf("\n\nMatriz reordenada por clave: \n");
	for (i = 0; i < (mat->cols) - 1; i++){
		if(toascii(mat->datos[0][i]) > toascii(mat->datos[0][i+1])){
			for (j = 0; j < mat->filas ; j++){
				caracter = mat->datos[i][j];
				mat->datos[i][j] = mat->datos[i+1][j];
				mat->datos[i+1][j] = caracter;
				
				printf("%c ", mat->datos[i][j]);
			}
		}
	}

	printf("\n************************\n");
	for (i = 0; i < mat->filas; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			if(toascii(mat->datos[0][j]) > toascii(mat->datos[0][j+1])) {
				caracter = mat->datos[i][j];
				mat->datos[i][j] = mat->datos[i+1][j];
				mat->datos[i+1][j] = caracter;
				
			}
			printf("%c ", mat->datos[i][j]);
		}
		printf("\n");
	}
	
	
}

void imprimir(char* mensaje){
	int i = 0;
	while (mensaje[i]) {
		printf("%c", (mensaje[i]));
		i++;
	}
}


