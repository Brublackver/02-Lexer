#ifndef FUNCIONES2_H
#define FUNCIONES2_H

int T2(int estado_actual, int entrada);
int reconocedor_2(char entrada);
int pertenece2(char entrada,char lista[],int longitud_lista);
int parentesis2(int valor);
void armarTablaTokens2(char *leidos);
void lectorErrores(char *leidos);
#endif