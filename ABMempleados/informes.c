#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "informes.h"



int listarEmpleadosPorSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec)
{

    int idSector;
    int indiceBuffer = -1;
    int flag = 0;

    system("cls");
    printf("    Lista de Empleados :");
    mostrarListaDeSectores(listaSectores,tamSec);
    printf("Ingrese el id del sector\n");
    scanf("%d",&idSector);

    indiceBuffer = buscarIdSector(idSector,listaSectores,tamSec);

    while( indiceBuffer == -1 )
    {
        printf("Id invalido.\nIngrese id del sector :\n");
        scanf("%d",&idSector);
        indiceBuffer = buscarIdSector(idSector,listaSectores,tamSec);
    }

    printf("    Lista de Empleados Sector : %s \n",listaSectores[indiceBuffer].descripcion);
    printf("LEGAJO     NOMBRE   EDAD  SEXO  SUELDO   F.INGRESO  SECTOR \n\n");

    for(int i=0; i<tamSec; i++)
    {
        if(listaNomina[i].isEmpty == 0 && listaNomina[i].idSector == idSector)
        {
            mostrarEmpleado(listaNomina[i], listaSectores,tamSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("   No hay empleados en el sector. Sector : %s \n",listaSectores[indiceBuffer].descripcion);
    }

    return 0;
}
int listarAllSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec)
{

    system("cls");
    printf("  Lista Empleados por Sector");
    int flag;

    for(int i=0; i<tamSec; i++)
    {

        printf("\n\n Sector : %s \n\n",listaSectores[i].descripcion);
        flag = 1;
        for(int j=0; j<tam; j++)
        {
            if( !listaNomina[j].isEmpty && listaNomina[j].idSector == listaSectores[i].id)
            {
                mostrarEmpleado(listaNomina[j],listaSectores,tamSec);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay empleados .\n");
        }
        printf("--------------------------------------------------------------------------\n");
    }
    return 0;
}

int totalSueldoSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec)
{

    int idSector;
    int indiceBuffer = -1;
    float acumulador=0;

    system("cls");
    printf("    Total sueldos Sector:");
    mostrarListaDeSectores(listaSectores,tamSec);
    printf("Ingrese el id del sector\n");
    scanf("%d",&idSector);

    indiceBuffer = buscarIdSector(idSector,listaSectores,tamSec);

    while( indiceBuffer == -1 )
    {
        printf("Id invalido.\nIngrese id del sector :\n");
        scanf("%d",&idSector);
        indiceBuffer = buscarIdSector(idSector,listaSectores,tamSec);
    }

    for(int i=0; i<tamSec; i++)
    {
        if(listaNomina[i].isEmpty == 0 && listaNomina[i].idSector == idSector)
        {

            acumulador+= listaNomina[i].sueldo;
        }
    }
    printf("  Total Sueldos : $ %2.f \n",acumulador);


    return 0;
}

int totalDepositar(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec){

    system("cls");
    printf("  Total Sueldos\n");
    float totalSueldos;
    float total=0;

    for(int i=0; i<tamSec; i++)
    {

        printf("\n\n Sector : %s \n\n",listaSectores[i].descripcion);

        for(int j=0; j<tam; j++)
        {
            if( !listaNomina[j].isEmpty && listaNomina[j].idSector == listaSectores[i].id)
            {
               totalSueldos += listaNomina[i].sueldo;
            }
        }
       printf("  Total Sueldos : $ %2.f \n",totalSueldos);
       total+=totalSueldos;
       printf("--------------------------------------------------------------------------\n");
    }

    printf("  Total a depositar : $ %2.f \n",total);

    return 0;
}

int sectorMayorSueldo(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec){

    float totalSueldos;
    float totales[tamSec];
    float mayores;
    int flag = 0;

    system("cls");
    printf("  Sectores que mas ganan\n");


    for(int i=0; i<tamSec; i++)
        {
        for(int j=0; j<tam; j++)
        {
            if( !listaNomina[j].isEmpty && listaNomina[j].idSector == listaSectores[i].id)
            {
               totalSueldos += listaNomina[i].sueldo;
            }
        }
       totales[i]=totalSueldos;
    }
    for(int i=0; i<tamSec; i++){

        if(flag == 0 || totales[i] > mayores){
            mayores = totales[i];
            flag=1;
        }
    }

    for(int i=0; i<tamSec; i++){
        if(mayores == totales[i]){
           printf("%s\n", listaSectores[i].descripcion);
        }
    }
    return 0;
}
