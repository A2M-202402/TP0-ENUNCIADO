CFLAGS=-ggdb -O0 -std=c99 -Wall -Wconversion -Wtype-limits -Werror -I src
VFLAGS=--leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2

valgrind: pruebas
	valgrind $(VFLAGS) ./pruebas 2>&1

pruebas: clean pruebas.c src/split.h src/split.c
	gcc $(CFLAGS) -o pruebas pruebas.c src/split.c 2>&1

clean:
	rm -rf pruebas 2>&1
