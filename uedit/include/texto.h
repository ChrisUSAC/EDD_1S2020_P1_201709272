#ifndef TEXTO_H
#define TEXTO_H
#include <string>
#include <stdlib.h>

using namespace std;

class texto
{
    public:
        //metodo constructor
        texto(WINDOW * win,int y, int x, char c);
        //metodo destructor
        virtual ~texto();

    protected:WINDOW * curwin;
};

#endif // TEXTO_H
