#include <stdio.h>
#include "reconocedor2.h"


int T2(int estado_actual, char entrada) {//funcion del automata finito deterministico,(tabla de transiciones)
  
    int tabla[10][5] = {
    /*0*/{1,1,1,2},
    /*1*/{1,1,1,2},
   /*2*/{2,2,2,2}
    }; 

  return tabla[estado_actual][reconocedor_2(entrada)];
}


int pertenece2(char entrada,char lista[],int longitud_lista){//funcion para evaluar a que lenguaje peretenece cada caracter
    for (int i = 0; i < longitud_lista; i++) {
        if (entrada == lista[i]) {
            return 1;  // El carácter se encuentra en la lista
        }
    }
    return 0;
};

int reconocedor_2(char entrada) {// funcion que reconoce el alfabeto utilizado
   char digitos[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
   char operadores[] = {'+', '*', '-','/'};
   char parentesis[] = {'(',')'};
 
   if (pertenece2(entrada,digitos,10)==1) {return 0; }
   else if (pertenece2(entrada,operadores,4)==1) {return 1;} 
   else if (pertenece2(entrada,parentesis,2)==1) {return 2;}
   else{return 3;}
}



//auxiliar para reconocer token
char* auxTabla2(char carac){
    if (reconocedor_2(carac)== 0){return "digito";}
    else if (reconocedor_2(carac)== 1){return "operador";}
    else if(reconocedor_2(carac)== 2){return "carac. puntuacion";}
    else{return "desconocido";}

};


void armarTablaTokens2(char *leidos) {
    int x = 0;
    printf("--------------------\n \n");
    printf("Tabla de tokens:\n \n");
    printf("|| CARACTER ||    TOKEN             ||\n");
    while (leidos[x] != '\0') {
        char carac = leidos[x];
        printf("||%10c||%20s", carac, auxTabla2(carac));
        printf("  ||\n");
        x++;
    }
}

void lectorErrores2(char *leidos){
int z = 0;
printf("ERRORES ENCONTRADOS:   \n");

    while(leidos[z] != '\0'){
 
      char caracter = leidos[z];
      if (reconocedor_2(caracter)== 3){
        printf("error en la columna %d, %c no pertenece al lenguaje\n\n",z+1,caracter);
      }
      z++;
    }


}