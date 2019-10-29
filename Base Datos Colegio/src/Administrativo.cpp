#include "Administrativo.h"

Administrativo::Administrativo()
{
    nombre="NULL";
    edad = 00;
    codigo = 0;
    grado=0;
}
Administrativo::Administrativo(string _nombre,int _edad,string _cargo):Persona(_nombre,_edad)
{
    cargo=_cargo;
}
void Administrativo::info()
{
    cout<<nombre<<endl;
    cout<<edad<<endl;
    cout<<cargo<<endl;
}

