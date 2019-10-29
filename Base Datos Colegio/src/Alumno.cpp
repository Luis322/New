#include "Alumno.h"

Alumno::Alumno()
{
    nombre="NULL";
    edad = 00;
    codigo = 0;
    grado=0;
}
Alumno::Alumno(string _nombre,int _edad, int _grado):Persona(_nombre,_edad),grado(_grado){}
{
    grado=_grado; 
}
void Alumno::info()
{
    cout<<nombre<<endl;
    cout<<edad<<endl;
    cout<<grado<<endl;
}
    

