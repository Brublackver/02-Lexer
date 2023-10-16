#regla para compilar el lexer
programa: main.c reconocedor_automata.c 
		gcc main.c reconocedor_automata.c -o programa

#regla para limpiar el programa
clean:
	    rm -f programa *.o