#include <iostream>

using namespace std;
class Polygon{
    protected:
        int width,height;
    public:
        Polygon(){
            width=1;
            height=1;
        }
        Polygon(int a,int b):width(a),height(b){}

        int area(){};

        void printArea(){
            cout<<this->area()<<'\n';
        }
        int getW(){return width;}
        int getH(){return height;}

};
class Triangle:Polygon{
    public:
        Triangle(int a, int b):Polygon(a,b){}
        int area(){
            return (width*height/2);
        }


};
class Rectangle:Polygon{
    public:
        Rectangle(int a, int b):Polygon(a,b){}
        int area(){
            return (width*height);
        }

};
class ArrayPolygon{
    Polygon **data;
    int size_;
    public:
        ArrayPolygon(){
            this->size_=0;
            this->data=new Polygon*[0];
        }

        ArrayPolygon(Polygon arr[],int size_){
            //size_=0;
            this->data = new Polygon*[size_];
            //for(int i=0;i<size_;i++)
                //this->data[i]=arr[i];
        }
        setSize(int size_){this->size_=size_;}

        void insertFinal(Polygon n){
            size_+=1;
            Polygon **p=new Polygon*[size_];
            for(int i=0;i<size_-1;i++)
                *p[i]=*data[i];
            *p[size_-1]=n;
            delete data;
            data=p;

        }
        void insertPos(Polygon n,int pos){
            size_+=1;
            Polygon **p=new Polygon*[size_];
            bool j=false;
            for(int i=0;i<size_;i++){
                if(i==pos){
                    j=true;
                    *p[i]=n;
                    continue;
                }
                if(j){
                    *p[i]=*data[i-1];
                }else{
                    *p[i]=*data[i];
                }
            }
            delete[] data;
            data=p;
		}
		void eliminarPos(int pos){
            size_-=1;
            Polygon **p=new Polygon*[size_];
            bool j=false;
            for(int i=0;i<size_;i++){
                if(i==pos){
                    j=true;
                }
                if(j){
                    *p[i]=*data[i+1];
                }else{
                    *p[i]=*data[i];
                }
            }
            delete[] data;
            data=p;

		}
        ~ArrayPolygon(){
            delete[] this->data;
        }

};
int main()
{
    Triangle poly1(1,2);
    Rectangle poly2(3,4);
    int numPoly,w,h;
    //Polygon *arrPoly;
    cout<<"Digite el numero de Polygonos"<<endl;
    cin>>numPoly;
    Polygon *t;

    Polygon *array;
    ArrayPolygon(array,numPoly);
    //Polygon *P->area();

    //Polygon *q=&poly2;
    //Polygon arr[]={arr};
    //Polygon **p
    //ArrayPolygon arr[]={poly1,poly2};

    //ArrayPolygon(arr,numPoly);



    /*for(int i=0;i<numPoly;i++){
        if(i%2){
            cout<<"Ingrese Triangulo"<<endl;
            cin>>w;
            cin>>h;
            arrPoly[i]=Triangle(w,h):Polygon(w,h);
        }else{
            cout<<"Ingrese Rectangulo"<<endl;
            cin>>w;
            cin>>h;
            arrPoly[i]=Rectangle(w,h);
        }
    }*/


    return 0;
}
