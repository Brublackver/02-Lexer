
#include <stdio.h>
#include <string.h>
#include "reconocedor2.h"
void procesarEntradaDeTexto2(char *cadena) {
    
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

       if ((estado_actual != 2 )){
        //los valores de de aceptacion
                printf("ACEPTADA\n");
                break;
                estado_actual = 0;
        
             }else{  
               printf("RECHAZADA\n");
               break;
               estado_actual = 0;
     
               };

               estado_actual = 0;
             
          
            continue;
        };

    printf("%d -> %c -> ", estado_actual, caracter);//imprime en pantalla el proceso
    estado_actual = T2(estado_actual, caracter);
    printf("%d\n", estado_actual);


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
armarTablaTokens2(leidos);

lectorErrores(leidos);

return;
}


int main() {//funcion main, pide al usuario una entrada por consola
    //Por ahora, comento todo lo que tenga que ver con manejo de archivos por que todavia no es claro el formato del flujo de entrada
  
    char cadena[100]; 
    printf("Ingresa una expresion numerica, sin dejar espacios en blanco: ");
    fgets(cadena, sizeof(cadena), stdin);
   // const char *nombreArchivo = "textoo.txt"; // archivo de prueba
    procesarEntradaDeTexto2(cadena);
    
    return 0;
}
