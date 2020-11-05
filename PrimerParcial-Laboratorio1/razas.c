#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pais.h"
#include "razas.h"
#include "misvalidaciones.h"
#include "utn.h"

#define OCUPADO 1
#define VACIO 0

void InicializarListadoRazas(eRaza listadoRazas[], int tamListaRazas)
{
    int i;

    for(i=0; i<tamListaRazas; i++)
    {
        listadoRazas[i].isEmpty = VACIO;
    }
}

void HarcodearListadoRazas(eRaza listaRazas[])
{
    int idRaza[6] = {10, 11, 12, 13, 14, 15}; //Primary Key
    char arrayDescripcion[6][31] = {"Siames", "Doberman", "Persa", "Pastor Belga", "Dogo Argentino", "Pastor Aleman"};
    char arrayTamanio[6][11] = {"Chico", "Grande", "Mediano", "Grande", "Grande", "Grande"};
    int arrayIDPaisDeOrigen[6] = {53, 51, 54, 52, 50, 51}; //Foreign Key

    int i;

    for(i=0; i<6; i++)
    {
        listaRazas[i].idRaza = idRaza[i];
        strcpy(listaRazas[i].descripcion, arrayDescripcion[i]);
        strcpy(listaRazas[i].tamanio, arrayTamanio[i]);
        listaRazas[i].idPaisOrigen = arrayIDPaisDeOrigen[i];
        listaRazas[i].isEmpty = OCUPADO;
    }

}

int BuscarEspacioLibreRaza(eRaza listadoRazas[], int tamlistaRazas)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamlistaRazas; i++)
    {
        if(listadoRazas[i].isEmpty == VACIO)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

eRaza BuscarRaza(eRaza listadoRazas[], int tamListaRazas, int idRaza)
{
    eRaza auxiliarRaza;
    int i;

    //Recibe un id que busca en el listado de razas y si coincide, nos devuelve toda la informacion de una raza.
    for(i=0; i<tamListaRazas; i++)
    {
        if(idRaza == listadoRazas[i].idRaza)
        {
            auxiliarRaza = listadoRazas[i];
            break;
        }
    }

    return auxiliarRaza;
}

int AltaDeRaza(eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    int retorno = -1;
    int indiceLibre;

    indiceLibre = BuscarEspacioLibreRaza(listadoRazas, tamListaRazas);

    if(indiceLibre != -1)
    {
        retorno = 0;
        listadoRazas[indiceLibre] = PedirDatosRaza(listadoRazas, tamListaRazas, listadoPaises, tamListaPaises);
    }

    return retorno;
}

void MostrarListadoRazasDisponibles(eRaza listadoRazas[], int tamListaRazas)
{
    int i;

    printf("\n-Listado de razas disponibles.\n\n");
    printf("----------------------------\n");
    printf("| ID RAZA |     RAZA       |\n");
    printf("----------------------------\n");

    for(i=0; i<tamListaRazas; i++)
    {
        if(listadoRazas[i].isEmpty == OCUPADO)
        {
            printf("     %-7d  %-10s\n", listadoRazas[i].idRaza , listadoRazas[i].descripcion);
        }
    }
}

int GenerarIDRaza(eRaza listadoRazas[], int tamListaRazas)
{
    int i;
    int id = 10; //El id inicial que nosotros establecimos para la lista de razas.

    for(i=0; i<tamListaRazas; i++)
    {
        while(id == listadoRazas[i].idRaza || (id < listadoRazas[i].idRaza && listadoRazas[i].isEmpty == OCUPADO))
        {
            id++;
        }
    }

    return id;
}

int BuscarIdMaximoRazaDisponible(eRaza listadoRazas[], int tamListaRazas)
{
    int idMaximoRaza;
    int i;

    for(i=0; i<tamListaRazas; i++)
    {
        if(i==0 || (listadoRazas[i].idRaza > idMaximoRaza && listadoRazas[i].isEmpty == OCUPADO))
        {
            idMaximoRaza = listadoRazas[i].idRaza;
        }
    }

    return idMaximoRaza;
}

eRaza PedirDatosRaza(eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    eRaza miRaza;
    int idMaximoPaisDisponible;
    int eleccionTamanio;

    idMaximoPaisDisponible = BuscarIdMaximoPaisDisponible(listadoPaises, tamListaPaises);

    miRaza.idRaza = GenerarIDRaza(listadoRazas, tamListaRazas);

    GetString(miRaza.descripcion, "\n-Ingrese una raza: ", "\n.Error! Solo letras, a lo sumo un espacio y MAX: 15 caracteres.", 15, 1);

    utn_getNumero(&eleccionTamanio, "\n-Ingrese el numero correspondiente al tamanio de la raza.\n\n 1.Chico -- 2.Mediano -- 3.Grande : ", "\n.ERROR! Eliga el numero correspondiente al tamanio de la raza.", 1, 3);

    switch(eleccionTamanio)
    {
        case 1:
            strcpy(miRaza.tamanio, "Chico");
            break;
        case 2:
            strcpy(miRaza.tamanio, "Mediano");
            break;
        default: //3
            strcpy(miRaza.tamanio, "Grande");
    }

    MostrarListadoPaisesDisponibles(listadoPaises, tamListaPaises);

    utn_getNumero(&miRaza.idPaisOrigen, "\n-Ingrese el numero perteneciente al pais de origen de la raza: ", "\n.Error pais invalido! Solo ingrese el numero correspondiente.", 50, idMaximoPaisDisponible);

    miRaza.isEmpty = OCUPADO;

    return miRaza;
}

int BorrarRaza(eRaza listadoRazas[], int tamlistaRazas, int idRazaABorrar)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamlistaRazas; i++)
    {
        if(listadoRazas[i].isEmpty == OCUPADO && listadoRazas[i].idRaza == idRazaABorrar)
        {
            retorno = 0;
            listadoRazas[i].isEmpty = VACIO;
        }
    }

    return retorno;
}
