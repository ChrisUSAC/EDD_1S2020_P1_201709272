#include "NodoLista.h"
//constructor
NodoLista::NodoLista(string palabraBus, string palabraRemp)
{
    this->palabraBus = palabraBus;
    this->palabraRemp = palabraRemp;
    this->siguiente = 0;
}
//destructor
NodoLista::~NodoLista()
{
    //dtor
}
