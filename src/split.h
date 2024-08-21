#ifndef SPLIT_H_
#define SPLIT_H_

#include <stdlib.h>

struct Partes {
    size_t cantidad;
    char** string;
};

/**
 * Recibe un string y un separador y devuelve un struct con la informacion de los strings separados.
 */
struct Partes* dividir_string(const char* string, char separador);

/**
 * Libera TODA la memoria utilizada por el struct Partes.
 */
void liberar_partes(struct Partes* partes);

#endif // SPLIT_H_
