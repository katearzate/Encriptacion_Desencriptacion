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
void descifrar(char mensaje[MAX], char clave[MAX], Matriz* mat);

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
	
	//Menu de eleccion
	Eleccion:
	printf("1: Cifrar \n2: Descifrar\n");
	int op;
	scanf("%d", &op);
	switch(op){
		case 1:
			matriz->filas = ((tamanoMen / matriz->cols) + 1);//+1 renglon para la clave
			if((tamanoMen % matriz->cols) != 0)
				matriz->filas+=1;
			cifrar(mensaje, clave, matriz);
			break;
		case 2: 
			matriz->filas = (tamanoMen / matriz->cols);
			if((tamanoMen % matriz->cols) != 0)
				matriz->filas+=1;
			descifrar(mensaje, clave, matriz);
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

//*********************** FUNCION DE CIFRADO ***********************
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

//********************** FUNCION DE DESCIFRAR **********************
void descifrar(char mensaje[MAX], char clave[MAX], Matriz* mat){
	crearEspacio(mat);
	
	int i, j, posicion = 0;
	printf("\nMatriz original:\n");
	for (i = 0; i < mat->filas; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			mat->datos[i][j] = mensaje[posicion];
			printf("%c ", mat->datos[i][j]);
			posicion++;
		}
		printf("\n");
	}
	Matriz* nvaMat = transpuesta(mat);
	//reacomodar matriz por clave ingresada
	printf("\n*****************");
	printf("\n\nMatriz por clave: \n");
	/*char* col;
	int aux = 0;
	for (i = 0; i < (nvaMat->filas)-1; i++)
	{
		if(nvaMat->datos[aux][0] == clave[i]){
			col = nvaMat->datos[i];
			nvaMat->datos[i] = nvaMat->datos[aux];
			nvaMat->datos[aux] = col; 
			aux++;
			i = 0;
		}
	}
	nvaMat = transpuesta(nvaMat);
	imprimirMatriz(nvaMat);
	*/
	
	char* col;
	for (i = 0; i < nvaMat->filas; i++)
	{
		for (j = 0; j < strlen(clave); j++)
		{
			if(nvaMat->datos[i][0] == clave[j]){
				col = nvaMat->datos[i];
				nvaMat->datos[i] = nvaMat->datos[j];
				nvaMat->datos[j] = col;
				break;
			}
		}
	}
	nvaMat = transpuesta(nvaMat);
	
	//imprimir mensaje
	char mensajeEnc[(nvaMat->cols*(nvaMat->filas - 1)) + 1];
	int posicionEnc = 0;
	for (i = 1; i < nvaMat->filas; i++)
	{
		for (j = 0; j < nvaMat->cols; j++)
		{
			printf("%c ", nvaMat->datos[i][j]);
			if((nvaMat->datos[i][j] == '%') || (nvaMat->datos[i][j] == '&')) 
				nvaMat->datos[i][j] = ' ';
			mensajeEnc[posicionEnc] = nvaMat->datos[i][j];
			posicionEnc++;
		}
		printf("\n");
	} 
	mensajeEnc[mat->cols*(mat->filas-1)] = '\0'; 
	printf("\nResultado:\n");
	imprimirMensaje(mensajeEnc);
}

//*********************** MATRIZ TRANSPUESTA ***********************
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

//*********************** IMPRIMIR EL MENSAJE ***********************
void imprimirMensaje(char* mensaje){
	int i = 0;
	while (mensaje[i]) {
		printf("%c", (mensaje[i]));
		i++;
	}
}

//************************ IMPRIMIR LA MATRIZ ***********************
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

//******************** CREAR ESPACIO PARA MATRIZ ********************
void crearEspacio(Matriz* mat){
	int i;
	mat->datos = (char**)malloc(sizeof(char*) * mat->filas);
	for (i = 0; i < mat->filas; i++)
		mat->datos[i] = (char*)malloc(sizeof(char) * mat->cols);
}

//******************** LIBERAR ESPACIO DE MATRIZ ********************
void liberarMemoria(Matriz* mat){
	int i;
	for (i = 0; i < mat->filas; i++)
	{
		free(mat->datos[i]);
	}
	free(mat->datos);
}
