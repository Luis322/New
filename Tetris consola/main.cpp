#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "Tetromino.h"
//using namespace std;

HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
COORD PointPos;

void gotoxy(int x, int y){
    PointPos.X = x;
    PointPos.Y = y;
    SetConsoleCursorPosition(console, PointPos);
}
void tablero(){
    cout<<endl;
    cout<<" XXXXXXXXXXXXXX"<<"    "<<"SIGUIENTE PIEZA"<<endl;
    cout<<" X            X"<<"    "<<"  XXXXXXXX"<<endl;
    cout<<" X            X"<<"    "<<"  X      X"<<endl;
    cout<<" X            X"<<"    "<<"  X      X"<<endl;
    cout<<" X            X"<<"    "<<"  X      X"<<endl;
    cout<<" X            X"<<"    "<<"  XXXXXXXX"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<"      PUNTOS:"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<"      NIVEL:"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" X            X"<<endl;
    cout<<" XXXXXXXXXXXXXX"<<endl;
}


int main()
{
    system("color 1F");
    Tetromino T;
    tablero();
    int x=6, y=10;
    gotoxy(x,y);T.Dibujar();
    bool game_over=false;

    while (!game_over){

        if (kbhit()){
            char tecla = getch();

            switch(tecla){
                case 'a':
                    gotoxy(x,y);T.DibujarOff();
                    x--;
                    gotoxy(x,y);T.Dibujar();
                case 'd':
                    gotoxy(x,y);T.DibujarOff();
                    x++;
                    gotoxy(x,y);T.Dibujar();
                case 'w':
                    gotoxy(x,y);T.DibujarOff();
                    y--;
                    gotoxy(x,y);T.Dibujar();
                case 's':
                    gotoxy(x,y);T.DibujarOff();
                    y++;
                    gotoxy(x,y);T.Dibujar();
                case 'j':
                    gotoxy(x,y);T.DibujarOff();
                    T.Rotacion();


            }
                        //if(tecla=)
        }
    Sleep(50);
    }

    return 0;
}
