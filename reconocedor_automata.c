#include <stdio.h>
#include "reconocedor.h"

int pertenece(char entrada,char lista[],int longitud_lista){//funcion para evaluar a que lenguaje peretenece cada caracter
    for (int i = 0; i < longitud_lista; i++) {
        if (entrada == lista[i]) {
            return 1;  // El carácter se encuentra en la lista
        }
    }
    return 0;
}
int reconocedor_(char entrada) {// funcion que reconoce el alfabeto utilizado
   char digitos[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
   char operadores[] = {'+', '*', '-','/'};
   char parentesis_abierto = '(';
   char parentesis_cerrado = ')';
   if (pertenece(entrada,digitos,10)==1) {return 0; }
   else if (pertenece(entrada,operadores,4)==1) {return 1;} 
   else if (entrada == parentesis_abierto) {return 2;}
   else if (entrada == parentesis_cerrado) {return 3;}
   else{return 4;}
}

int T(int estado_actual, int entrada) {//funcion del automata finito deterministico,(tabla de transiciones)
  
    int tabla[10][5] = {
    /*0*/{8,-1,2,-1,-1},
    /*1*/{1,6,-1,-1,-1},
    /*2*/{7,-1,2,-1,-1},
    /*3*/{4,-1,2,-1,-1},
    /*4*/{4,3,-1,5,-1},
    /*5*/{-1,3,-1,5,-1},
    /*6*/{1,-1,2,-1,-1},
    /*7*/{7,3,-1,-1,-1},
    /*8*/{8,9,-1,-1,-1},
    /*9*/{1,-1,2,-1,-1}
    }; 
  if (reconocedor_(entrada) == 2){parentesis(+1);}else if(reconocedor_(entrada) == 3){parentesis(-1);}

  return tabla[estado_actual][reconocedor_(entrada)];
}

