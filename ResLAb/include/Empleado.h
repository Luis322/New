#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>
using namespace std;
class Empleado
{
    public:
        Empleado()
        {
            nombre="nomb";
            salario =0;
            apellido="apell";
        }

        Empleado(string _nombre,string _apellido,int _salario){
            nombre=_nombre;
            apellido=_apellido;
            salario=_salario;
        }
        void setNombre(string _nombre){
            nombre=_nombre;}
        void setApellido(string _apellido){
            apellido=_apellido;}
        void setSalario(int _salario){
            salario=_salario;}
        string getNombre(){
            return nombre;}
        string getApellido(){
            return apellido;}
        int getSalario(){
            return salario;}
        int aumentarSal(){
            salario*=1.1;}



    private:
        string nombre;
        string apellido;
        int salario;
};

#endif // EMPLEADO_H
