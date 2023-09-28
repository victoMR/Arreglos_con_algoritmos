#ifndef VECTORES_H
#define VECTORES_H
#include <iostream>

using namespace std;

class vectores
{
private:
    //int ar[5]; // esto es un puntero
    int *ar; // asi se declara un puntero
    int n;
    int ele;
    void quickRec(int li,int ls);
    int posPivote(int li, int ls);

public:
    vectores(int n);
    void pideDatos();
    void imprimir();
    string buscarSec(int ele);
    int buscarSecRec(int pos, int ele);
    void burbuja();
    string busquedaBin(int ele );
    string busquedaBinRec(int li, int ls, int ele );
    void quickSort();
    void newQuick();
    void insercion();
    void insercion2();
};

#endif // VECTORES_H
