#include "Persona.h"

Persona::Persona()
{
    nombre="NULL";
    edad=00;
    codigo=NULL;

}
Persona::Persona(string _nom,int _edad)
{
    nombre=_nom;
    edad=_edad;
    codigo=NULL;

}


string Persona::getNombre(){return nombre;}
int Persona::getEdad(){return edad;}

void Persona::setNombre(string _nombre)
{
    nombre=_nombre;
}
void Persona::setEdad(int a)
{
    edad=a;
}
void Persona::generarCodigo()
{

}
