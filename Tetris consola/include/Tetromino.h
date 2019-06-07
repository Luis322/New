#ifndef TETROMINO_H
#define TETROMINO_H
#include <iostream>

using namespace std;

class Tetromino
{
    int x;
    int y;
    public:
        Tetromino(int _x,int _y){
            x=_x;
            y=_y;
        }
        Tetromino(){
            x=0;
            y=0;

        }
        void Dibujar(){
            cout<<"XXXX";
            //cout<<" X "<<endl;
        }
        void DibujarOff(){
            cout<<"    ";
        }
        void Rotacion(){
            cout<<"XXX";
        }
        //~Tetromino();

    protected:

    private:
};

#endif // TETROMINO_H
