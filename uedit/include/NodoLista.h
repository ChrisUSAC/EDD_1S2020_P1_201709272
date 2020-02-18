#ifndef NODOLISTA_H
#define NODOLISTA_H

#include<iostream>
using namespace std;

class NodoLista
{
    public:
        NodoLista(string palabraBus, string palabraRemp);
        virtual ~NodoLista();
        NodoLista* siguiente; //puntero al siguiente nodo

        string palabraBus;
        string palabraRemp;

    protected:

    private:
};

#endif // NODOLISTA_H
