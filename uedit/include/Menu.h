#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <curses.h> //libreria utilizada para los menus
#include <string>
#include "cursor.h"
#include "ListaDoble.h"
#include "Pila.h"
#include "Lista.h"

using namespace std;

class Menu
{
    public:
        //metodos contructor y destructor
        Menu();
        virtual ~Menu();

        //metodos que desplegan los menus
        void menuPrincipal(); // metodo que desplega el menu principal

        void menuEditor(); // metodo que desplega la interfaz del editor
        void metodoBuscarRemplazar(WINDOW* win,cursor* p); // funcion ctrl+w
        void repintarEditor();//metodo que repinta el editor con el texto de la lista
        void metodoReportes(WINDOW* win,cursor* p); //funcion ctrl+c


    protected:

    private:
};

#endif // MENU_H
