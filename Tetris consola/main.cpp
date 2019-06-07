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
    cout<<"XXXXXXXXXXXXXX"<<"    "<<"SIGUIENTE PIEZA"<<endl;
    cout<<"X            X"<<"    "<<"  XXXXXXXX"<<endl;
    cout<<"X            X"<<"    "<<"  X      X"<<endl;
    cout<<"X            X"<<"    "<<"  X      X"<<endl;
    cout<<"X            X"<<"    "<<"  X      X"<<endl;
    cout<<"X            X"<<"    "<<"  XXXXXXXX"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<"      PUNTOS:"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<"      NIVEL:"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"X            X"<<endl;
    cout<<"XXXXXXXXXXXXXX"<<endl;
}


int main()
{
    system("color 1F");
    Tetromino T;
    tablero();
    int x=6, y=2;
    gotoxy(x,y);T.Dibujar();
    bool game_over=false;

    while (!game_over){

        if (kbhit()){
            char tecla = getch();
            gotoxy(x,y);T.DibujarOff();
            if(tecla=='j');x--;
            if(tecla=='l');x++;
            if(tecla=='i');y--;
            if(tecla=='k');x++;
            gotoxy(x,y);T.Dibujar();
        }
    Sleep(50);
    }

    return 0;
}
