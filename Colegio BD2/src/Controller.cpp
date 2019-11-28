#include "Controller.h"
#include "Colegio.h"
#include <cstring>
#include <iostream>
void Controller::opcion(int a){
    string nombre,apellido;
    int edad,grado;
    int pos;
    int menu;

    if(a==1){
        Col.burbuja();
    }
    if(a==2){
        string nombre, apellido;
        cout<<"Ingresa nombre: ";cin>>nombre;
        cout<<"Ingresa apellido: ";cin>>apellido;
        cout<<"Ingresa edad: ";cin>>edad;
        cout<<"Ingrese grado: ";cin>>grado;
        Col.agregar(nombre,apellido,edad,grado);
    }
    if(a==3){
        //Col.imprimir();
        cout<<"INGRESA POSICION: ";cin>>pos;
        if(Col.getTamanio() >= pos){
            cout<<"INGRESA NUEVO NOMBRE: ";cin>>nombre;
            cout<<"INGRESA NUEVO APELLIDO: ";cin>>apellido;
            cout<<"INGRESA LA NUEVA EDAD: ";cin>>edad;
            cout<<"INGRESA NUEVO GRADO: ";cin>>grado;
            Col.cambiar(nombre,apellido,edad,grado,pos-1);
        }
    }
    if(a==4){
        Col.imprimir();
        cout<<"ingresa la posicion: ";cin>>pos;
        Col.borrar(pos);
    }
    if(a==5){
        cout<<"ingresa el apellido de la persona: ";cin>>apellido;
        Col.buscar_relacion(apellido);

    }
    if(a==6){

        Col.imprimir();

    }

}
void Controller::opcion1(int a){
    string nombre,apellido,cargo;
    int edad;
    int pos;
    int menu;

    if(a==1){

        Col.burbuja1();


    }
    if(a==2){

        cout<<"Ingresa nombre: ";cin>>nombre;
        cout<<"Ingresa apellido: ";cin>>apellido;
        cout<<"Ingresa edad: ";cin>>edad;
        cout<<"Ingrese cargo: ";cin>>cargo;
        Col.agregar(nombre,apellido,edad,cargo);
    }
    if(a==3){
        //Col.imprimir();
        cout<<"INGRESA POSICION: ";cin>>pos;
        if(Col.getTamanio() >= pos){
            cout<<"INGRESA NUEVO NOMBRE: ";cin>>nombre;
            cout<<"INGRESA NUEVO APELLIDO: ";cin>>apellido;
            cout<<"INGRESA LA NUEVA EDAD: ";cin>>edad;
            cout<<"INGRESA NUEVO CARGO: ";cin>>cargo;
            Col.cambiar(nombre,apellido,edad,cargo,pos-1);
        }
    }
    if(a==4){
        Col.imprimir();
        cout<<"ingresa la posicion: ";cin>>pos;
        Col.borrar(pos,1);
    }
    if(a==5){
        cout<<"ingresa el apellido de la persona: ";cin>>apellido;
        Col.buscar_relacion1(apellido);

    }
    if(a==6){

        Col.imprimir(1);

    }
}
