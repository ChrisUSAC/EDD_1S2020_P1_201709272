#include "NodoListaC.h"

NodoListaC::NodoListaC(string direccion,string nombre)
{
    this->direccion = direccion;
    this->nombre = nombre;
    this->sig = 0;
}

NodoListaC::~NodoListaC()
{
    //dtor
}
