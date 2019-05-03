#include <iostream>
#include "Point.h"
using namespace std;

void swap(int *a,int *b){
    int m=*a;
    *a=*b;
    *b=m;
}
int sumRec(int *a,int len){
    if (len<=0)
        return 0;
    //int n=len-1;
    //int *b=&n;
    int *b=a+len--;
    return sumRec(a,len--)+ *b;
}
void printPoint(Point *a,int len){
    for(int i=0;i<len;i++){

        cout<<a->getX()<<endl;
    }
}
/*void invertir(int *a, int len){
    int *b=len;
    for (int i=0;i<len<i++){
        swap(&a,&b);
    }
}*/

int main()
{
    int a=1;
    int b=2;
    swap(&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    int arr[5]={1,2,3,4,5};
    cout<<sumRec(arr,5);
    Point m(1,2),n(3,4),o(5,6),p(7,8);
    Point arrp[]={m,n,o,p};
    return 0;
}
