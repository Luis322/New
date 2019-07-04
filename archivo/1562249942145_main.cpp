#include <iostream>

using namespace std;
template <typename T>
class Complejo{
    T real;
    T imaginario;
    public:
        Complejo(){
            real=0;
            imaginario=0;
        }
        Complejo(T a,T b):real(a),imaginario(b){}

        int getA(){return real;}
        int getB(){return imaginario;}
        void setA(int a){real=a;}
        void setB(int b){imaginario=b;}
        /*ostream& operator +(Complejo <T>&a,Complejo <T>&b){
            Complejo M;
            int p=a.getA()+b.getA();
            int q=a.getB()+b.getB();
            M.setA(p);
            M.setB(q);
            return ostream;

        }*/

};
template <typename T>
class DynamicArray {
    T *data;
    int size;
public:
    DynamicArray() {
        data = new T[0];
        this->size = 0;
    }

    DynamicArray(T arr[], int size) {
        this->data = new T[size];
        this->size = size;
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
    }

    DynamicArray(DynamicArray &o) {
        data = new T[o.size];
        size = o.size;
        for (int i = 0; i < size; ++i)
            data[i] = o.data[i];
    }

    void resize(int newsize){
        T *ptr = new T[newsize];
        int minsize = (newsize > size)?size:newsize;
        for(int i = 0; i < minsize; i++)
            ptr[i] = data[i];
        delete[] data;
        size = newsize;
        data = ptr;
    }

    void push_back(T val) {
        resize(size + 1);
        data[size - 1] = val;
    }

    void insert(T val, int pos) {
        resize(size + 1);
        for(int i = size-1; i > pos; i--)
            data[i] = data[i-1];
        data[pos] = val;
    }

    void remove(int pos) {
        for(int i=pos; i<size-1; i++)
            data[i] = data[i+1];
        resize(size-1);
    }

    void print() {
        for(int i =0; i < size; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }

    ~DynamicArray() {
        delete[] data;
    }
};

template<typename T>
ostream& operator << (ostream &ostream,Complejo<T> &p){
    ostream <<"("<<p.getA()<<","<<p.getB()<<")";
    return ostream;
}
///Sobrecarga operador +
template<typename T>
Complejo<T>& operator + (Complejo<T> &p,Complejo<T> &q){

    return *(new Complejo<T>(p.getA()+q.getA(),p.getB()+q.getB()));
}
///Sobrecarga operador -
template<typename T>
Complejo<T>& operator - (Complejo<T> &p,Complejo<T> &q){

    return *(new Complejo<T>(p.getA()-q.getA(),p.getB()-q.getB()));
}
///Sobrecarga operador *
template<typename T>
Complejo<T>& operator * (Complejo<T> &p,Complejo<T> &q){
    int m=p.getA()*q.getA()+p.getB()*q.getB();
    int n=p.getB()*q.getA()-p.getA()*q.getB();
    return *(new Complejo<T>(m,n));
}
///Sobrecarga operador * escalar
template<typename T>
Complejo<T>& operator * (int p,Complejo<T> &q){

    return *(new Complejo<T>(p*q.getA(),p*q.getB()));
}
///Sobrecarga operador /
template<typename T>
Complejo<T>& operator / (Complejo<T> &p,Complejo<T> &q){
    int m=p.getA()*q.getA()+p.getB()*q.getB();
    int n=p.getB()*q.getA()-p.getA()*q.getB();
    int d=q.getA()*q.getA()+q.getB()*q.getB();

    return *(new Complejo<T>(m/d,n/d));
}
int main()
{
    /*Complejo<double> A(-5,5);
    //cout<<A<<endl;
    Complejo<double> B(2,-6);
    cout<<A*B<<endl;
    cout<<2*A<<endl;*/
    Complejo<double> A(-5,5);

    Complejo<double> arrComp[2] ={A,A};
    DynamicArray <Complejo<double> >Complejos(arrComp, 2);
    Complejos.print();
    Complejo<double> B(2,-6);
    Complejos.insert(B,0);
    Complejos.print();
    return 0;
}
