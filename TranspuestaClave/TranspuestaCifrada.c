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
	matriz->cols = strlen(clave); 	//saber el tamaño de las columnas

}


