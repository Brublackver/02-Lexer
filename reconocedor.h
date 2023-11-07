
#ifndef FUNCIONES_H
#define FUNCIONES_H

/*
struct error {
int  columna;
char caracter;
char anterior;

};
*/
//extern struct error errores[];
int T(int estado_actual, int entrada);
//struct error nuevoError(char *cadenaErronea);
int reconocedor_(char entrada);
int pertenece(char entrada,char lista[],int longitud_lista);
int parentesis(int valor);
void armarTablaTokens(char *leidos);
#endif
