/*PROTOTIPO O FIRMA*/
#ifndef PAIS_H
#define PAIS_H

typedef struct
{
    int idPaisOrigen; //Primary Key
    char nombrePais[31];
    char continente[16];
    int codigoTelefonico;
    int isEmpty;

}ePais;

void InicializarListadoPaises(ePais listadoPaises[], int tamListaPaises);

void HarcodearListadoPaises(ePais listaPaises[]);

ePais BuscarPais(ePais listadoPaises[], int tamListaPaises, int idPais);

int BuscarIdMaximoPaisDisponible(ePais listadoPaises[], int tamListaPaises);

void MostrarListadoPaisesDisponibles(ePais listadoPaises[], int tamListaPaises);

#endif // PAIS_H
