#include <iostream>
#include <windows.h>
#include "Colegio.h"
#include "Persona.h"
#include "Alumno.h"
#include "Controller.h"
using namespace std;

int main()
{
     Controller c;

     while(true){
     	int A;
	cout<<"#################################"<<endl;
	cout<<"#  1)ALUMNOS                    #"<<endl;
    cout<<"#  2)ADMINISTRATIVO             #"<<endl;
    cout<<"#  3)SALIR                      #"<<endl;
	cout<<"#################################"<<endl;
	cin>>A;
	system("CLS");

     	if(A==1){
     		while (true){

        		int elec;
        		cout<<"1) ORDENAR ALUMNOS "<<endl;
        		cout<<"2) INGRESAR NUEVO ALUMNO  "<<endl;
       			cout<<"3) MODIFICAR ALUMNO"<<endl;
        		cout<<"4) ELIMINAR ALUMNO "<<endl;
       			cout<<"5) BUSCAR ALUMNO"<<endl;
        		cout<<"6) IMPRIMIR REGISTRO"<<endl;
                cout<<"7) VOLVER AL LOGIN"<<endl;
                cout<<"8) SALIR"<<endl;
        		cin>>elec;
			if(elec==7){
				system("CLS");
				break;
			}
			if(elec==8){
				return 0;
			}
        		c.opcion(elec);
        		system("pause");
        		system("CLS");

		}
     	}
    	else if(A==2){
      	 	 while (true){

        		int elec;
        		cout<<"1) ORDENAR ADMINISTRATIVOS"<<endl;
        		cout<<"2) INGRESAR NUEVO ADMINISTRATIVO"<<endl;
       			cout<<"3) MODIFICAR ADMINISTRATIVO"<<endl;
        		cout<<"4) ELIMINAR ADMINISTRATIVO "<<endl;
       			cout<<"5) BUSCAR ADMINISTRATIVO"<<endl;
        		cout<<"6) IMPRIMIR REGISTRO"<<endl;
                cout<<"7) VOLVER AL LOGIN"<<endl;
                cout<<"8) SALIR"<<endl;
        		cin>>elec;
			if(elec==7){
				system("CLS");

				break;

			}
			if(elec==8){
				return 0;
			}
        		c.opcion1(elec);
        		system("pause");
        		system("CLS");

		}
   	}
	else if(A==3){
		return 0;
		exit(-1);
	}
    }//primer while

    /*Colegio C;
    C.agregar("Luis","adf",24,3);
    C.agregar("Edgard","aca",23,2);
    C.agregar("Lucia","abd",22,1);
    C.agregar("Luis","abc",21,5);
    C.burbuja();
    C.borrar(1);
    C.imprimir();*/



    return 0;
}
