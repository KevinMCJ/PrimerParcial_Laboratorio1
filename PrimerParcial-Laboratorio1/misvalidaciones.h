/*PROTOTIPO O FIRMA*/
#ifndef MISVALIDACIONES_H
#define MISVALIDACIONES_H


/** \brief Realiza el pedido y carga de una cadena de acuerdo a un nombre o caracter de no mas de 15 caracteres.
 *
 * \param pCadena char* Direccion de memoria de la variable a cargar
 * \param mensaje char* Mensaje para el pedido de la cadena.
 * \param mensajeError char* Mensaje de error para el pedido de la cadena.
 * \param maxCaracteres int Maximo de caracteres permitidos en la cadena.
 * \param cantidadEspaciosPermitidos int Cantidad de espacios permitidos en la cadena.
 * \return int Retorna 0 si todo salio bien.
 *
 */
int GetString(char* pCadena, char* mensaje, char* mensajeError, int maxCaracteres, int cantidadEspaciosPermitidos);

/** \brief Realiza el pedido y carga de un caracter de confirmacion (SI O NO)
 *
 * \param mensaje[] char    Mensaje para el pedido de la cadena.
 * \param mensajeError[] char    Mensaje de error para el pedido de la cadena.
 * \return char Retorna el caracter de confirmacion cargado.
 *
 */
char GetConfirmCharacter(char mensaje[], char mensajeError[]);

char GetGender(char mensaje[], char mensajeError[]);

#endif
