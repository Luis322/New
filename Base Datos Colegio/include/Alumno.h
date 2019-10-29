#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"

class Alumno:public Persona
{
    public:
        Alumno();
        void info();


    protected:

    private:
        int grado;
};

#endif // ALUMNO_H
