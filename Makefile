programa: main.c reconocedor_automata.c
    gcc main.c reconocedor_automata.c -o programa

programa2: main2.c reconocedor_automata2.c
    gcc main2.c reconocedor_automata2.c -o programa2

test: tests.c main.c reconocedor_automata.c
    gcc main.c reconocedor_automata.c tests.c -o test

test2: tests.c main2.c reconocedor_automata2.c
    gcc main2.c reconocedor_automata2.c tests.c -o test2

clean:
    rm -f programa programa2 test test2 *.o
