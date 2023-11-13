
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
int T(int estado_actual, char entrada);
//struct error nuevoError(char *cadenaErronea);
int reconocedor_(char entrada);
int pertenece(char entrada,char lista[],int longitud_lista);
int parentesis(int valor);
void armarTablaTokens(char *leidos);
void procesarEntradaDeTexto(char *cadena);
extern int parentesis_control;
struct error {
    char mensaje[100];
};

struct error nuevoError(const char *mensaje);
void agregarError(struct error err);

#endif
