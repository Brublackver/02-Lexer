#include <stdio.h>
#include "reconocedor.h"
#include "reconocedor2.h"

void test_procesarEntradaDeTexto() {
    printf("Iniciando pruebas para procesarEntradaDeTexto...\n");
    char* prueba1 = "6*7*(11-1)\n";
    char* prueba2 = "2+2*2\n";
    char* prueba3 = "(6+2)*3\n";

    procesarEntradaDeTexto(prueba1);
    procesarEntradaDeTexto(prueba2);
    procesarEntradaDeTexto(prueba3);
}

void test_procesarEntradaDeTexto2() {
    printf("Iniciando pruebas para procesarEntradaDeTexto2...\n");
    char* prueba1 = "6*7*(11-1)\n";
    char* prueba2 = "2+2*2\n";
    char* prueba3 = "(6+2)*3\n";

    procesarEntradaDeTexto2(prueba1);
    procesarEntradaDeTexto2(prueba2);
    procesarEntradaDeTexto2(prueba3);
}
