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
    cout<<"[";
    for(int i=0;i<len;i++){

        cout<<"("<<a->getX()<<","<<a->getY()<<")";
        if(i<len-1)
            cout<<",";
        *a++;
    }
    cout<<"]"<<endl;
}
void invertir(int a[], int len){
    int *b=&a[len-1];
    for (int i=0;i<(len/2);i++){
        swap(*a,*b);
        /*int m=*a;
        *a=*b;
        *b=m;*/
        a++;
        b--;
    }
}
void invertir1(int a[],int len){
    int *b=a+len-1;
    for(;b>a;a++,b--)
        swap(a,b);
}
void inverRecu(int a[], int len){
    if(len==1)
        return ;
    swap(a++,(a+len-1));
    inverRecu(a,len-2) ;

}

int main()
{
    int a=1;
    int b=2;
    swap(&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    int arr[5]={1,2,3,4,5};
    cout<<sumRec(arr,5)<<endl;
    Point m(1,2),n(3,4),o(5,6),p(7,8);
    Point arrp[4]={m,n,o,p};
    printPoint(arrp,4);
    //invertir(arr,5);
    //invertir1(arr,5);
    inverRecu(arr,5);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;


    return 0;
}
