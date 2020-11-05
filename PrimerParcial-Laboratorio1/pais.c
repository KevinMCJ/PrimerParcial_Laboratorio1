#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pais.h"
#include "razas.h"
#include "mascotas.h"
#include "veterinaria.h"

#include "misvalidaciones.h"
#include "utn.h"

#define OCUPADO 1
#define VACIO 0

void InicializarListadoPaises(ePais listadoPaises[], int tamListaPaises)
{
    int i;

    for(i=0; i<tamListaPaises; i++)
    {
        listadoPaises[i].isEmpty = VACIO;
    }
}

void HarcodearListadoPaises(ePais listaPaises[])
{
    int arrayIDPaisOrigen[5] = {50, 51, 52, 53, 54};
    char arrayNombrePais[5][31] = {"Argentina", "Alemania", "Belgica", "Tailandia", "Persia"};
    char arrayContinente[5][16] = {"America", "Europa", "Europa", "Asia", "Asia"};
    int arrayCodigoTelefonico[5] = {54, 49, 32, 66, 98};

    int i;

    for(i=0; i<5; i++)
    {
        listaPaises[i].idPaisOrigen = arrayIDPaisOrigen[i];
        listaPaises[i].codigoTelefonico = arrayCodigoTelefonico[i];
        strcpy(listaPaises[i].nombrePais, arrayNombrePais[i]);
        strcpy(listaPaises[i].continente, arrayContinente[i]);
        listaPaises[i].isEmpty = OCUPADO;
    }

}

ePais BuscarPais(ePais listadoPaises[], int tamListaPaises, int idPais)
{
    ePais auxiliarPais;
    int i;

    //Recibe un id que busca en el listado de razas y si coincide, nos devuelve toda la informacion de una raza.
    for(i=0; i<tamListaPaises; i++)
    {
        if(idPais == listadoPaises[i].idPaisOrigen)
        {
            auxiliarPais = listadoPaises[i];
            break;
        }
    }

    return auxiliarPais;
}

int BuscarIdMaximoPaisDisponible(ePais listadoPaises[], int tamListaPaises)
{
    int idMaximoPais;
    int i;

    for(i=0; i<tamListaPaises; i++)
    {
        if(i==0 || (listadoPaises[i].idPaisOrigen > idMaximoPais && listadoPaises[i].isEmpty == OCUPADO))
        {
            idMaximoPais = listadoPaises[i].idPaisOrigen;
        }
    }

    return idMaximoPais;
}

void MostrarListadoPaisesDisponibles(ePais listadoPaises[], int tamListaPaises)
{
    int i;

    printf("\n-Listado de paises disponibles.\n\n");
    printf("----------------------------\n");
    printf("| ID PAIS |     PAIS       |\n");
    printf("----------------------------\n");

    for(i=0; i<tamListaPaises; i++)
    {
        if(listadoPaises[i].isEmpty == OCUPADO)
        {
            printf("     %-7d  %-10s\n", listadoPaises[i].idPaisOrigen , listadoPaises[i].nombrePais);
        }
    }
}
