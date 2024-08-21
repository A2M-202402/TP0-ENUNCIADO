#include "pa2mm.h"
#include "src/split.h"

#include "string.h"
#include <stdbool.h>

void partirUnStringNuloResultaEnCeroPartes()
{
    struct Partes* partes = dividir_string(NULL, ',');
    pa2m_afirmar(partes->cantidad == 0, "Partir un string nulo resulta en cero partes");
    liberar_partes(partes);
}

void partirUnStringVacioResultaEnUnaParteVacia()
{
    struct Partes* partes = dividir_string("", ',');
    pa2m_afirmar(partes->cantidad == 1, "Partir un string vacio resulta en una parte vacia");
    pa2m_afirmar(strcmp(partes->string[0], "") == 0, "La primera parte es vacia");
    liberar_partes(partes);
}

void partirUnStringCondosPartesSeparadasPorComaResultaEnDosPartes()
{
    struct Partes* partes = dividir_string("hola,mundo", ',');
    pa2m_afirmar(partes->cantidad == 2, "Partir un string con dos partes separadas por coma resulta en dos partes");
    pa2m_afirmar(strcmp(partes->string[0], "hola") == 0, "La primera parte es 'hola'");
    pa2m_afirmar(strcmp(partes->string[1], "mundo") == 0, "La segunda parte es 'mundo'");
    liberar_partes(partes);
}

void partirUnStringConTresPartesSeparadasPorComaResultaEnTresPartes()
{
    struct Partes* partes = dividir_string("hola,mundo,como", ',');
    pa2m_afirmar(partes->cantidad == 3, "Partir un string con tres partes separadas por coma resulta en tres partes");
    pa2m_afirmar(strcmp(partes->string[0], "hola") == 0, "La primera parte es 'hola'");
    pa2m_afirmar(strcmp(partes->string[1], "mundo") == 0, "La segunda parte es 'mundo'");
    pa2m_afirmar(strcmp(partes->string[2], "como") == 0, "La tercera parte es 'como'");
    liberar_partes(partes);
}

void partirUnStringConUnaParteSinSeparadorResultaEnUnaParte()
{
    struct Partes* partes = dividir_string("hola", ',');
    pa2m_afirmar(partes->cantidad == 1, "Partir un string con una parte sin separador resulta en una parte");
    pa2m_afirmar(strcmp(partes->string[0], "hola") == 0, "La primera parte es 'hola'");
    liberar_partes(partes);
}

void partirUnStringDeSeparadoresResultaEnPartesVacias()
{
    struct Partes* partes = dividir_string(",,,", ',');
    pa2m_afirmar(partes->cantidad == 4, "Partir un string de separadores resulta en partes vacias");
    pa2m_afirmar(strcmp(partes->string[0], "") == 0, "La primera parte es vacia");
    pa2m_afirmar(strcmp(partes->string[1], "") == 0, "La segunda parte es vacia");
    pa2m_afirmar(strcmp(partes->string[2], "") == 0, "La tercera parte es vacia");
    pa2m_afirmar(strcmp(partes->string[3], "") == 0, "La cuarta parte es vacia");
    liberar_partes(partes);
}

int main(){

    pa2m_nuevo_grupo("Split de strings vacíos o nulos");
    partirUnStringNuloResultaEnCeroPartes();
    partirUnStringVacioResultaEnUnaParteVacia();

    pa2m_nuevo_grupo("Split de strings separados por comas");
    partirUnStringCondosPartesSeparadasPorComaResultaEnDosPartes();
    partirUnStringConTresPartesSeparadasPorComaResultaEnTresPartes();
    partirUnStringConUnaParteSinSeparadorResultaEnUnaParte();
    
    pa2m_nuevo_grupo("Split de un strings solo de separadores");
    partirUnStringDeSeparadoresResultaEnPartesVacias();

    return pa2m_mostrar_reporte();
}
