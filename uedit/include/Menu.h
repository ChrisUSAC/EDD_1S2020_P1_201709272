#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <curses.h> //libreria utilizada para los menus
#include <string>
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


    protected:

    private:
};

#endif // MENU_H
