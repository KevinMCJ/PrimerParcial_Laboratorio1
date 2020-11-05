/*PROTOTIPO O FIRMA*/
#ifndef MASCOTAS_H
#define MASCOTAS_H

typedef struct
{
    int id;
    char nombre[21];
    int edad;
    char sexo;
    char tipo[16];
    float peso;
    int idRaza; //Foreign Key
    int isEmpty;

}eMascota;

void InicializarListadoMascotas(eMascota listadoMascotas[], int tamListaMascotas);

void HardcodearListadoMascotas(eMascota listaMascotas[]);

int CantidadDeMascotasEnLaLista(eMascota listadoMascotas[], int tamListaMascotas);

int EliminarMascota(eMascota listadoMascotas[], int tamListaMascotas, int idAEliminar);

int BuscarMascotaPorID(eMascota listadoMascotas[], int tamListaMascotas, int id);

int BuscarEspacioLibreMascota(eMascota listadoMascotas[], int tamListaMascotas);

eMascota PedirDatosMascota(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListadoRazas, ePais listadoPaises[], int tamListaPaises);

int AltaDeMascota(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

int GenerarIDMascota(eMascota listadoMascotas[], int tamListaMascotas);

int ModificarMascota(eMascota listadoMascotas[], int tamListaMascotas, int idAModificar, eRaza listadoRazas[], int tamlistaRazas);

int BuscarTipoDeMascota(eMascota listadoMascotas[], int tamListaMascotas, char tipoIngresado[]);

int BorrarMascotasDeUnaRaza(eMascota listadoMascotas[], int tamListaMascotas, int idRazaABorrar);

void MostrarListadoPorTipoYPeso(eMascota listadoMascotas[], int tamListaMascotas);

#endif // MASCOTAS_H
