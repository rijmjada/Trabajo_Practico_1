/*
 * menuPrincipal.c
 *
 *  Created on: 15 abr. 2021
 *      Author: diego
 */
#include <stdio.h>
#include <stdlib.h>

int menuPrincipal(int* opcionMenu,int flagOpcion1y2,int flagOperaciones,float x, float y){


	int opcionUsuario;

		if(flagOpcion1y2 == 0)
		{
			printf("\n  ****** Bienvenido! ******\n");
			printf("	 __________ \n");
			printf("	| ---------|\n");
			printf("	||12345678||\n");
			printf("	| -------- |\n");
			printf("	|[M|#|C][-]|\n");
			printf("	|[7|8|9][+]|\n");
			printf("	|[4|5|6][x]|\n");
			printf("	|[1|2|3][.]|\n");
			printf("	|[.|O|:][=]|\n");
			printf("	 __________ \n");


			printf("\n1- Ingresar 1er operando (A = x)\n");
			printf("2- Ingresar 2do operando (B = y)\n");
			printf("3- Calcular todas las operaciones\n");
			printf("4- Informar resultados\n");
			printf("5- Salir\n");
			printf("\n Elija una opcion: \n");
				fflush(stdin);
				scanf("%d",&opcionUsuario);
		}

		if(flagOpcion1y2 == 1 && flagOperaciones == 0)

		{

			printf("\n  ****** Bienvenido! ******\n");
					printf("	 __________ \n");
					printf("	| ---------|\n");
					printf("	||12345678||\n");
					printf("	| -------- |\n");
					printf("	|[M|#|C][-]|\n");
					printf("	|[7|8|9][+]|\n");
					printf("	|[4|5|6][x]|\n");
					printf("	|[1|2|3][.]|\n");
					printf("	|[.|O|:][=]|\n");
					printf("	 __________ \n");

					printf("\n1- Ingresar 1er operando (%.2f)\n",x);
				printf("2- Ingresar 2do operando (B = y)\n");
				printf("3- Calcular todas las operaciones\n");
				printf("4- Informar resultados\n");
				printf("5- Salir\n");
				printf("\n Elija una opcion: \n");
				fflush(stdin);
				scanf("%d",&opcionUsuario);
		}

		if(flagOperaciones == 1)
		{
			printf("\n  ****** Bienvenido! ******\n");
					printf("	 __________ \n");
					printf("	| ---------|\n");
					printf("	||12345678||\n");
					printf("	| -------- |\n");
					printf("	|[M|#|C][-]|\n");
					printf("	|[7|8|9][+]|\n");
					printf("	|[4|5|6][x]|\n");
					printf("	|[1|2|3][.]|\n");
					printf("	|[.|O|:][=]|\n");
					printf("	 __________ \n");
				printf("\n1- Ingresar 1er operando (%.2f)\n",x);
				printf("2- Ingresar 2do operando (%.2f)\n",y);
				printf("3- Calcular todas las operaciones\n");
				printf("4- Informar resultados\n");
				printf("5- Salir\n");
				printf("\n Elija una opcion: \n");
				fflush(stdin);
				scanf("%d",&opcionUsuario);
		}




		*opcionMenu=opcionUsuario;

	return 0;
}
