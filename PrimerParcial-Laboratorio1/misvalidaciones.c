#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "misvalidaciones.h"

int GetString(char* pCadena, char* mensaje, char* mensajeError, int maxCaracteres, int cantidadEspaciosPermitidos)
{
    int retorno;
    int i;
    int contadorEspacios;
    char bufferString[maxCaracteres]; //El tamaño del buffer de apoyo depende de la cantidad de caracteres que pasemos en el parametro.

    //RETORNO 1 COMO VALIDO 0 COMO INVALIDO.
    do
    {
        retorno = 1;

        contadorEspacios = 0; //En caso de error y que se ejecute otra iteracion el contador vuelve a iniciar en 0.

        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", bufferString);

        if(strlen(bufferString) > sizeof(bufferString))
        {
            retorno = 0;
        }
        else
        {
            for(i=0; i<strlen(bufferString); i++)
            {

                if(bufferString[i] == ' ')
                {
                    contadorEspacios++;
                }

                //EXCLUI TODA LA TABLA DEL CODIGO ASCII, MENOS LOS VALORES DE LAS LETRAS DEL ABECEDARIO EN MAYUSCULA , MINUSCULA Y EL ESPACIO (32).
                if(!((bufferString[i] >= 65 && bufferString[i] <= 90) || (bufferString[i] >= 97 && bufferString[i] <= 122) || bufferString[i] == 32) || contadorEspacios > cantidadEspaciosPermitidos)
                {
                    retorno = 0;
                    break;
                }
            }

        }

        if(retorno == 0)
        {
            printf("%s", mensajeError);
        }

    }while(retorno != 1);

    //Una vez obtenido un string valido a nuestros requerimientos, lo transformo a minusculas.
    strlwr(bufferString);

    //Convierto en mayuscula la primer letra y si hay un espacio, la que sigue despues de este.
    for(i=0; i<strlen(bufferString); i++)
    {
        if(i == 0)
        {
            bufferString[i] = toupper(bufferString[i]);
        }
        else if(isspace(bufferString[i]))
        {
            i++;
            bufferString[i] = toupper(bufferString[i]);
        }
    }

    //Finalmente le pasamos el string final al contenedor de la cadena deseada.
    strcpy(pCadena, bufferString);

    return retorno;
}

char GetConfirmCharacter(char mensaje[], char mensajeError[])
{
    char confirmCharacter;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &confirmCharacter);
    confirmCharacter = toupper(confirmCharacter);

    while(confirmCharacter != 'S' && confirmCharacter != 'N')
    {
        printf("%s", mensajeError);
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &confirmCharacter);
        confirmCharacter = toupper(confirmCharacter);
    }

    return confirmCharacter;
}

char GetGender(char mensaje[], char mensajeError[])
{
    char genderCaracter;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &genderCaracter);
    genderCaracter = toupper(genderCaracter);

    while(genderCaracter != 'F' && genderCaracter != 'M')
    {
        printf("%s", mensajeError);
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &genderCaracter);
        genderCaracter = toupper(genderCaracter);
    }

    return genderCaracter;
}

