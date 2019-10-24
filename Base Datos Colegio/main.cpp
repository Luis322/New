#include <iostream>
#include "Persona.h"
#include "Alumno.h"
using namespace std;

int main()
{
    Persona A;
    Persona *B=&A;
    //Persona A("Edgar",21);
    cout<<B->getNombre()<<endl;
    cout<<B->getEdad()<<endl;
    B->setNombre("Luis");
    B->setEdad(20);
    cout<<endl;
    cout<<B->getNombre()<<endl;
    cout<<B->getEdad()<<endl;




    return 0;
}
