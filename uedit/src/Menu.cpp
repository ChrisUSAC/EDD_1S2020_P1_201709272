#include "Menu.h"
#include <string>

using namespace std;
//---------------------------------------------------------------------------------------------
//metodo constructor
Menu::Menu()
{
    //ctor
}
//---------------------------------------------------------------------------------------------
//metodo destructor
Menu::~Menu()
{
    //dtor
}
//---------------------------------------------------------------------------------------------
void Menu::menuPrincipal()
{
    initscr(); //inicio de curses
    noecho();
    cbreak();

    int alto,ancho,pos_x,pos_y; //variables para la creacion de la ventana
    alto = 20;
    ancho = 60;
    pos_x = pos_y = 0;

    WINDOW* win = newwin(alto,ancho,pos_y,pos_x); // instancia de una ventana
    box(win,0,0);
    refresh();
    wrefresh(win);

    //permite el uso de las flechas del teclado
    keypad(win,true);

    string eleccion[4] = {"1. CREAR ARCHIVO" ,"2. ABRIR ARCHIVO","3. ARCHIVOS RECIENTES","4. SALIR"}; // para la seleccion del menu
    int choice=0;
    int remarcar = 0;

    mvwprintw(win,3,5,"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA");
    mvwprintw(win,4,5,"FACULTAD DE INGENIERIA");
    mvwprintw(win,5,5,"ESTRUCTURA DE DATOS");
    mvwprintw(win,6,5,"PRACTICA 1");
    mvwprintw(win,7,5,"CHRISTOPHER ALEXANDER COBAR ASTURIAS");
    mvwprintw(win,8,5,"201709272");
    mvwprintw(win,12,5,"MENU ");

    while(1)
    {
        int lugarY = 13;
        for(int i = 0; i < 4;i++)
        {
            if(i==remarcar)


                wattron(win,A_REVERSE);
            mvwprintw(win,lugarY++,5,eleccion[i].c_str());
            wrefresh(win);
            wattroff(win,A_REVERSE);

        }
        choice = wgetch(win);

        switch(choice)
        {
        case KEY_UP:
            remarcar--;
            break;
        case KEY_DOWN:
            remarcar++;
            break;
        default:
            break;
        }


        if(choice == 10) // si se presiona tecla enter, sale del while
        {
            break;
        }

        if(remarcar == 4) // remarca la opcion 1
        {
            remarcar = 0;

        }
        if(remarcar == -1) //remarca la opcion 4
        {
            remarcar = 3;

        }

    }

    endwin(); // destruye la ventana del menuPrincipal y abre la ventana del siguiente menu

    //evaluar que opcion del menu se desea utilizar
    if(remarcar==0)
    {
        //desplegar el editor de texto
        menuEditor();
    }
    else if(remarcar==1)
    {
        //desplegar menu abrir archivos

    }
    else if(remarcar==2)
    {
        //desplegar menu archivos recientes

    }
    else if(remarcar==3)
    {
        //finalizar aplicacion
    }

}
//---------------------------------------------------------------------------------------------
void Menu::menuEditor()
{
    initscr(); //inicio de curses
    noecho();
    cbreak();

    int alto,ancho,pos_x,pos_y; //variables para la creacion de la ventana
    alto = 40;
    ancho = 100;
    pos_x = pos_y = 0;

    WINDOW* win = newwin(alto,ancho,pos_y,pos_x); // instancia de una ventana
    box(win,0,0);
    refresh();
    wrefresh(win);

    mvwprintw(win,3,5,"Este");
    mvwprintw(win,4,5,"Seria");
    mvwprintw(win,5,5,"El");
    mvwprintw(win,6,5,"menu");
    mvwprintw(win,7,5,"para");
    mvwprintw(win,8,5,"edicion");

    int c = getch();
    endwin(); // destruye la ventana del menuPrincipal y abre la ventana del siguiente menu

}
//---------------------------------------------------------------------------------------------

