#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 50
#define long_alfabeto 26
#define inicio_ascii_mayusculas 65
#define inicio_ascii_minusculas 97

const char *alfMinusculas = "abcdefghijklmnopqrstuvwxyz",
           *alfMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void importarDiccionario(char* nomArchivo);
void importarTexto(char* nomArchivo);
void encriptar(char *mensaje, char *resultado);

int main(){
	char nomDiccionario[max], nomTexto[max];
	printf("********************* Kate The Ripper ********************\n");
	system("ls\n\n");
	
	printf("Ingresar nombre de diccionario: \n");
	fgets(nomDiccionario, max, stdin);
	strtok(nomDiccionario, "\n");
	
	printf("Ingresar nombre de archivo con texto: \n");
	fgets(nomTexto, max, stdin);
	strtok(nomTexto, "\n");
	
	importarDiccionario(nomDiccionario);
	//importarTexto(nomTexto);
	
	return 0;
}


//********************** FUNCION IMPORTAR DICCIONARIO DE DATOS ******************************
void importarDiccionario(char* nomArchivo){
	char texto[max], encriptada[max], textoACrackear[max];
	
	/*printf("Ingresar el texto a crackear: \n");
	fgets(textoACrackear, max, stdin);
	strtok(textoACrackear, "\n");*/
	importarTexto(texto);
	
	FILE *archivo;
	archivo = fopen ( nomArchivo, "r" );        
	if (archivo==NULL) {
		fprintf(stderr, "** Error de archivo del diccionario **\n"); 
		exit(0);
	}
	while(1){
		if(fgets(texto, max, archivo) == NULL) break; 
		encriptar(texto, encriptada);
		strtok(encriptada, "\n");
		strtok(texto, "\n");
		if(strcmp(textoACrackear, encriptada) == 0){
			printf("\n\nLa contraseña es: %s", texto);
			fclose (archivo);
			exit(0);
		}else {
			printf(".");
			continue;
		}
		while(getchar() != '\n');
	}
	printf("\n\n * Contraseña no encontrada *");
	fclose (archivo);
}



//********************** FUNCION LEER ARCHIVO CON TEXTO CIFRADO *****************************
void importarTexto(char* nomArchivo){
	FILE *archivo;
	archivo = fopen ( nomArchivo, "r" );        
	if (archivo==NULL) {
		fprintf(stderr, "** Error de archivo de texto encriptado **\n"); 
		exit(0);
	}
	while(1){
		if(fgets(nomArchivo, max, archivo) == NULL) break; 
		strtok(nomArchivo, "\n");
	}
	fclose(archivo);
}


//******************************** FUNCION ENCRIPTAR *****************************************
void encriptar(char *mensaje, char *resultado) {
	int i = 0, saltos = 3;				  //definir el numero de saltos.
	while (mensaje[i]) {
		char caracterActual = mensaje[i];
		int posicionOriginalAscii = (caracterActual);	
		if (!isalpha(caracterActual)) {		
			resultado[i] = caracterActual;
			i++;
			continue; 
		}
		if (isupper(caracterActual)) {
			resultado[i] = alfMayusculas[(posicionOriginalAscii - inicio_ascii_mayusculas + saltos) % long_alfabeto];
		} 
		else if (islower(caracterActual)) { 
			resultado[i] = alfMinusculas[(posicionOriginalAscii - inicio_ascii_minusculas + saltos) % long_alfabeto];
		}
		i++;
	}
}




