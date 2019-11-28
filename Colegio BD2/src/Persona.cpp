#include "Persona.h"
#include "Alumno.h"

Persona::Persona()
{
    nombre="nNULL";
    apellido="aNULL";
}
Persona::Persona(string _nombre, string _apellido, int _edad)
{
    nombre=_nombre;
    apellido=_apellido;
    edad=_edad;
}
string Persona::getNombre(){return nombre;}
string Persona::getApellido(){return apellido;}
int Persona::getEdad(){return edad;}

void Persona::setNombre(string _nombre)
{
    nombre=_nombre;
}
void Persona::setApellido(string _apellido)
{
    apellido=_apellido;
}

void Persona::setEdad(int a)
{
    edad=a;
}
string Persona::mayus(string &cad)
{

    for(int i=0;i<cad.length();i++)
        cad[i]=towupper(cad[i]);
    return cad;
}
