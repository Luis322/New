#include "Alumno.h"
#include "Persona.h"
#include <string>
#include <iostream>
//using namespace std;

Alumno::Alumno():Persona()
{
    promedio = 0;
    grado=0;
}
Alumno::Alumno(string _nombre, string _apellido, int _edad, int _grado):Persona(mayus(_nombre),mayus(_apellido),_edad)
{
    grado=_grado;

}
int Alumno::getGrado(){return grado;}
void Alumno::setGrado(int _grado){grado=_grado;}
void Alumno::info()
{
    cout<<"NOMBRE: "<<this->getNombre()<<", "<<this->getApellido()<<endl;
    cout<<"EDAD: "  <<this->getEdad()<<endl;
    cout<<"GRADO: " <<this->getGrado()<<endl;
}
