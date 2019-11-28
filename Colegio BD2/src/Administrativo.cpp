#include "Administrativo.h"
#include "Persona.h"
#include <string>
#include <iostream>

Administrativo::Administrativo():Persona()
{
    cargo="nNULL";
}

Administrativo::Administrativo(string _nombre, string _apellido, int _edad, string _cargo):Persona(mayus(_nombre),mayus(_apellido),_edad)
{
    cargo=mayus(_cargo);
}

string Administrativo::getCargo(){return cargo;}
void Administrativo::setCargo(string _cargo){cargo=_cargo;}

void Administrativo::info()
{
    cout<<"NOMBRE: "<<this->getNombre()<<", "<<this->getApellido()<<endl;
    cout<<"EDAD: "  <<this->getEdad()<<endl;
    cout<<"CARGO: " <<this->getCargo()<<endl;
}
