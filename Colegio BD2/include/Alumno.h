#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"
#include <string.h>
using namespace std;

class Alumno:public Persona
{
    public:
        Alumno();
        Alumno(string, string, int, int);
        int getGrado();
        void setGrado(int);
        void info();


    protected:

    private:
        int grado;
        float promedio;
};


#endif // ALUMNO_H
