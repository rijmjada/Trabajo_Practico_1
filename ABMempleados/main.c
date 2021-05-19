#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "sector.h"
#include "informes.h"



#define TAM 15
#define TAMSEC 5



int main()
{

    int nextLegajo = 2000;

    eEmpleado nomina[TAM];
    eSector sectores[TAMSEC]={
            {500,"Legales"},
            {501,"Sistemas"},
            {502,"RRHH"},
            {503,"Marketing"},
            {504,"Contable"}
    };
    inicializarEmpleado(nomina, TAM);

    hardcodearEmpleados(nomina,TAM,5,&nextLegajo);

    char exit = 'n';

    do{

        switch(menuAbm()){

            case 1:
                if(altaEmpleado(nomina,TAM,sectores,TAMSEC,&nextLegajo)){
                    printf("\nAlta Exitosa\n");
                }
                else{
                    printf("\nNo se puedo cargar el empleado\n");
                }

                break;

            case 2:
                if(bajaEmpleado(nomina,TAM,sectores,TAMSEC)){
                    printf("Baja Exitosa!\n");
                }
                else{
                    printf("Hubo un error en el proceso de baja!\n");
                }
                break;

            case 3:

                break;

            case 4:
                system("cls");
                mostrarEmpleados(nomina,TAM,sectores,TAMSEC);
                break;

            case 5:
                ordenarEmpleados(nomina, TAM);
                break;

            case 6:
                printf("Informes\n");
                break;

            case 7:
                system("cls");
                mostrarListaDeSectores(sectores,TAMSEC);
                break;

            case 8:
                listarAllSector(nomina,TAM,sectores,TAMSEC);
                break;

            case 9:
                system("cls");
                listarEmpleadosPorSector(nomina,TAM,sectores,TAMSEC);
                break;

            case 10:
                system("cls");
                totalSueldoSector(nomina,TAM,sectores,TAMSEC);
                break;
            case 11:
                system("cls");
                totalDepositar(nomina,TAM,sectores,TAMSEC);
                break;
            case 12:
                sectorMayorSueldo(nomina,TAM,sectores,TAMSEC);
                break;
            case 13:
                printf("Confirma que desea salir? s/n\n");
                fflush(stdin);
                scanf("%c",&exit);
                break;

        default:
            printf("Opcion no valida. Reingrese\n");
            break;

        }//switch

        system("pause");

    }while(exit == 'n');

    return 0;
}




