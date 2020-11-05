#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int MyGets(char* cadena, int longitud)
{

    int retorno;
    char bufferString[4096];

    retorno = -1;

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
            }
            if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena, bufferString, longitud);
                retorno = 0;
            }
        }
    }

    return retorno;
}

/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if(	pResultado != NULL &&
        MyGets(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atoi(bufferString); //ATOI CONVIERTE UN STRING A INT.

	}

    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
int esNumerica(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] != '\0'; i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
        }
		//CONTINUE
	}
	//BREAK
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno = -1;
	int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError!= NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);

            if( getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo )
            {
                retorno = 0;
                *pResultado = bufferInt;
                break;
            }

            printf("%s", mensajeError);

        }while(retorno != 0);

    }

	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if(	pResultado != NULL &&
        MyGets(bufferString,sizeof(bufferString)) == 0 &&
    	esFlotante(bufferString,sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atof(bufferString); //ATOF CONVIERTE UN STRING YA VALIDADO A FLOAT.

	}

    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
int esFlotante(char* cadena, int limite)
{
	int retorno = 1;
	int i;
	int contadorPuntos = 0;

	if(cadena != NULL && limite > 0)
    {
        for(i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
            {
                continue;
            }
            if(cadena[i] > '9' || cadena[i] < '0')
            {
                if(cadena[i] == '.' && contadorPuntos == 0)
                {
                    contadorPuntos++;
                }else{
                    retorno = 0;
                    break;
                }
            }
            //CONTINUE
        }
        //BREAK
    }

	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	int retorno = -1;
	float bufferFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError!= NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);

            if( getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo )
            {
                retorno = 0;
                *pResultado = bufferFloat;
                break;
            }

            printf("%s", mensajeError);

        }while(retorno != 0);

    }

	return retorno;
}
