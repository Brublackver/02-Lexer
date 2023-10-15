#include <stdio.h>
#include "reconocedor.h"

int parentesis_control;//actua como pila para conotrolar el correcto uso de parentesis

int parentesis(int valor){parentesis_control = parentesis_control + valor;}

void procesarArchivoDeTexto(const char *nombreArchivo) {//funcion que recibe archivo de texto y lee caracter por caracter
   
    // Abre el archivo en modo lectura
    FILE *archivo = fopen(nombreArchivo, "r");


    //Si el archhivo no esta vacio, lee caracter por caracter
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    int estado_actual = 0;
    char caracter;
    while ((caracter = fgetc(archivo)) != EOF) {//asigna el caracter a la variable y trabaja con ella

     if ((caracter == '\n' || caracter == '\r')){
       if ((estado_actual == 1 || estado_actual == 4 || estado_actual == 5 )&&(parentesis_control ==0)){
        //los valores de de aceptacion
                       printf("ACEPTADA\n");
             }else if (parentesis_control !=0){  
               printf("RECHAZADA\n");
               break;
               estado_actual = 0;
               parentesis_control = 0;
               };

               estado_actual = 0;
               parentesis_control = 0;
          
            continue;
        };

        printf("%d -> %c -> ", estado_actual, caracter);//imprime en pantalla el proceso
        estado_actual = T(estado_actual, caracter);
        printf("%d\n", estado_actual);
        
        
        if (estado_actual == -1) { // evalua si es correcto el proceso
            printf("RECHAZADA\n");
            break;
            estado_actual = 0;
            parentesis_control = 0;
        };
    };

    fclose(archivo);
    return;
}

int main() {//funcion main, define el archivo de texto a leer
    parentesis_control = 0;
    const char *nombreArchivo = "textoo.txt"; // archivo de prueba
    procesarArchivoDeTexto(nombreArchivo);
    return 0;
}
