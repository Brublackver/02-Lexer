#ifndef RECONOCEDOR2_H
#define RECONOCEDOR2_H

int T2(int estado_actual, char entrada);
int reconocedor_2(char entrada);
int pertenece2(char entrada,char lista[],int longitud_lista);
int parentesis2(int valor);
void armarTablaTokens2(char *leidos);
void lectorErrores(char *leidos);
void procesarEntradaDeTexto2(char *cadena);
extern int parentesis_control;

#endif