#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Persona.h"
#include <string>
using namespace std;

class Administrativo:public Persona
{
    public:
        Administrativo();
        Administrativo(string,string,int,string);

        string getCargo();
        void setCargo(string);

        void info();

    protected:

    private:
        string cargo;
};

#endif // ADMINISTRATIVO_H
