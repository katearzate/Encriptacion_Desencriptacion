/*
 * Implementación de Cifrado de César
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100
#define long_alfabeto 26
#define inicio_ascii_mayusculas 65
#define inicio_ascii_minusculas 97
#define MOD(i, n) (i % n + n) % n //modulo positivo
			      
const char *alfMinusculas = "abcdefghijklmnopqrstuvwxyz",
           *alfMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void encriptar(char *mensaje, char *resultado, int saltos);
void desencriptar(char *mensaje, char *resultado,int saltos);
void imprimir();


void encriptar(char *mensaje, char *resultado, int saltos) {
  printf("El mensaje encriptado es: ");
  int i = 0;
  while (mensaje[i]) {
    char caracterActual = mensaje[i];
    int posicionOriginalAscii = (caracterActual);	
    if (!isalpha(caracterActual)) {		//isalpha: corresponde a alguna letra
      resultado[i] = caracterActual;
      i++;
      continue; // siguiente iteración.
    }
    if (isupper(caracterActual)) {		//isupper: letra mayuscula
      resultado[i] =
          alfMayusculas[(posicionOriginalAscii - inicio_ascii_mayusculas +
                              saltos) %
                             long_alfabeto];
    } 
    else if (islower(caracterActual)) { //islower: letra minuscula 

      resultado[i] =
          alfMinusculas[(posicionOriginalAscii - inicio_ascii_minusculas +
                              saltos) %
                             long_alfabeto];
    }
    
    printf("%c", (resultado[i]));
    i++;
  }
}

void desencriptar(char *mensaje, char *resultado, int saltos) {
  printf("El mensaje desencriptado es: ");
  int i = 0;
  while (mensaje[i]) {
    char caracterActual = mensaje[i];
    int posicionOriginalAscii = (caracterActual);
    if (!isalpha(caracterActual)) {
      resultado[i] = caracterActual;
      i++;
      continue; 
    }
    if (isupper(caracterActual)) {		//es mayuscula
      resultado[i] = alfMayusculas[MOD(
          posicionOriginalAscii - inicio_ascii_mayusculas - saltos,
          long_alfabeto)];
    } else if (islower(caracterActual)) { 	//es minuscula
      resultado[i] = alfMinusculas[MOD(
          posicionOriginalAscii - inicio_ascii_minusculas - saltos,
          long_alfabeto)];
    }
    printf("%c", (resultado[i]));
    i++;
  }
}

void imprimir(){
	char mensaje[max], mensajeCifrado[max], mensajeDescifrado[max];
	int saltos, decision;
	printf("Escribe el mensaje: \n");
	fgets(mensaje, max, stdin);
	mensaje[strcspn(mensaje, "\r\n")] = 0;		//strcspn: devuelve la longitud de la cadena 	
	printf("Número de saltos: \n");
	scanf("%d", &saltos);
	tomaDecision:
	printf("\n¿Que opcion desea realizar?\n");
	printf("1: encriptar \n2: desencriptar\n");
	scanf("%d", &decision);
	switch(decision){
		case 1: 
			encriptar(mensaje, mensajeCifrado, saltos);
			break;
		case 2: 
			desencriptar(mensaje, mensajeDescifrado, saltos);
			break;
		default:
			printf("No se eligió un numero\n");
			goto tomaDecision;
	}
	printf("\n\n * \n * \n *\n\n");
	while(getchar() != '\n');
	imprimir();
}

int main(){
	
	printf(" ********** CIFRADO DE CESAR ************ \n");
	imprimir();
}
