#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ofstream archivo("archivo.txt");
    archivo<<"ciencia de la computacion ciencia de la computacion distribuida\n";
    archivo<<"ciencia de la computacion ciencia de la computacion distribuida\n";
    archivo<<"ciencia de la computacion ciencia de la computacion distribuida\n";
    archivo<<"ciencia de la computacion ciencia de la computacion distribuida\n";
    archivo<<"ciencia de la computacion ciencia de la computacion distribuida\n";
    archivo<<"ciencia de la computacion ciencia de la computacion distribuida\n";

    archivo.close();
    ifstream archivo1("archivo.txt");
    string texto;
    //int line;
    //while(!archivo.eof()){
        getline(archivo1,texto,'\0');
        cout<<texto<<endl;
    //}
    ofstream copia("copia.txt");
    copia<<texto;
    copia.close();
    //line+=1;

    ///convertir string a char*
    char cstr[texto.size() + 1];
	strcpy(cstr, texto.c_str());
	cout<<texto<<endl;
	///contando palabras
    int cont=0;
    for(int i=0;i<texto.size();i++){
        if(cstr[i]==32||cstr[i]=='\n')
            cont+=1;
    }
	cout<<"El archivo tiene "<<cont<<" palabras"<<endl;
    return 0;
}
