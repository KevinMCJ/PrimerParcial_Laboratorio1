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

void InicializarListadoMascotas(eMascota listadoMascotas[], int tamListaMascotas)
{
    int i;

    for(i=0; i<tamListaMascotas; i++)
    {
        listadoMascotas[i].isEmpty = VACIO;
    }
}

void HardcodearListadoMascotas(eMascota listaMascotas[])
{
    int arrayID[7] = {100, 101, 102, 103, 104, 105, 106};
    char arrayNombre[7][21] = {"Kiara", "Hulk", "Pacho", "Argos", "Luna", "Thor", "Delfi"};
    char arraySexo[7] = {'F', 'M', 'M', 'M', 'F', 'M', 'F'};
    char arrayTipo[7][16] = {"Gato", "Perro", "Gato", "Perro", "Perro", "Perro", "Gato"};
    int arrayEdad[7] = {4, 10, 6, 5, 3, 6, 3};
    float arrayPeso[7] = {3.8, 13.5, 4.3, 16.68, 14.22, 42.32, 5.90}; //Nuevo atributo peso.
    int idRaza[7] = {10, 11, 12 , 13, 13, 14, 10}; //Foreign Key

    int i;

    for(i=0; i<7; i++)
    {
        listaMascotas[i].id = arrayID[i];
        strcpy(listaMascotas[i].nombre, arrayNombre[i]);
        strcpy(listaMascotas[i].tipo, arrayTipo[i]);
        listaMascotas[i].sexo = arraySexo[i];
        listaMascotas[i].edad = arrayEdad[i];
        listaMascotas[i].peso = arrayPeso[i];
        listaMascotas[i].idRaza = idRaza[i];
        listaMascotas[i].isEmpty = OCUPADO;
    }

}

int CantidadDeMascotasEnLaLista(eMascota listadoMascotas[], int tamListaMascotas)
{
    int i;
    int contadorMascotas;

    contadorMascotas = 0;

    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            contadorMascotas++;
        }
    }

    return contadorMascotas;
}

int BuscarMascotaPorID(eMascota listadoMascotas[], int tamListaMascotas, int id)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamListaMascotas; i++)
    {
        if(id == listadoMascotas[i].id && listadoMascotas[i].isEmpty == OCUPADO)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int EliminarMascota(eMascota listadoMascotas[], int tamListaMascotas, int idAEliminar)
{
    char confirmacion;
    int retorno = -1;

    //El "ID a eliminar" va a tomar el valor del indice en la lista de la mascota a dar de baja.
    idAEliminar = BuscarMascotaPorID(listadoMascotas, tamListaMascotas, idAEliminar);
    //Le pasamos como parametro el id a encontrar , si no lo encuentra en la lista retorna -1.

    if(idAEliminar != -1)
    {
        //Le solicitamos al usuario la confirmacion de la baja.
        confirmacion = GetConfirmCharacter("\n-Esta seguro de que desea eliminar a la mascota de la lista? S / N : ", ".Error! Ingrese S o N.\n");

        //Si el usuario confirmo la baja, decimos que todo salio bien con un 1.
        if(confirmacion == 'S')
        {
            retorno = 1;
            listadoMascotas[idAEliminar].isEmpty = VACIO;
        }else //Si se nego retornamos un 0.
        {
            retorno = 0;
        }
    }

    return retorno;
}

eMascota PedirDatosMascota(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListadoRazas, ePais listadoPaises[], int tamListaPaises)
{
    int numeroTipo;
    int idMaximoRazaDisponible;
    eMascota unaMascota;

    //ID maximo a aceptar en el ingreso de la raza a seleccionar.
    idMaximoRazaDisponible = BuscarIdMaximoRazaDisponible(listadoRazas, tamListadoRazas);

    unaMascota.id = GenerarIDMascota(listadoMascotas, tamListaMascotas);

    utn_getNumero(&unaMascota.idRaza, "\n-Ingrese el numero perteneciente a la raza de su mascota: ", "\n.Error raza invalida! Solo ingrese el numero correspondiente.", 10, idMaximoRazaDisponible);

    GetString(unaMascota.nombre, "\n-Ingrese el nombre de la mascota: ", "\n.Nombre invalido! Solo letras, a lo sumo un espacio y max: 15 caracteres.", 15, 1);

    unaMascota.sexo = GetGender("\n-Ingrese el sexo de la mascota F | M : ", "\n.Sexo invalido! Solo ingrese F o M.");

    utn_getNumero(&unaMascota.edad, "\n-Ingrese la edad de la mascota: ", "\n.Edad invalida! Min: 0 Max: 20.", 0, 20);

    utn_getNumero(&numeroTipo, "\n-Ingrese el numero correspondiente al tipo de la mascota\n\n # 1.Gato ---  2.Perro -- 3.Raro: ", "\n.Tipo invalido! Ingrese 1, 2 o 3.", 1, 3);

    switch(numeroTipo)
    {
        case 1:
            utn_getNumeroFlotante(&unaMascota.peso, "\n-Ingrese el peso de la mascota en kilos: ", "\n.Peso Invalido! Ingrese un numero valido (Un gato no debe pesar mas de 13 kilos).", 0, 13);
            strcpy(unaMascota.tipo, "Gato");
            break;
        case 2:
            utn_getNumeroFlotante(&unaMascota.peso, "\n-Ingrese el peso de la mascota en kilos: ", "\n.Peso Invalido! Ingrese un numero valido (Un perro no debe pesar mas de 90 kilos).", 0, 90);
            strcpy(unaMascota.tipo, "Perro");
            break;
        default: //Raro
            utn_getNumeroFlotante(&unaMascota.peso, "\n-Ingrese el peso de la mascota en kilos: ", "\n.Peso Invalido! Ingrese un numero valido (Peso no mayor a 150kg).", 0, 150);
            strcpy(unaMascota.tipo, "Raro");
    }

    MostrarListadoMascotaMismaRaza(listadoMascotas, tamListaMascotas, listadoRazas, tamListadoRazas, unaMascota.idRaza, listadoPaises, tamListaPaises);

    unaMascota.isEmpty = OCUPADO;

    return unaMascota;
}

int AltaDeMascota(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    int retorno = -1;
    int indiceLibre;

    indiceLibre = BuscarEspacioLibreMascota(listadoMascotas, tamListaMascotas);

    if(indiceLibre != -1)
    {
        retorno = 0;
        listadoMascotas[indiceLibre] = PedirDatosMascota(listadoMascotas, tamListaMascotas, listadoRazas, tamListaRazas, listadoPaises, tamListaPaises);
    }

    return retorno;
}

int BuscarEspacioLibreMascota(eMascota listadoMascotas[], int tamListaMascotas)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == VACIO)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int GenerarIDMascota(eMascota listadoMascotas[], int tamListaMascotas)
{
    int i;
    int id = 100; //El id inicial que nosotros establecimos para la lista de mascotas.

    for(i=0; i<tamListaMascotas; i++)
    {
        while(id == listadoMascotas[i].id || (id < listadoMascotas[i].id && listadoMascotas[i].isEmpty == OCUPADO))
        {
            id++;
        }
    }

    return id;
}

int ModificarMascota(eMascota listadoMascotas[], int tamListaMascotas, int idAModificar, eRaza listadoRazas[], int tamlistaRazas)
{
    int numeroTipo;
    int idMaximoRazaDisponible;
    int retorno = -1;
    int opcionElegida;

    //ID maximo a aceptar en el ingreso de la raza a seleccionar.
    idMaximoRazaDisponible = BuscarIdMaximoRazaDisponible(listadoRazas, tamlistaRazas);

    //El "ID a modificar" va a tomar el valor del indice en la lista de la mascota a modificar.
    idAModificar = BuscarMascotaPorID(listadoMascotas, tamListaMascotas, idAModificar);
    //Si no lo encuentra en la lista retorna -1

    if(idAModificar != -1)
    {
        printf("\n  MODIFICAR\n  ---------");
        printf("\n  1.Nombre\n  2.Edad\n  3.Sexo\n  4.Tipo\n  5.Raza\n  6.CANCELAR\n");

        utn_getNumero(&opcionElegida, "\n-Que desea modificar?: ", "\n.Opcion Invalida! Ingrese un numero valido entre las opciones.", 1, 6);

        switch(opcionElegida)
        {
            case 1:
                GetString(listadoMascotas[idAModificar].nombre, "\n-Ingrese el nuevo nombre de la mascota: ", "\n.Nombre invalido! Solo letras, a lo sumo un espacio y max: 15 caracteres.", 15, 1);
                break;
            case 2:
                utn_getNumero(&listadoMascotas[idAModificar].edad, "\n-Ingrese la nueva edad de la mascota: ", "\n.Edad invalida! Min: 0 Max: 20.", 0, 20);
                break;
            case 3:
                listadoMascotas[idAModificar].sexo = GetGender("\n-Ingrese el nuevo genero de la mascota F | M : ", "\n.Genero invalido! Solo ingrese F o M.");
                break;
            case 4:
                utn_getNumero(&numeroTipo, "\n-Ingrese el numero correspondiente al tipo de la mascota\n\n # 1.Gato ---  2.Perro : ", "\n.Tipo invalido! Ingrese 1 o 2.", 1, 2);

                if(numeroTipo)
                {
                    strcpy(listadoMascotas[idAModificar].tipo, "Gato"); // 1
                }else{
                    strcpy(listadoMascotas[idAModificar].tipo, "Perro"); // 2
                }

                break;
            case 5:
                MostrarListadoRazasDisponibles(listadoRazas, tamlistaRazas);
                utn_getNumero(&listadoMascotas[idAModificar].idRaza, "\n-Ingrese el numero perteneciente a la raza de su mascota: ", "\n.Error raza invalida! Solo ingrese el numero correspondiente.", 10, idMaximoRazaDisponible);
                break;
            case 6:
                retorno = 0; //El usuario cancelo la modificacion.
                break;
        }

        if(opcionElegida != 6)
        {
            retorno = 1; //El usuario realizo una modificacion.
        }
    }

    return retorno;
}

int BorrarMascotasDeUnaRaza(eMascota listadoMascotas[], int tamListaMascotas, int idRazaABorrar)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO && listadoMascotas[i].idRaza == idRazaABorrar)
        {
            retorno = 0;
            listadoMascotas[i].isEmpty = VACIO;
        }
    }

    return retorno;
}

void MostrarListadoPorTipoYPeso(eMascota listadoMascotas[], int tamListaMascotas)
{
    int i, j;

    //Paralelos
    char tiposDisponibles[3][21] = {"Gato", "Perro", "Raro"};
    int contadoresTipos[3] = {0};
    float pesosTotalesTipos[3] = {0};
    float promediosPesoTipos[3] = {0};

    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            //Aca iteramos para cargar los arrays paralelos buscando primero mascotas tipo "Gato", luego "Perro", etc.
            for(j=0; j<3; j++)
            {
                if(strcmp(listadoMascotas[i].tipo, tiposDisponibles[j]) == 0)
                {
                    contadoresTipos[j]++;
                    pesosTotalesTipos[j]+= listadoMascotas[i].peso;
                    promediosPesoTipos[j] = pesosTotalesTipos[j] / contadoresTipos[j];
                }
            }
        }
    }

    printf("      ------------------------------------------------------------------------\n");
    printf("      |   TIPO   |  PESO TOTAL  |  CANTIDAD MASCOTAS  |  PROMEDIO PESO TOTAL |\n");
    printf("      ------------------------------------------------------------------------\n");

    for(i=0; i<3; i++)
    {
        printf("      |  %-11s %-20.3f %-20d %-13.3f |\n", tiposDisponibles[i], pesosTotalesTipos[i], contadoresTipos[i], promediosPesoTipos[i]);
        printf("      ------------------------------------------------------------------------\n");
    }
}
