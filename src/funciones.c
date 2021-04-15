/*
 * funciones.c
 *
 *  Created on: 15 abr. 2021
 *      Author: diego
 */

#include <stdio.h>
#include <stdlib.h>

int suma(float* resultadoSuma, float x ,float y){

	int retorno = 0;

	if(resultadoSuma != NULL){

		int resolucion = x+y;

		*resultadoSuma = resolucion;
		retorno = 1;
	}

	return retorno;
}

int resta(float* resultadoResta, float x ,float y){

	int retorno = 0;

		if(resultadoResta != NULL){

			int resolucion = x-y;

			*resultadoResta = resolucion;
			retorno = 1;
		}

		return retorno;

}

int multiplicar(float* resultadoMultiplicacion, float x ,float y){

	float resolucion = x * y;
	*resultadoMultiplicacion = resolucion;

	return 0;
}

int dividir(float* resultadoDividir, float x ,float y){

	float resolucion;
	int retorno = 0;
	if ( y != 0 ){
		resolucion = x/ y;
		*resultadoDividir = resolucion;
		retorno = 1;
	}

	return retorno;
}

int factorial(int* factorial,float miVariable) {

	int retorno = 0;
	int factorialX=1;

	if(miVariable==0){
		*factorial = 1;
		retorno = 1;
	}

	if(miVariable > 0)
	{
		while (miVariable>0) {
			factorialX = factorialX*miVariable;
			miVariable--;
			}
		*factorial = factorialX;
		retorno = 1;
	}


	return retorno;
}
