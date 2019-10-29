#ifndef PERSONA_H
#define PERSONA_H
using namespace std;
#include <string>

class Persona
{
    public:
        Persona();
        Persona(string,int);
        Persona(const &Persona);
        string getNombre();
        int getEdad();
        int getCodigo();
        void setNombre(string);
        void setEdad(int);
        virtual void info()=0;
        void generarCodigo();




    protected:

    private:
        string nombre;
        int edad;
        int codigo;
};

#endif // PERSONA_H
