#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "misvalidaciones.h"
#include "pais.h"
#include "razas.h"
#include "mascotas.h"

#include "veterinaria.h"

#define TAM_MASCOTAS 10
#define TAM_RAZAS 20
#define TAM_PAISES 10

/*-PRIMER PARCIAL. LABORATORIO 1 - KEVIN MAMANI 1°B*/

int main()
{
    eMascota listadoPrincipalMascotas[TAM_MASCOTAS];
    eRaza listadoPrincipalRazas[TAM_RAZAS];
    ePais listadoPrincipalPaises[TAM_PAISES];

    int opcionElegida;
    int idSolicitado;
    int mascotasEnLista;

    InicializarListadoMascotas(listadoPrincipalMascotas, TAM_MASCOTAS);
    InicializarListadoRazas(listadoPrincipalRazas, TAM_RAZAS);
    InicializarListadoPaises(listadoPrincipalPaises, TAM_PAISES);

    HarcodearListadoRazas(listadoPrincipalRazas);
    HardcodearListadoMascotas(listadoPrincipalMascotas);
    HarcodearListadoPaises(listadoPrincipalPaises);

    do
    {
        mascotasEnLista = CantidadDeMascotasEnLaLista(listadoPrincipalMascotas, TAM_MASCOTAS);

        Menu();

        utn_getNumero(&opcionElegida, "\n-Que desea hacer?: ", "\n.Opcion Invalida!", 1, 13);

        switch(opcionElegida)
        {
            case 1:
                if(mascotasEnLista != 0)
                {
                    MostrarListadoMascotasConRazas(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES);
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria a mostrar.\n\n");
                }
                break;
            case 2:
                if(mascotasEnLista != 0)
                {
                    MostrarMascotasConDatosPaisYRaza(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES);
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria a mostrar.\n\n");
                }
                break;
            case 3:
                if(mascotasEnLista != 0)
                {
                    MostrarListadoPorTamanioYPeso(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES);
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria a mostrar.\n\n");
                }
                break;
            case 4:
                if(mascotasEnLista != 0)
                {
                    MostrarListadoPorTipoYPeso(listadoPrincipalMascotas, TAM_MASCOTAS);
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria para mostrar datos.\n\n");
                }
                break;
            case 5:
                MostrarListadoRazasDisponibles(listadoPrincipalRazas, TAM_RAZAS);
                if(AltaDeMascota(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES) != -1)
                {
                    printf("\n-Alta realizada correctamente.\n\n");
                }else{
                    printf("\n-No hay mas espacio en la lista.\n\n");
                }
                break;
            case 6:
                if(AltaDeRaza(listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES) != -1)
                {
                    printf("\n-Alta realizada correctamente.\n\n");
                }else{
                    printf("\n-No hay mas espacio en la lista.\n\n");
                }
                break;
            case 7:
                if(mascotasEnLista != 0)
                {
                    MostrarListadoMascotasConRazas(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES);

                    utn_getNumero(&idSolicitado, "\n-Ingrese el ID de la mascota a modificar: ", "\n.ID Invalida!.", 1, 50000);

                    switch(ModificarMascota(listadoPrincipalMascotas, TAM_MASCOTAS, idSolicitado, listadoPrincipalRazas, TAM_RAZAS))
                    {
                        case 1: // El usuario realizo una modificacion.
                            printf("\n-Modificacion realizada correctamente.\n\n");
                            break;
                        case 0: // El usuario cancelo la modificacion.
                            printf("\n-Operacion cancelada correctamente.\n\n");
                            break;
                        default: // -1 (El ID escrito por el usuario no fue encontrado en la lista)
                            printf("\n-ID no encontrada en la lista, cancelando operacion..\n\n");
                    }
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria para modificar.\n\n");
                }
                break;
            case 8:
                if(mascotasEnLista != 0)
                {
                    MostrarListadoMascotasConRazas(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES);

                    utn_getNumero(&idSolicitado, "\n-Ingrese el ID de la mascota a eliminar: ", "\n.ID Invalida!.", 1, 50000);

                    switch(EliminarMascota(listadoPrincipalMascotas, TAM_MASCOTAS, idSolicitado))
                    {
                        case 1: // El usuario confirmo la baja.
                            printf("\n-Baja realizada correctamente.\n\n");
                            break;
                        case 0: // El usuario denego la baja.
                            printf("\n-Operacion cancelada correctamente.\n\n");
                            break;
                        default: // -1 (El ID escrito por el usuario no fue encontrado en la lista)
                            printf("\n-ID no encontrada en la lista, cancelando operacion..\n\n");
                    }
                }else{
                    printf("\n-No hay mascotas registradas en la veterina para dar de baja.\n\n");
                }
                break;
            case 9:
                MostrarListadoRazasDisponibles(listadoPrincipalRazas, TAM_RAZAS);

                if(BorrarRazaConMascotas(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS) != -1)
                {   //CONFIRMO BORRADO
                    printf("\n-Raza y mascotas de la misma eliminados correctamente.\n\n");
                }else{
                    printf("\n-Operacion cancelada correctamente.\n\n"); //DENEGO EL BORRADO.
                }
                break;
            case 10:
                if(mascotasEnLista != 0 && OrdenarListadoPorPais(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES) != -1)
                {
                    printf("\n-Listado ordenado correctamente.\n\n");
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria para ordenar.\n\n");
                }
                break;
            case 11:
                if(mascotasEnLista != 0 && OrdenarListadoPorCodigoTelPais(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES) != -1)
                {
                    printf("\n-Listado ordenado correctamente.\n\n");
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria para ordenar.\n\n");
                }
                break;
            case 12:
                if(mascotasEnLista != 0)
                {
                    MostrarPaisDeOrigenMasMascotas(listadoPrincipalMascotas, TAM_MASCOTAS, listadoPrincipalRazas, TAM_RAZAS, listadoPrincipalPaises, TAM_PAISES);
                }else{
                    printf("\n-No hay mascotas registradas en la veterinaria.\n\n");
                }
                break;
            case 13:
                printf("\n.Gracias por utilizar el programa.\n");
                break;
        }

        if(opcionElegida != 13)
        {
            LimpiarConsola();
        }

    }while(opcionElegida != 13);

    return 0;
}
