/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include <conio.h>

#include "menuPrincipal.h"
#include "funciones.h"

int main(void) {

	setbuf(stdout,NULL);

		float x=0;
		float y=0;
		int exit=0;
		int opcionMenu;

		int flagOpcion1y2 = 0;
		int flagOperaciones = 0;
		int flagInforme = 0;

		float resultadoResta;
		float resultadoSuma;
		float resultadoMultiplicacion;
		float resultadoDivision;
		int resultadoFactorial;
		int resultadoFactorial2;


	while(exit ==0){

		menuPrincipal(&opcionMenu,flagOpcion1y2,flagOperaciones,x,y);

		switch(opcionMenu){

		case 1:
			system("cls");
			printf("\nEsperando su ingreso...");
			fflush(stdin);
			scanf ("%f",&x);

			flagOpcion1y2 = 1;
			break;

		case 2:
			if(flagOpcion1y2){
				system("cls");
				printf("\nEsperando su ingreso...");
				fflush(stdin);
				scanf ("%f",&y);

				flagOperaciones = 1;
			}
			else{
				system("cls");
				printf("\n***ANTES DEBE INGRESAR EL PRIMER OPERANDO***\n");

			}
			break;

		case 3:
			if(flagOperaciones==1){
			system("cls");
			printf("\n***Las operaciones fueron calculadas***\n");
			system("cls");
			resta(&resultadoResta,x,y);
			suma(&resultadoSuma, x,y);
			dividir(&resultadoDivision,x,y);
			multiplicar(&resultadoMultiplicacion,x,y);
			factorial(&resultadoFactorial,x);
			factorial(&resultadoFactorial2,y);

			flagInforme = 1;

			}

			else{
				system("cls");
				printf("\n***ANTES DEBE INGRESAR AMBOS OPERANDOS***\n");

			}

			break;

		case 4:
			if(flagInforme){
				system("cls");
				printf("\nEl resultado de  %.2f + %.2f es : %.2f\n", x,y,resultadoSuma);
				printf("\nEl resultado de  %.2f - %.2f es : %.2f\n", x,y,resultadoResta);

				if (dividir(&resultadoDivision,x,y)){
					printf("\nEl resultado de  %.2f / %.2f es : %.2f\n", x,y,resultadoDivision);
					}
					else
					{
						printf("\nEl resultado de  %.2f / %.2f es : No se puede dividir por 0\n", x,y);
					}

				printf("\nEl resultado de  %.2f * %.2f es : %.2f\n", x,y,resultadoMultiplicacion);

				if(factorial(&resultadoFactorial,x)){
					printf("\nEl factorial de %.2f es :  %d\n",x,resultadoFactorial);
					}
				else{
						printf("\nEl factorial de %.2f : No se puede calcular\n ",x);
					}
				if(factorial(&resultadoFactorial2,y)){
					printf("\nEl factorial de %.2f es : %d\n",y,resultadoFactorial2);
					}
				else
					{
						printf("\nEl factorial de %.2f : No se puede calcular \n: ",y);
					}



				x=0;
				y=0;
				flagOpcion1y2 = 0;
				flagOperaciones = 0;
				flagInforme = 0;



			}//if case4
			else{
				system("cls");
				printf("\n***ANTES DEBE CALCULAR LAS OPERACIONES***\n");
			}


			break;

		case 5: exit=1;
			break;
		default:
			system("cls");
			printf("\n***NO INGRESO UNA OPCION VALIDA***\n");
			printf("\nPulse una tecla para continuar...\n");
			system("cls");


			break;

	    break;
		}//switch

	}//while

	return EXIT_SUCCESS;
}
