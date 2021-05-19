#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];
}eSector;

int cargarDescripcionSector(int id, eSector sectores[], int tamSec,char descrip[]);
void mostrarListaDeSectores(eSector sectores[],int tamSec);
void mostrarSector(eSector sectores);
int validarIdSector(int id, eSector listaSectores[],int tamSec);

int buscarIdSector(int id, eSector listaSectores[],int tamSec);



#endif // SECTOR_H_INCLUDED

