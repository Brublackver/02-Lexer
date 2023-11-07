#regla para compilar el lexer
programa: main.c reconocedor_automata.c 
		gcc main.c reconocedor_automata.c -o programa

#regla para limpiar el programa
clean:
	    rm -f programa *.o

test: tests.c main.c reconocedor_automata.c 
		gcc main.c reconocedor_automata.c tests.c -o test

programa2: main2.c reconocedor_automata2.c
		gcc main2.c reconocedor_automata2.c -o programa2