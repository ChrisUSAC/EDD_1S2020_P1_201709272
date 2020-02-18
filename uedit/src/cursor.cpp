#include "cursor.h"

//-----------------------------------------------------------------------------------------------------
//metodo constructor
cursor::cursor(WINDOW* win, int y, int x, char c)
{
    this->curwin = win;
    this->yLoc = y;
    this->xLoc = x;
    getmaxyx(curwin,yMax,xMax);
    this->caracter = c;
    this->numeroCaracter=0;

}
//-----------------------------------------------------------------------------------------------------
//metodo destructor
cursor::~cursor()
{

}
//-----------------------------------------------------------------------------------------------------
//desplazamiento a la izquierda como un borrar
void cursor::mvizq()
{
    xLoc--;

    if(xLoc < 1 && yLoc!=1)
    {
        xLoc = xMax-3;
        yLoc--;
    }
    else if(xLoc < 1 && yLoc==1)
    {
        xLoc = 1;
    }
    else
    {
        //evaluar si la psicion de x es mayor a 1 para posicionar el borrado
        if(xLoc!=1)
        {

        }
        else
        {
            xLoc = 1;
        }


    }
}
//-----------------------------------------------------------------------------------------------------
//desplazamiento a la derecha
void cursor::mvder()
{
    xLoc++;

    if(xLoc > xMax-3 )
    {
         xLoc = 1;
         yLoc++;
    }

}
//-----------------------------------------------------------------------------------------------------
int cursor::getmv()
{
    int choice = wgetch(curwin); // optiene el caracter presionado en teclado
    this->numeroCaracter = choice; // se lo asigna al puntero como numero de caracter
    this->caracter = choice; // se lo asigna al puntero como caracter a imprimir
    return choice; //retorna el codigo ascii del caracter presionado

}
//-----------------------------------------------------------------------------------------------------
//metodo que imprime el caracter que tiene el cursor en la cordenada y,x
void cursor::display()
{
    mvwaddch(curwin,yLoc,xLoc,caracter);
}
//-----------------------------------------------------------------------------------------------------
void cursor::movimientos()
{

}
//metodos getters******************************************************************************************************************

int cursor::getxLoc()
{
    return this->xLoc;
}
//-----------------------------------------------------------------------------------------------------
int cursor::getyLoc()
{
    return this->yLoc;
}
//-----------------------------------------------------------------------------------------------------
int cursor::getxMax()
{
    return this->xMax;
}
//-----------------------------------------------------------------------------------------------------
int cursor::getyMax()
{
    return this->yMax;
}
//-----------------------------------------------------------------------------------------------------
char cursor::getCaracter()
{
    return this->caracter;
}

//*********************************************************************************************************************************
//setters
void cursor::settxLoc(int x)
{
    this->xLoc = x;
}
//-----------------------------------------------------------------------------------------------------
void cursor::settyLoc(int y)
{
    this->yLoc = y;
}
//-----------------------------------------------------------------------------------------------------
void cursor::settCaracter(char c)
{
    this->caracter = c;
}

//*********************************************************************************************************************************
