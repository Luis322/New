#include "Colegio.h"

///PUBLIC ////////////////////////////////////////
Colegio::Colegio()
{
    tamanio = 0;
    tamanio1=0;
    bool b=true;
    bool d=true;
    int cont=1;
    int cont1=1;
    Lectura(b,tamanio,cont);
    Lectura(d,tamanio1,cont1,1);


}
void Colegio::agregar(string nuevonombre,string nuevoapellido,int nuevaedad,int nuevogrado)
{
    Alumno *nuevo= new Alumno[tamanio+1];
    for(int i=0;i<tamanio;i++){
        nuevo[i]=a[i];
    }
    tamanio++;
    nuevo[tamanio-1].setNombre(mayus(nuevonombre));
    nuevo[tamanio-1].setApellido(mayus(nuevoapellido));
    nuevo[tamanio-1].setEdad(nuevaedad);
    nuevo[tamanio-1].setGrado(nuevogrado);
    delete [] a;
    a=nuevo;
    mod_arch(convertiratexto(getTamanio()),nuevonombre,nuevoapellido,nuevaedad,nuevogrado);
}
void Colegio::agregar(string nuevonombre,string nuevoapellido,int nuevaedad,string nuevocargo)
{
    Administrativo *nuevo= new Administrativo[tamanio1+1];
    for(int i=0;i<tamanio1;i++){
        nuevo[i]=b[i];
    }
    tamanio1++;
    nuevo[tamanio1-1].setNombre(mayus(nuevonombre));
    nuevo[tamanio1-1].setApellido(mayus(nuevoapellido));
    nuevo[tamanio1-1].setEdad(nuevaedad);
    nuevo[tamanio1-1].setCargo(mayus(nuevocargo));
    delete [] b;
    b=nuevo;
    mod_arch(convertiratexto(getTamanio1()),nuevonombre,nuevoapellido,nuevaedad,nuevocargo);
}
void Colegio::borrar(int posicion)
{
    Alumno *nuevo= new Alumno[tamanio-1];
    tamanio--;
    for(int i=0;i<posicion-1;i++){
        nuevo[i]=a[i];
    }
    for(int i=posicion-1;i<tamanio;i++){
        nuevo[i]=a[i+1];
    }
    delete [] a;
    a=nuevo;
}
void Colegio::borrar(int posicion,int p)
{
    Administrativo *nuevo= new Administrativo[tamanio1-1];
    tamanio1--;
    for(int i=0;i<posicion-1;i++){
        nuevo[i]=b[i];
    }
    for(int i=posicion-1;i<tamanio1;i++){
        nuevo[i]=b[i+1];
    }
    delete [] b;
    b=nuevo;
}
void Colegio::cambiar(string nombre,string apellido, int edad, int grado, int pos)
{
    a[pos].setEdad(edad);
    a[pos].setNombre(mayus(nombre));
    a[pos].setApellido(mayus(apellido));
    a[pos].setGrado(grado);
    mod_arch(convertiratexto(pos+1),nombre,apellido,edad,grado);
}
void Colegio::cambiar(string nombre,string apellido, int edad, string cargo, int pos)
{
    b[pos].setEdad(edad);
    b[pos].setNombre(mayus(nombre));
    b[pos].setApellido(mayus(apellido));
    b[pos].setCargo(mayus(cargo));
    mod_arch(convertiratexto(pos+1),nombre,apellido,edad,cargo);
}
void Colegio::imprimir(){
    for(int i=0;i<tamanio;i++){
        cout<<"///////////////////////////////////"<<endl;
        cout<<"POSICION: "<<i+1<<endl;
        /*cout<<"Nombre: "<<a[i].getNombre()<<" ";
        cout<<a[i].getApellido()<<endl;
        cout<<"EDAD: "<<a[i].getEdad()<<endl;
        cout<<"GRADO: "<<a[i].getGrado()<<endl;*/
        a[i].info();
        cout<<"///////////////////////////////////"<<endl;
    }
}
void Colegio::imprimir(int m){
    for(int i=0;i<tamanio1;i++){
        cout<<"///////////////////////////////////"<<endl;
        cout<<"POSICION: "<<i+1<<endl;
        /*cout<<"Nombre: "<<b[i].getNombre()<<" ";
        cout<<b[i].getApellido()<<endl;
        cout<<"EDAD: "<<b[i].getEdad()<<endl;
        cout<<"GRADO: "<<b[i].getGrado()<<endl;*/
        b[i].info();
        cout<<"///////////////////////////////////"<<endl;
    }
}
int Colegio::getTamanio(){return tamanio;}
int Colegio::getTamanio1(){return tamanio1;}

int Colegio::comodin(string a,string b){
    int conta=0;
    mayus(a);
    mayus(b);
    if(lenght(b)<lenght(a)){
        return 0;
    }
    for(int i=0;b[i]!='\0';i++){
        if(b[i]==a[0]){
            for(int j=0;j<lenght(a);j++){
                if(a[j]==b[i+j]){
                    conta++;
                }
            }
            if(conta==lenght(a)){
                return 1;
            }
        }
    }
    return 0;
}
bool Colegio::buscarExacto(string a,string b){
    int conta=0;
    mayus(a);
    mayus(b);
    if(lenght(b)!=lenght(a))
        return 0;
    for(int i=0;b[i]!='\0';i++){
            if(a[i]==b[i])
                conta++;
        if(conta==lenght(a)){
            return 1;
        }
    }

    return 0;
}
void Colegio::buscar_relacion(string apell){
    int pos;
    mayus(apell);
    for(int i=0;i<tamanio;i++){
        if(buscarExacto(apell,a[i].getApellido())){
            cout<<"Encontrado"<<endl;
            cout<<"Nombre: "<<a[i].getNombre()<<" "<<endl;
            cout<<"Apellido: "<<a[i].getApellido()<<endl;
            cout<<"Edad: "<<a[i].getEdad()<<endl;
            pos=i;
            break;
        }
    }
    cout<<"Busquedas relacionadas: "<<endl;
    for(int i=0;i<tamanio;i++){
        if(pos==i){continue;}
        if(comodin(apell,a[i].getApellido())){
            cout<<a[i].getApellido()<<", ";
            cout<<a[i].getNombre()<<endl;;
        }
    }
}
void Colegio::burbuja()
{
    for(int i=0; i<tamanio; i++){
        for (int j=tamanio-1; j>0; j--){
            char buff1[100];
            char buff2[100];
            if(strcmp(strcpy(buff1,a[j].getApellido().c_str()),strcpy(buff2,a[j-1].getApellido().c_str()))<0)
                swap(a[j],a[j-1]);
            /*string cadena = "hola mundo";
            char buffer[100];
            strcpy(buffer,cadena.c_str());
            std::cout << buffer;*/
            ///www.cplusplus.com/reference/cstring/strcmp/ ////// strcmp(char* cad1,char* cad2)
            string nombtemp1=a[j-1].getNombre();
            string apelltemp1=a[j-1].getApellido();
            int edadtemp1=a[j-1].getEdad();
            int gradotemp1=a[j-1].getGrado();

            string nombtemp2=a[j].getNombre();
            string apelltemp2=a[j].getApellido();
            int edadtemp2=a[j].getEdad();
            int gradotemp2=a[j].getGrado();

            mod_arch(convertiratexto(j),nombtemp1,apelltemp1,edadtemp1,gradotemp1);
            mod_arch(convertiratexto(j+1),nombtemp2,apelltemp2,edadtemp2,gradotemp2);
        }
    }
}
// para los admins modificacion
//int Colegio::getTamanio(){return tamanio;} Este no se modifico esta arriba
void Colegio::buscar_relacion1(string apell){
    int pos;
    mayus(apell);
    for(int i=0;i<tamanio1;i++){
        if(buscarExacto(apell,b[i].getApellido())){
            cout<<"Encontrado"<<endl;
            cout<<"Nombre: "<<b[i].getNombre()<<" "<<endl;
            cout<<"Apellido: "<<b[i].getApellido()<<endl;
            cout<<"Edad: "<<b[i].getEdad()<<endl;
            pos=i;
            break;
        }
    }
    cout<<"Busquedas relacionadas: "<<endl;
    for(int i=0;i<tamanio1;i++){
        if(pos==i){continue;}
        if(comodin(apell,b[i].getApellido())){
            cout<<b[i].getApellido()<<", ";
            cout<<b[i].getNombre()<<endl;;
        }
    }
}
void Colegio::burbuja1()
{
    for(int i=0; i<tamanio1; i++){
        for (int j=tamanio1-1; j>0; j--){
            char buff1[100];
            char buff2[100];
            if(strcmp(strcpy(buff1,b[j].getApellido().c_str()),strcpy(buff2,b[j-1].getApellido().c_str()))<0)
                swap(b[j],b[j-1]);
            /*string cadena = "hola mundo";
            char buffer[100];
            strcpy(buffer,cadena.c_str());
            std::cout << buffer;*/
            ///www.cplusplus.com/reference/cstring/strcmp/ ////// strcmp(char* cad1,char* cad2)
            string nombtemp1=b[j-1].getNombre();
            string apelltemp1=b[j-1].getApellido();
            int edadtemp1=b[j-1].getEdad();
            string cargotemp1=b[j-1].getCargo();

            string nombtemp2=b[j].getNombre();
            string apelltemp2=b[j].getApellido();
            int edadtemp2=b[j].getEdad();
            string cargotemp2=b[j].getCargo();

            mod_arch(convertiratexto(j),nombtemp1,apelltemp1,edadtemp1,cargotemp1);
            mod_arch(convertiratexto(j+1),nombtemp2,apelltemp2,edadtemp2,cargotemp2);
        }
    }
}
///PROTECTED ////////////////////////////////////////////
int Colegio::lenght(string a){
    int cont=0;
    for(int i=0;a[i]!='\0';i++){
        cont++;
    }
    return cont;
}
string Colegio::mayus(string &cad)
{

    for(int i=0;i<cad.length();i++)
        cad[i]=towupper(cad[i]);
    return cad;
}
int Colegio::conv_char(char a)
{
    return a-'0';
}
char Colegio::p_l(string a,int i){
    return a[i];
}
char Colegio::p_l1(string b,int i,int p){
    return b[i];
}
void Colegio::swap(Alumno &a, Alumno &b)
{
    Alumno temp=a;
    a=b;
    b=temp;
}
void Colegio::swap(Administrativo &a, Administrativo &b)
{
    Administrativo temp=a;
    a=b;
    b=temp;
}
void Colegio::swap1(Administrativo &c, Administrativo &d)
{
    Administrativo temp=c;
    c=d;
    d=temp;
}

string Colegio::convertiratexto(float f){
    stringstream ss;
	ss << f;
	return ss.str();
}
int Colegio::convertiranumero(string texto1){
	int number;
	number = atof(texto1.c_str());
	return number;
}
void Colegio::mod_arch(string arch,string nomb="NULL",string apell="NULL",int edad=0,int grad=0){
    string nameArchivo=arch;
    nameArchivo += ".txt";
    ofstream fs(nameArchivo.c_str());
    fs <<nomb<<endl;
    fs <<apell<<endl;
    fs <<edad<<endl;
    fs <<grad<<endl;
    fs.close();
}
void Colegio::mod_arch(string arch,string nomb="NULL",string apell="NULL",int edad=0,string carg="NULL"){
    string nameArchivo=arch;
    nameArchivo += "A.txt";
    ofstream fs(nameArchivo.c_str());
    fs <<nomb<<endl;
    fs <<apell<<endl;
    fs <<edad<<endl;
    fs <<carg<<endl;
    fs.close();
}
string Colegio::obt_linea(string x,int y){
    ifstream archivo_entrada(x.c_str());
    string linea;
    int contador = 0;
    while(getline(archivo_entrada, linea)) {
        if(y==contador) {
            return linea;
        }
        contador++;
    }
}

void Colegio::Lectura(bool m,int &tamanio,int cont){
    while(m==true){
        string nameArchivo=convertiratexto(cont);
        nameArchivo += ".txt";
        ifstream fs(nameArchivo.c_str(),ios :: in);
        if(fs.fail()){
            m=false;
            tamanio--;
        }
        tamanio++;
        fs.close();
        cont++;
    }
    a=new Alumno[tamanio];
    for(int i=1;i<=tamanio;i++){
        string nameArchivo=convertiratexto(i);
        nameArchivo += ".txt";
        ifstream fs(nameArchivo.c_str(),ios :: in);
        a[i-1].setNombre(obt_linea(nameArchivo,0));
        ////////////////////
        a[i-1].setApellido(obt_linea(nameArchivo,1));
        ///////////////////
        string temp1=obt_linea(nameArchivo,2);
        a[i-1].setEdad(convertiranumero(temp1));
        ///////////////////
        string temp2=obt_linea(nameArchivo,3);
        a[i-1].setGrado(convertiranumero(temp2));
        //////////////////
        fs.close();
    }
}
void Colegio::Lectura(bool m,int &tamanio , int cont, int x){
    while(m==true){
        string nameArchivo=convertiratexto(cont);
        nameArchivo += "A.txt";
        ifstream fs(nameArchivo.c_str(),ios :: in);
        if(fs.fail()){
            m=false;
            tamanio--;
        }
        tamanio++;
        fs.close();
        cont++;
    }
    b=new Administrativo[tamanio];
    for(int i=1;i<=tamanio;i++){
        string nameArchivo=convertiratexto(i);
        nameArchivo += "A.txt";
        ifstream fs(nameArchivo.c_str(),ios :: in);
        b[i-1].setNombre(obt_linea(nameArchivo,0));
        ////////////////////
        b[i-1].setApellido(obt_linea(nameArchivo,1));
        ///////////////////
        string temp1=obt_linea(nameArchivo,2);
        b[i-1].setEdad(convertiranumero(temp1));
        ///////////////////
        string temp2=obt_linea(nameArchivo,3);
        b[i-1].setCargo(temp2);
        //////////////////
        fs.close();
    }
}
/// ///////////////////////////////////////////
Colegio::~Colegio()
{
    delete []a;
    delete []b;
}
