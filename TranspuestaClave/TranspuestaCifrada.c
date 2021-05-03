#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 80
#define CCYN "\x1B[36m"
#define CWHT "\x1B[37m"

typedef struct matriz{
	unsigned filas;
	unsigned cols;
	char** datos;
}Matriz; 

void cifrar(char mensaje[MAX], char clave[MAX], Matriz* mat);

int main(){
	printf("%s \t********** CIFRADO POR MATRIZ TRANSPUESTA ************ \n", CCYN);
	
	char mensaje[MAX], clave[MAX];
	printf("\n%sMensaje: ", CWHT);
	fgets(mensaje, MAX, stdin);
	mensaje[strcspn(mensaje, "\r\n")] = 0;
	
	printf("\nClave: ");
	fgets(clave, MAX, stdin);
	clave[strcspn(clave, "\r\n")] = 0;

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
	strncat(clave, mensaje, (strlen(clave)+1));
	
	int resto = abs((mat->cols * mat->filas) - strlen(clave));
	const char* relleno = "&";
	for (i = 0; i < resto; i++)
		strncat(clave, relleno, (strlen(clave)+i+1));
	
	while (clave[j]) {
		printf("%c", (clave[j]));
		j++;
	}
}

