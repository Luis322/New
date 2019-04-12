#include <iostream>
#include "Empleado.h"
using namespace std;
/////////////POBLEMA 1////////////////
int Sum_Multi(int n, int sum=0){
    for (int i=3;i<n;i++){
        if(i%3==0 || i%5==0)
            sum+=i;
    }
    return sum;
}
////////////PROBLEMA 2//////////////////
int impares(int n){
    for(int i=1;i<=n;i++){
        if(i%2){
            if(i<n)
                cout<<i<<",";
            else
                cout<<i;
        }
    }
}
////////////PROBLEMA 3////////////////
bool esPrimo(long long n,int i=2){
    if (n==2)
        return true;
    for(;i<n;i++){
        if(!(n%i))
            return false;
    }
    return true;
}
int Primos(int n,int i=2){
    for(;i<=n;i++)
        if(esPrimo(i))
            cout<<i<<endl;
}
///////////PROBLEMA 4////////////////


///////////PROBLEMA 5//////////////
long long factor(long long n,long long cont=0){

    for (long long i=2;i<=n;i++){
        if(cont==n)
            return cont;
        if(cont<=n){
            if(esPrimo(i)){
                cont*=i;
            }
        }
    }


}

int main()
{
    //cout << Sum_Multi(1000) << endl;//PROBLEMA 1
    //impares(11);//PROBLEMA 2
    //cout<<esPrimo(600851475143);
    //Primos(20);
    //cout<<factor(600851475143);
    Empleado emp1;
    Empleado emp2;
    cout<<emp1.getNombre()<<endl;
    cout<<emp1.getApellido()<<endl;
    cout<<emp1.getSalario()<<endl;
    emp1.setSalario(100);
    cout<<emp1.getSalario()<<endl;
    emp1.aumentarSal();
    cout<<emp1.getSalario();
    return 0;
}
