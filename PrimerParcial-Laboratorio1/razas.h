/*PROTOTIPO O FIRMA*/
#ifndef RAZAS_H
#define RAZAS_H

typedef struct
{
    int idRaza; //Primary Key.
    char descripcion[31];
    char tamanio[11];
    int idPaisOrigen; //Foreign Key.
    int isEmpty;

}eRaza;

void InicializarListadoRazas(eRaza listadoRazas[], int tamListaRazas);

void HarcodearListadoRazas(eRaza listaRazas[]);

eRaza BuscarRaza(eRaza listadoRazas[], int tamListaRazas, int idRaza);

int BuscarEspacioLibreRaza(eRaza listadoRazas[], int tamlistaRazas);

eRaza PedirDatosRaza(eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

int AltaDeRaza(eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

void MostrarListadoRazasDisponibles(eRaza listadoRazas[], int tamListaRazas);

int GenerarIDRaza(eRaza listadoRazas[], int tamListaRazas);

int BuscarIdMaximoRazaDisponible(eRaza listadoRazas[], int tamListaRazas);

int BorrarRaza(eRaza listadoRazas[], int tamlistaRazas, int idRazaABorrar);

#endif // RAZAS_H
