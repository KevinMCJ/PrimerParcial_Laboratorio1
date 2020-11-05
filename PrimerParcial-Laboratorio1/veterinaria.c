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

void Menu()
{
    printf("\n*********************\n");
    printf("*MENU DE OPERACIONES*\n");
    printf("*********************\n");
    printf("1.Mostrar listado de mascotas.\n");
    printf("2.Mostrar listado mascotas con datos del pais.\n");
    printf("3.Mostrar listado mascotas por Tamanio Y Peso.\n");
    printf("4.Listar por Tipo y Peso (Datos).\n");
    printf("5.Alta de mascota\n");
    printf("6.Alta de raza\n");
    printf("7.Modificar mascota.\n");
    printf("8.Baja de mascota.\n");
    printf("9.Borrado en cascada de razas con sus mascotas.\n");
    printf("10.Ordenar listado por Pais De Origen.\n");
    printf("11.Ordenar listado por Codigo Telefonico Pais.\n");
    printf("12.Pais de origen con mas mascotas en la veterinaria.\n");
    printf("13.SALIR\n");
}

void MostrarMascotaConRaza(eMascota unaMascota, eRaza unaRaza, ePais unPais)
{
    printf("      |  %-5d\t%-10s\t%-6c \t %-7s\t%-4d \t %-20s  %-11s   |\n", unaMascota.id, unaMascota.nombre, unaMascota.sexo, unaMascota.tipo, unaMascota.edad, unaRaza.descripcion, unPais.nombrePais);
    printf("      ------------------------------------------------------------------------------------------------\n");
}

void MostrarListadoMascotasConRazas(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    eRaza auxiliarRaza;
    ePais auxiliarPais;

    int i;

    printf("      ------------------------------------------------------------------------------------------------\n");
    printf("      |  ID  |  NOMBRE    |   SEXO    |   TIPO    |   EDAD    |       RAZA       |   PAIS DE ORIGEN  |\n");
    printf("      ------------------------------------------------------------------------------------------------\n");

    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            auxiliarRaza = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[i].idRaza);
            auxiliarPais = BuscarPais(listadoPaises, tamListaPaises, auxiliarRaza.idPaisOrigen);
            MostrarMascotaConRaza(listadoMascotas[i], auxiliarRaza, auxiliarPais);
        }
    }
}

int OrdenarListadoPorPais(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    int retorno = -1;
    int i;
    int j;

    eMascota auxMascota;
    eRaza auxRazaI;
    eRaza auxRazaJ;

    ePais auxPaisI;
    ePais auxPaisJ;

    for(i=0; i<tamListaMascotas-1; i++)
    {
        for(j=i+1; j<tamListaMascotas; j++)
        {
            //Obtenemos la raza en posicion 0 con sus campos.
            auxRazaI = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[i].idRaza);

            auxPaisI = BuscarPais(listadoPaises, tamListaPaises, auxRazaI.idPaisOrigen);
            //Obtenemos la raza en posicion i+1 con sus campos.
            auxRazaJ = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[j].idRaza);

            auxPaisJ = BuscarPais(listadoPaises, tamListaPaises, auxRazaJ.idPaisOrigen);

            if(strcmp(auxPaisI.nombrePais, auxPaisJ.nombrePais) > 0)
            {
                retorno = 0;
                auxMascota = listadoMascotas[i];
                listadoMascotas[i] = listadoMascotas[j];
                listadoMascotas[j] = auxMascota;
            }

        }
    }

    return retorno;
}

void MostrarListadoMascotaMismaRaza(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, int idRazaAMostrar, ePais listadoPaises[], int tamListaPaises)
{
    int hayUno;
    int iMascotas;
    int iRaza;
    int iPais;

    hayUno = 0;

    printf("\n\t\t       ____________________________________________________________\n\t\t      |\t\t\t\t\t\t\t\t   |\n");
    printf("\t\t      | Listado de mascotas pertenecientes a la raza de su mascota |\n");
    printf("\t\t      |____________________________________________________________|\n\n");
    printf("      ------------------------------------------------------------------------------------------------\n");
    printf("      |  ID  |  NOMBRE    |   SEXO    |   TIPO    |   EDAD    |       RAZA       |   PAIS DE ORIGEN  |\n");
    printf("      ------------------------------------------------------------------------------------------------\n");

    for(iMascotas=0; iMascotas<tamListaMascotas; iMascotas++)
    {
        for(iRaza=0; iRaza<tamListaRazas; iRaza++)
        {
            for(iPais = 0; iPais<tamListaPaises; iPais++)
            {
                if(listadoMascotas[iMascotas].isEmpty == OCUPADO && listadoMascotas[iMascotas].idRaza == idRazaAMostrar && listadoRazas[iRaza].idRaza == idRazaAMostrar)
                {
                    if(listadoRazas[iRaza].idPaisOrigen == listadoPaises[iPais].idPaisOrigen)
                    {
                        hayUno = 1;
                        MostrarMascotaConRaza(listadoMascotas[iMascotas], listadoRazas[iRaza], listadoPaises[iPais]);
                    }
                }
            }
        }
    }

    if(hayUno == 0)
    {
        printf("      |\t\t\t\tNO HAY NINGUNA MASCOTA CON LA MISMA RAZA \t\t\t   |\n");
        printf("      ----------------------------------------------------------------------------------------------\n");
    }
}

void MostrarPaisDeOrigenMasMascotas(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    ePais auxiliarPais;
    eRaza auxiliarRaza;

    int maximaCantidadRepeticiones;
    int indiceMasRepeticiones;
    int i, j;
    int contadorMaximosRepetidos;
    //Arrays Paralelos
    int arrayIdPaisOrigen[tamListaMascotas];
    int arrayContadores[tamListaMascotas];

    contadorMaximosRepetidos = 0;

    //Carga de array pais de origen mediante las razas de cada mascota.
    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            //Iniciamos todo el array en uno ya que todos los que se encontraron al menos se repitieron 1 vez.
            arrayContadores[i] = 1;

            auxiliarRaza = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[i].idRaza);

            arrayIdPaisOrigen[i] = auxiliarRaza.idPaisOrigen;
        }
    }

    //Carga de arrays contadores mediante el paralelo del id pais de origen.
    for(i=0; i<tamListaMascotas-1; i++)
    {
        for(j=i+1; j<tamListaMascotas; j++)
        {
            if(arrayIdPaisOrigen[i] == arrayIdPaisOrigen[j])
            {
                arrayContadores[i]++;
            }
        }
    }

    //Iteracion para encontrar finalmente el idPais de origen con mas repeticiones.
    for(i=0; i<tamListaMascotas;i++)
    {
        if(i==0 || arrayContadores[i] > maximaCantidadRepeticiones)
        {
            if(arrayContadores[i] <= tamListaMascotas) //Este if para que no tome numeros basura
            {
                maximaCantidadRepeticiones = arrayContadores[i];
                indiceMasRepeticiones = i;
            }
        }
    }

    /*Iteracion para saber sabes si hay varios maximos en el arrayContadores, de ser asi hay 2
            razas o mas con la misma cantidad de mascotas maximas de la lista.*/
    for(i=0; i<tamListaMascotas; i++)
    {
        if(arrayContadores[i] == maximaCantidadRepeticiones && arrayContadores[i] <= tamListaMascotas)
        {
            contadorMaximosRepetidos++;
        }
    }

    if(contadorMaximosRepetidos > 1)
    {
        printf("\n-Hay dos o mas paises de origen con la misma cantidad de mascotas en la lista.\n\n");
    }
    else
    {
        auxiliarPais = BuscarPais(listadoPaises, tamListaPaises, arrayIdPaisOrigen[indiceMasRepeticiones]);
        printf("\n-El pais de origen con mas mascotas es: %s\n\n", auxiliarPais.nombrePais);
    }

}

void MostrarMascotasConDatosPaisYRaza(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    eRaza auxiliarRaza;
    ePais auxiliarPais;

    int i;

    printf("      --------------------------------------------------------------------------------------\n");
    printf("      |  ID   |     NOMBRE     |     RAZA     |   TAMANIO   |     PAIS     |  CODIGO TEL.  |\n");
    printf("      --------------------------------------------------------------------------------------\n");

    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            auxiliarRaza = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[i].idRaza);
            auxiliarPais = BuscarPais(listadoPaises, tamListaPaises, auxiliarRaza.idPaisOrigen);
            printf("      |  %-9d %-13s %-16s %-13s %-17s %-8d |\n", listadoMascotas[i].id, listadoMascotas[i].nombre, auxiliarRaza.descripcion, auxiliarRaza.tamanio, auxiliarPais.nombrePais, auxiliarPais.codigoTelefonico);
            printf("      --------------------------------------------------------------------------------------\n");
        }
    }
}

int OrdenarListadoPorCodigoTelPais(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    int retorno = -1;
    int i;
    int j;

    eMascota auxMascota;
    eRaza auxRazaI;
    eRaza auxRazaJ;

    ePais auxPaisI;
    ePais auxPaisJ;

    for(i=0; i<tamListaMascotas-1; i++)
    {
        for(j=i+1; j<tamListaMascotas; j++)
        {
            //Obtenemos la raza para luego obtener el pais de cada mascota mediante la relacion.
            auxRazaI = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[i].idRaza);

            auxPaisI = BuscarPais(listadoPaises, tamListaPaises, auxRazaI.idPaisOrigen);
            //Hacemos lo mismo con la siguiente mascota asi podemos compararlas.
            auxRazaJ = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[j].idRaza);

            auxPaisJ = BuscarPais(listadoPaises, tamListaPaises, auxRazaJ.idPaisOrigen);

            if(auxPaisI.codigoTelefonico < auxPaisJ.codigoTelefonico)
            {
                retorno = 0;
                auxMascota = listadoMascotas[i];
                listadoMascotas[i] = listadoMascotas[j];
                listadoMascotas[j] = auxMascota;
            }

        }
    }

    return retorno;
}

int MostrarListadoPorTamanioYPeso(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas, ePais listadoPaises[], int tamListaPaises)
{
    eRaza auxiliarRaza;
    ePais auxiliarPais;
    int retorno = -1;
    int eleccionTamanioUsuario;
    float sumaPesoMascotas;
    char tamanioElegido[21];

    sumaPesoMascotas = 0;

    utn_getNumero(&eleccionTamanioUsuario, "\n-Ingrese el tamanio de las masctoas a listar.\n\n 1.Chico -- 2.Mediano -- 3.Grande : ", "\n.ERROR! Eliga el numero correspondiente al tamanio de la mascota.", 1, 3);

    switch(eleccionTamanioUsuario)
    {
        case 1:
            strcpy(tamanioElegido, "Chico");
            break;
        case 2:
            strcpy(tamanioElegido, "Mediano");
            break;
        default: //3
            strcpy(tamanioElegido, "Grande");
    }

    int i;

    printf("      -------------------------------------------------------------------------------------------------\n");
    printf("      |  ID   |     NOMBRE     |     RAZA     |   TAMANIO   |   PESO   |     PAIS     |  CODIGO TEL.  |\n");
    printf("      -------------------------------------------------------------------------------------------------\n");

    for(i=0; i<tamListaMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            auxiliarRaza = BuscarRaza(listadoRazas, tamListaRazas, listadoMascotas[i].idRaza);

            if(strcmp(auxiliarRaza.tamanio, tamanioElegido) == 0)
            {
                retorno = 0;
                sumaPesoMascotas += listadoMascotas[i].peso;
                auxiliarPais = BuscarPais(listadoPaises, tamListaPaises, auxiliarRaza.idPaisOrigen);
                printf("      |  %-9d %-13s %-16s %-13s %-10.2f %-17s %-8d |\n", listadoMascotas[i].id, listadoMascotas[i].nombre, auxiliarRaza.descripcion, auxiliarRaza.tamanio, listadoMascotas[i].peso, auxiliarPais.nombrePais, auxiliarPais.codigoTelefonico);
                printf("      -------------------------------------------------------------------------------------------------\n");
            }
        }
    }

    if(retorno == 0) //O sea que encontro al menos uno.
    {
        printf("\n-La suma total del peso entre las mascotas de tamanio %s es: %.3f\n\n", tamanioElegido, sumaPesoMascotas);
    }else{
        printf("\n-No hay mascotas de tamanio %s en la lista para calcular el peso total.\n\n", tamanioElegido);
    }

    return retorno;
}

int BorrarRazaConMascotas(eMascota listadoMascotas[], int tamListaMascotas, eRaza listadoRazas[], int tamListaRazas)
{
    int retorno = -1;
    int idRazaElegida;
    int confirmacionBorrado;
    int idMaximoRazaDisponible;

    idMaximoRazaDisponible = BuscarIdMaximoRazaDisponible(listadoRazas, tamListaRazas);

    utn_getNumero(&idRazaElegida, "\n-Ingrese el numero perteneciente a la raza a eliminar: ", "\n.Error raza invalida! Solo ingrese el numero correspondiente.", 10, idMaximoRazaDisponible);

    confirmacionBorrado = GetConfirmCharacter("\n.Esta seguro/a de eliminar esta raza con todas sus mascotas de la lista? S / N : ", "\n.Error! Solo ingrese S o N.");

    if(confirmacionBorrado == 'S')
    {
        retorno = 0;
        BorrarRaza(listadoRazas, tamListaRazas, idRazaElegida);
        BorrarMascotasDeUnaRaza(listadoMascotas, tamListaMascotas, idRazaElegida);
    }

    return retorno;
}

void LimpiarConsola()
{
    system("pause");
    system("cls");
}
