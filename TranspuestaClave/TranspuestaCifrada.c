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
Matriz* transpuesta(Matriz* mat);
void imprimirMensaje(char* mensaje);
void imprimirMatriz(Matriz* mat);
void crearEspacio(Matriz* mat);
void liberarMemoria(Matriz* mat);

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
	int i, j;
	strncat(clave, mensaje, (strlen(mensaje)));
	
	int resto = abs((mat->cols * mat->filas) - strlen(clave));
	const char* relleno = "&";
	for (i = 0; i < resto; i++)
		strncat(clave, relleno, (strlen(clave)+i));
	
	crearEspacio(mat);
		
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
	Matriz* nvaMat = transpuesta(mat);
	char* col;
	printf("\n*****************");
	printf("\n\nMatriz por clave: \n");
	for (i = 0; i < (nvaMat->filas)-1; i++){
		if(nvaMat->datos[i][0] > nvaMat->datos[i+1][0]){
			col = nvaMat->datos[i];
			nvaMat->datos[i] = nvaMat->datos[i+1];
			nvaMat->datos[i+1] = col; 
			i = -1;
		}
	}
	nvaMat = transpuesta(nvaMat);
	imprimirMatriz(nvaMat);
	
}


Matriz* transpuesta(Matriz* mat){
	int i, j;
	Matriz* nvaMatriz = (Matriz*)malloc(sizeof(Matriz));
	
	nvaMatriz->filas = mat->cols;
	nvaMatriz->cols = mat->filas;
	crearEspacio(nvaMatriz);
	
	for (i = 0; i < mat->filas; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			nvaMatriz->datos[j][i] = mat->datos[i][j];
		}
	}
	liberarMemoria(mat);
	
	return nvaMatriz;
}

void imprimirMensaje(char* mensaje){
	int i = 0;
	while (mensaje[i]) {
		printf("%c", (mensaje[i]));
		i++;
	}
}

void imprimirMatriz(Matriz* mat){
	int i, j, posicionEnc = 0;
	char mensajeEnc[(mat->cols*mat->filas) + 1];
	for (i = 0; i < mat->filas; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			printf("%c ", mat->datos[i][j]);
			mensajeEnc[posicionEnc] = mat->datos[i][j];
			posicionEnc++;
		}
		printf("\n");
	} 
	mensajeEnc[(mat->cols*mat->filas)] = '\0'; 
	printf("\nResultado:\n");
	imprimirMensaje(mensajeEnc);	
}

void crearEspacio(Matriz* mat){
	int i;
	mat->datos = (char**)malloc(sizeof(char*) * mat->filas);
	for (i = 0; i < mat->filas; i++)
		mat->datos[i] = (char*)malloc(sizeof(char) * mat->cols);
}


void liberarMemoria(Matriz* mat){
	int i;
	for (i = 0; i < mat->filas; i++)
	{
		free(mat->datos[i]);
	}
	free(mat->datos);
}
