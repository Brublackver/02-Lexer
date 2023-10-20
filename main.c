#include <stdio.h>
#include "reconocedor.h"
#include <string.h>

/*
struct error nuevoError(char *cadenaErronea){
    struct error nuevoError;
    int columnaa = strlen(cadenaErronea);
    nuevoError.columna = columnaa;
    nuevoError.caracter = cadenaErronea[columnaa];
    nuevoError.anterior = cadenaErronea[columnaa - 1];
    return nuevoError;
}
*/
int parentesis_control;//actua como pila para conotrolar el correcto uso de parentesis

int parentesis(int valor){parentesis_control = parentesis_control + valor;};


void procesarEntradaDeTexto(char *cadena) {//funcion que recibe entrada y evalua caracter por caracter
   
    // Abre el archivo en modo lectura
    //FILE *archivo = fopen(nombreArchivo, "r");


    //Si la entrada no es vacia, lee caracter por caracter
    char leidos[100] = "" ;
    if (cadena == NULL || cadena[0] == '\0') {
        printf("Cadena vacía.\n");
        return;
    }
    int estado_actual = 0;
    int i = 0;
    //char caracter;
    while (cadena[i] != '\0') {//asigna el caracter a la variable y trabaja con ella
      char caracter = cadena[i];

     if ((caracter == '\n' || caracter == '\r')){

       if ((estado_actual == 1 || estado_actual == 4 || estado_actual == 5 )&&(parentesis_control ==0)){
        //los valores de de aceptacion
                printf("ACEPTADA\n");
                break;
                estado_actual = 0;
               parentesis_control = 0;
             }else if (parentesis_control !=0 || estado_actual == -1){  
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


      /*
        if (estado_actual == -1) { // evalua si es correcto el proceso
            printf("RECHAZADA\n");
            break;
            estado_actual = 0;
            parentesis_control = 0;
        };*/  

        i++;
    int longitud = strlen(leidos);

    //evalua que no es exceda el numero de caracteres permitidos
    if (longitud < sizeof(leidos) - 1) {
        leidos[longitud] = caracter;
        leidos[longitud + 1] = '\0'; 
    } else {
        printf("Maximo de caracteres superado.\n");
    };
    

    };
    printf("estado actualllllllllllllllll: %d",estado_actual);
    armarTablaTokens(leidos);
    //fclose(archivo);

    

    return;
};

int main() {//funcion main, pide al usuario una entrada por consola
    //Por ahora, comento todo lo que tenga que ver con manejo de archivos por que todavia no es claro el formato del flujo de entrada
    parentesis_control = 0;
    char cadena[100]; 
    printf("Ingresa una expresion numerica valida, sin dejar espacios en blanco: ");
    fgets(cadena, sizeof(cadena), stdin);
   // const char *nombreArchivo = "textoo.txt"; // archivo de prueba
    procesarEntradaDeTexto(cadena);
    
    return 0;
}
