#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "sector.h"
#include "Datos.h"

void inicializarEmpleado(eEmpleado lista[],int tam)
{

    for(int i=0; i< tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}
int hardcodearEmpleados(eEmpleado lista[], int tam, int xCantidad, int* pLegajo)
{

    int cantidad = 0;
    if(lista != NULL && tam > 0 && cantidad >= 0 && cantidad <= 0 && pLegajo != NULL)
    {
        for(int i=0; i < xCantidad; i++)
        {
            lista[i].legajo = *pLegajo;
            (*pLegajo)++;  // PODRIA PONER TAMBIEN  " *pLegajo = *pLegajo + 1; "
            strcpy(lista[i].nombre,nombres[i]);
            lista[i].edad = edades[i];
            lista[i].sueldo = sueldos[i];
            lista[i].sexo = sexos[i];
            lista[i].fIngreso = fechas[i];
            lista[i].idSector = idSectores[i];
            lista[i].isEmpty = 0;
            cantidad++;

        }
    }


    return cantidad;
}


void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{

    int flag = 1;
    printf("    Lista de Empleados\n");
    printf("LEGAJO     NOMBRE   EDAD  SEXO  SUELDO   F.INGRESO  SECTOR \n\n");

    for(int i=0; i<tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarEmpleado(lista[i],sectores,tamSec);
            flag = 0;
        }
    }
    if(flag)
    {
        printf("No hay empleados para mostrar . \n");
    }

    printf("\n\n");
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tamSec)
{
    char descrip[20];
    cargarDescripcionSector(unEmpleado.idSector, sectores,tamSec,descrip);

    printf("%d   %10s   %d   %c  %9.2f   %02d/%02d/%d   %s\n"
           ,unEmpleado.legajo
           ,unEmpleado.nombre
           ,unEmpleado.edad
           ,unEmpleado.sexo
           ,unEmpleado.sueldo
           ,unEmpleado.fIngreso.dia
           ,unEmpleado.fIngreso.mes
           ,unEmpleado.fIngreso.anio
           ,descrip
          );

}

void ordenarEmpleados(eEmpleado lista[], int tam)
{

    eEmpleado auxEmpleado;
    for(int i=0; i<tam -1 ; i ++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(lista[i].sexo > lista[j].sexo ||(lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre, lista[j].nombre)>0))
            {
                auxEmpleado = lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}

int menuAbm()
{

    int opcionMenu;

    system("cls");
    printf("          Menu de Opciones \n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Lista Empleados\n");
    printf("5- Ordenar Empleados\n");
    printf("6- Informes\n");
    printf("7- Lista Sectores\n");
    printf("8- Lista todos los sectores\n");
    printf("9- Lista Empleados por Sector\n");
    printf("10- Total sueldos por Sector\n");
    printf("11- Total a depositar \n");
    printf("12- Sector mayor Sueldo\n");
    printf("13- Salir\n");

    fflush(stdin);
    scanf("%d",&opcionMenu);

    return opcionMenu;
}

int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec, int* pLegajo)
{

    int todoOk = 0;
    eEmpleado nuevoEmpleado;
    int indice;
    int bufferSector;

    system("cls");
    printf("   Alta Empleado\n\n");
    printf(" Legajo : %d\n",*pLegajo);

    if(lista != NULL && tam > 0 && pLegajo != NULL)
    {
        indice = buscarEspacioLibre(lista, tam);

        if (indice == -1)
        {
            printf("\nNo hay lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese nombre : ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese edad : ");
            scanf("%d",&nuevoEmpleado.edad);

            printf("Ingrese sexo : ");
            fflush(stdin);
            scanf("%c",&nuevoEmpleado.sexo);

            printf("Ingrese sueldo : ");
            fflush(stdin);
            scanf("%f",&nuevoEmpleado.sueldo);

            printf("Ingrese fecha de ingreso dd/mm/aaaa : ");
            fflush(stdin);
            scanf("%d/%d/%d",&nuevoEmpleado.fIngreso.dia
                  ,&nuevoEmpleado.fIngreso.mes
                  ,&nuevoEmpleado.fIngreso.anio);

            mostrarListaDeSectores(sectores,tamSec);
            printf("Ingrese el id del sector : ");
            scanf("%d",&bufferSector);

            nuevoEmpleado.idSector = bufferSector;
            nuevoEmpleado.legajo = *pLegajo; // ASIGNO EL VALOR DE NEXTLEGAJO A  nuevoEmpleado.legajo
            nuevoEmpleado.isEmpty = 0;       // isEmpty en 0 (espacio ocupado)
            *pLegajo = *pLegajo + 1;         // SUMO EL VALOR DE NEXTLEGAJO
            // (*pLegajo)++                  // OTRA FORMA DE SUMAR EL VALOR DE NEXTLEGAJO
            lista[indice] =  nuevoEmpleado;  // COPIO EL EMPLEADO CARGADO EN LA LISTA DEFINITIVA

            todoOk = 1;
        }

    }

    return todoOk;
}

int buscarEspacioLibre(eEmpleado lista[], int tam)
{

    int lugarLibreArray = -1;
    for(int i=0; i<tam; i++)
    {

        if(lista[i].isEmpty)
        {
            lugarLibreArray = i; // devuelve la posicion libre
            break;
        }
    }

    return lugarLibreArray;
}

int buscarEmpleadoPorLegajo(eEmpleado lista[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {

        if(lista[i].legajo == legajo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{

    int todoOk = -1;
    int legajo;
    int indice;
    char confirma;

    system("cls");
    printf("    Baja Empleado\n");
    mostrarEmpleados(lista,tam,sectores,tamSec);
    printf("Ingrese legajo : \n");
    scanf("%d",&legajo);

    indice = buscarEmpleadoPorLegajo(lista,tam,legajo);

    if(indice == -1)
    {
        printf("No hay ningun empleado con el legajo : %d\n",legajo);
    }
    else
    {
        mostrarEmpleado(lista[indice],sectores,tamSec);
        printf("Confirma baja ? \n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {

            lista[indice].isEmpty = 1;
            todoOk = 1;
        }
        else
        {
            printf("Baja cancelada por el usuario.\n");
        }

    }

    return todoOk;
}


