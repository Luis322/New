#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Persona.h"

class Administrativo:public Persona
{
    public:
        Administrativo(string,int,string);
        void info();

    protected:

    private:
        string cargo;
};

#endif // ADMINISTRATIVO_H
