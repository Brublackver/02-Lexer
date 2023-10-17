
#ifndef FUNCIONES_H
#define FUNCIONES_H

int T(int estado_actual, int entrada);
int reconocedor_(char entrada);
int pertenece(char entrada,char lista[],int longitud_lista);
int parentesis(int valor);
void armarTablaTokens(char *leidos);
#endif
