#ifndef CURSOR_H
#define CURSOR_H
#include <string>
#include <curses.h>
#include <stdlib.h>

using namespace std;

class cursor
{
    public:
        //metodo constructor
        cursor(WINDOW* win, int y , int x, char c);
        //metodo destructor
        virtual ~cursor();

        void mvizq();
        void mvder();
        int getmv();
        void display();
        void movimientos(); //metodo que controla la impresion en pantalla

        //getters
        int getxLoc();//retorna posicion actual de x
        int getyLoc();//retorna posicion actual de y
        int getxMax();
        int getyMax();

        //setters
        void settxLoc(int x);
        void settyLoc(int y);
        void settCaracter(char c);

    protected:

    private:
        int xLoc, yLoc, xMax, yMax;
        char caracter;
        int numeroCaracter;
        WINDOW* curwin;
};

#endif // CURSOR_H
