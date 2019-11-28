#ifndef COLEGIO_H
#define COLEGIO_H
#include "Alumno.h"
#include "Administrativo.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
class Colegio
{
    public:
        Colegio();
        void agregar(string, string, int, int);///Alumno
        void agregar(string,string,int,string);///Admin
        void borrar(int);
        void borrar(int,int);
        void cambiar(string,string,int,int,int);
        void cambiar(string,string,int,string,int);
        void imprimir();
        void imprimir(int);
        int getTamanio();
        int getTamanio1();

        int comodin(string, string );
        bool buscarExacto(string, string);
        void buscar_relacion(string);
        void buscar_relacion1(string);

        void burbuja();
        void burbuja1();
        void ord_rank(int);


        ~Colegio();
    protected:
        int lenght(string a);
        int lenght(string a,int p);
        string mayus(string &);
        conv_char(char);
        char p_l(string,int);
        void swap(Alumno&,Alumno&);
        void swap(Administrativo&,Administrativo&);
	//la modificazion :v
        //int lenght1(string,int);
        char p_l1(string,int,int);
        void swap1(Administrativo&,Administrativo&);
	//end
        void mod_arch(string,string,string,int,int);
        void mod_arch(string,string,string,int,string);
        string convertiratexto(float );
        int convertiranumero(string);
        string obt_linea(string,int);

        void Lectura(bool,int&,int);
        void Lectura(bool,int&,int,int);
    private:
        int tamanio;
        int tamanio1;
        Alumno *a;
        Administrativo *b;

};

#endif // COLEGIO_H
