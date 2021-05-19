#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "empleado.h"

int listarEmpleadosPorSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int listarAllSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int totalSueldoSector(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int totalDepositar(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);
int sectorMayorSueldo(eEmpleado listaNomina[],int tam, eSector listaSectores[], int tamSec);



#endif // INFORMES_H_INCLUDED
