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


void encriptarMat(char mensaje[MAX], Matriz* mat); 
void desencriptarMat(char mensaje[MAX], Matriz* mat); 
void imprimir(char* mensaje);

int main(){
	printf("%s \t********** CIFRADO POR MATRIZ TRANSPUESTA ************ \n", CCYN);
	
	char mensaje[MAX];
	printf("\n%sMensaje: ", CWHT);
	fgets(mensaje, MAX, stdin);
	mensaje[strcspn(mensaje, "\r\n")] = 0;
	int op;
	Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
	printf("Ingresar dimension de columnas de matriz: ");
	scanf("%d", &matriz->cols);
	
	size_t tamanoMen = 0;
	tamanoMen = strlen(mensaje);	//Definir tamaño de mat->filas (renglones)
	matriz->filas = (tamanoMen / matriz->cols); 
	if((tamanoMen%matriz->cols) != 0){
		matriz->filas+=1;
	}
	
	Eleccion:
	printf("1: Cifrar \n2: Descifrar\n");
	scanf("%d", &op);
	switch(op){
		case 1:
			encriptarMat(mensaje, matriz);
			break;
		case 2: 
			desencriptarMat(mensaje, matriz);
			break;
		default: 
			printf("No se eligió bien");
			goto Eleccion;
	}
	printf("\n\n\n * \n\n * \n\n *\n\n\n");
	while(getchar() != '\n');
	main();
	return 0;
}

//************************* ENCRIPTAR ****************************
void encriptarMat(char mensaje[MAX], Matriz* mat){
	int i, j;
	
	//concatenar relleno del mensaje
	int resto = abs((mat->cols * mat->filas) - strlen(mensaje));
	const char* relleno = "&";
	for (i = 0; i < resto; i++)
		strncat(mensaje, relleno, (strlen(mensaje)+i+1));
	
	//crear espacio de memoria para matriz
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
			if(mensaje[posicion] == ' ') 
				mensaje[posicion] = '%';
			mat->datos[i][j] = mensaje[posicion];
			printf("%c ", mat->datos[i][j]);
			posicion++;
		}
		printf("\n");
	}
		
	//Matriz transpuesta *********
	printf("\nMatriz transpuesta:\n");	
	char mensajeEnc[(mat->cols*mat->filas) + 1];
	int posicionEnc = 0;
	for (i = 0; i < mat->cols; i++)
	{
		for (j = 0; j < mat->filas; j++)
		{
			mensajeEnc[posicionEnc] = mat->datos[j][i];
			printf("%c ", mat->datos[j][i]);
			posicionEnc++;
		}
		printf("\n");
	}
	mensajeEnc[(mat->cols*mat->filas)] = '\0'; 
	printf("\nMensaje cifrado:\n");	
	imprimir(mensajeEnc);
	
}

//************************* DESENCRIPTAR ****************************
void desencriptarMat(char mensaje[MAX], Matriz* mat){
	int i, j, posicion = 0;
	
	mat->datos = (char**)malloc(sizeof(char*) * mat->cols);
	for (i = 0; i < mat->cols; i++)
		mat->datos[i] = (char*)malloc(sizeof(char) * mat->filas);
	
	printf("\nMatriz original:\n");
	for (i = 0; i < mat->cols; i++)
	{
		for (j = 0; j < mat->filas; j++)
		{/*
			if((mensaje[posicion] == '%') | (mensaje[posicion] == '&')) 
				mensaje[posicion] = ' ';*/
			mat->datos[i][j] = mensaje[posicion];
			printf("%c", mat->datos[i][j]);
			posicion++;
		}
		printf("\n");
	}
	
	printf("\nMatriz transpuesta:\n");
	char mensajeEnc[(mat->cols*mat->filas) + 1];
	int posicionEnc = 0;
	for (i = 0; i < mat->filas; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			if((mat->datos[j][i] == '%') | (mat->datos[j][i] == '&')) 
				mensajeEnc[posicionEnc] = ' ';
			else
			mensajeEnc[posicionEnc] = mat->datos[j][i];
			printf("%c ", mat->datos[j][i]);
			posicionEnc++;
		}
		printf("\n");
	}
	mensajeEnc[(mat->cols*mat->filas)] = '\0'; 
	printf("\nMensaje descifrado:\n");	
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
