/*PROTOTIPO O FIRMA*/
#include <stdio.h>

int MyGets(char* cadena, int longitud);

int esNumerica(char* cadena, int limite);

int getInt(int* pResultado);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

int esFlotante(char* cadena, int limite);

int getFloat(float* pResultado);

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);
