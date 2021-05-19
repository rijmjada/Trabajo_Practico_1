#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "sector.h"


int buscarIdSector(int id, eSector listaSectores[],int tamSec){

    int indice = -1;
    for(int i=0; i<tamSec; i++){
        if(listaSectores[i].id == id){
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarSector(eSector sectores){

    printf("    %d   %10s\n",sectores.id, sectores.descripcion);
}


void mostrarListaDeSectores(eSector listaSectores[],int tamSec){

    printf("    Lista De Sectores\n");
    printf("    Id Descripcion\n");
    for(int i=0;i<tamSec;i++){
        mostrarSector(listaSectores[i]);
    }
}

int validarIdSector(int id, eSector listaSectores[],int tamSec){

    int esta = 0;
    for(int i=0; i<tamSec; i++){
        if(listaSectores[i].id == id){
            esta = 1;
            break;
        }
    }
    return esta;
}



int cargarDescripcionSector(int id, eSector listaSectores[], int tamSec,char descrip[]){

    int todoOk = -1;

    if(id>=500 && id<=504 && listaSectores != NULL && tamSec > 0 && descrip != NULL){

        for(int i=0; i<tamSec; i++){

            if(listaSectores[i].id == id){

                strcpy(descrip,listaSectores[i].descripcion);

                todoOk = 1;
                break;
            }
        }
    }


    return todoOk;
}


