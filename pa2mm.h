#ifndef __PA2M_H_
#define __PA2M_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define BLANCO "\x1b[37;1m"
#define VERDE "\x1b[32;1m"
#define ROJO "\x1b[31;1m"
#define AMARILLO "\x1b[33;1m"
#define NORMAL "\x1b[0m"

#define TILDE "✓"
#define CRUZ "✗"

int __pa2m_cantidad_de_pruebas_corridas = 0;
int __pa2m_cantidad_de_pruebas_fallidas = 0;
const char* __pa2m_prueba_actual = NULL;

void __pa2m_atajarse(void (*handler)(int)){
  signal(SIGABRT, handler);
  signal(SIGSEGV, handler);
  signal(SIGBUS, handler);
  signal(SIGILL, handler);
  signal(SIGFPE, handler);
}

void __pa2m_morir(int signum){
  if(__pa2m_prueba_actual)
    printf(ROJO "\n\nERROR MIENTRAS SE EJECUTABA LA PRUEBA: " AMARILLO "'%s'\n\n" BLANCO, __pa2m_prueba_actual);
  else printf(ROJO "\n\nFINALIZACION ANORMAL DE LAS PRUEBAS\n\n"BLANCO);
  fflush(stdout);
  __pa2m_atajarse(SIG_DFL);
}

#define pa2m_afirmar(afirmacion, descripcion) do {      \
    __pa2m_prueba_actual = descripcion;                 \
    __pa2m_atajarse(__pa2m_morir);                      \
    if (afirmacion) {                                   \
      printf( VERDE TILDE " ");                         \
    } else {                                            \
      __pa2m_cantidad_de_pruebas_fallidas++;            \
      printf( ROJO CRUZ " ");                           \
    }                                                   \
    printf(BLANCO "%s\n", __pa2m_prueba_actual);        \
    fflush(stdout);                                     \
    __pa2m_prueba_actual = NULL;                        \
    __pa2m_cantidad_de_pruebas_corridas++;              \
  }while(0);

void pa2m_nuevo_grupo(const char* descripcion){
  printf(AMARILLO "\n%s\n", descripcion);
  while(*(descripcion++)) printf("=");
  printf(BLANCO "\n");
}

int pa2m_mostrar_reporte() {
  printf(BLANCO "\n---------------------------------\n"
         "%i pruebas corridas, %i errores - %s\n" NORMAL,
         __pa2m_cantidad_de_pruebas_corridas,
         __pa2m_cantidad_de_pruebas_fallidas,
         __pa2m_cantidad_de_pruebas_fallidas == 0 ? "OK" : "D:");
  return __pa2m_cantidad_de_pruebas_fallidas;
}

#endif // __PA2M_H_
