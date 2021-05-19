#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "sector.h"

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{

    int legajo;
    char nombre[24];
    int edad;
    char sexo;
    float sueldo;
    eFecha fIngreso;
    int idSector;
    int isEmpty;

}eEmpleado;

int menuAbm();
int buscarEspacioLibre(eEmpleado lista[], int tam);
int buscarEmpleadoPorLegajo(eEmpleado lista[], int tam, int legajo);
int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec, int* pLegajo);
int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
void inicializarEmpleado(eEmpleado lista[],int tam);
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam);
void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
void ordenarEmpleados(eEmpleado lista[], int tam);
int cargarDescripcionSector(int id, eSector sectores[], int tamSec,char descrip[]);


int hardcodearEmpleados(eEmpleado lista[], int tam, int xCantidad, int* pLegajo);

int listarEmpleadosPorSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int listarAllSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int totalSueldoSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int totalDepositar(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int sectorMayorSueldo(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);



#endif // EMPLEADO_H_INCLUDED
