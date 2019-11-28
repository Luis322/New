#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string.h>

using namespace std;
class Persona
{
    public:
        Persona();
        Persona(string,string,int);
        string getNombre();
        string getApellido();
        int getEdad();
        int getCodigo();
        void setNombre(string);
        void setApellido(string);
        void setEdad(int);
        string mayus(string &);
        virtual void info()=0;

        void generarCodigo();


    protected:

    private:
        string nombre;
        string apellido;
        int edad;
        int codigo;
};

#endif // PERSONA_H
