#include "NodoPila.h"

NodoPila::NodoPila(string palabraBus, string palabraRemp, string estado, string palabra, int posicion)
{
    this->palabraBus = palabraBus;
    this->palabraRemp = palabraRemp;
    this->estado = estado;
    this->palabra = palabra;
    this->posicion = posicion;

    this->siguiente = 0;
}

NodoPila::~NodoPila()
{
    //dtor
}
