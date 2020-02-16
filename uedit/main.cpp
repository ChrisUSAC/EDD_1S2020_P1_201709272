#include <iostream>
#include <curses.h> // libreria para creacion de menus
#include "Menu.h"

using namespace std;

int main()
{
    //creacion del objeto menu
    Menu* menu = new Menu();
    menu->menuPrincipal();

    return 0;
}
