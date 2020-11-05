/*PROTOTIPO O FIRMA*/
#ifndef VETERINARIA_H
#define VETERINARIA_H

void Menu();

void MostrarMascotaConRaza(eMascota unaMascota, eRaza unaRaza, ePais unPais);

void MostrarListadoMascotasConRazas(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

int OrdenarListadoPorPais(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

void MostrarListadoMascotaMismaRaza(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, int idRazaAMostrar, ePais listadoPaises[], int tamListaPaises);

void MostrarPaisDeOrigenMasMascotas(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

void MostrarMascotasConDatosPaisYRaza(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

int OrdenarListadoPorCodigoTelPais(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

int MostrarListadoPorTamanioYPeso(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises);

int BorrarRazaConMascotas(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas);

void LimpiarConsola();

#endif // VETERINARIA_H
