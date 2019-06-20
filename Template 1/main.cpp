#include <iostream>

using namespace std;

// ___ Dynamic Array with Templates ___ //

template <typename T>
class Point {
    T x, y;
public:
    Point(const T a = 0, const T b = 0) : x(a), y(b) {}
    T getX();
    T getY();
};

template <typename T>
T Point<T>::getX() {
    return x;
}

template <typename T>
T Point<T>::getY() {
    return y;
}

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

template <typename T>
ostream& operator << (ostream &ostream, Point<T> &p)
{
    ostream << "(" << p.getX() << "," << p.getY() << ")";
    return ostream;
}

int main() {
    int arr[] = {1,2,3,4,5};
    DynamicArray<int> a(arr, 5);
    a.push_back(6);
    a.print();
    a.insert(10,5);
    a.print();
    a.remove(5);
    a.print();

    Point<int> arrPoints[2] = {Point<int>(2,3), Point<int>(4,5)};

    DynamicArray<Point<int> > Points(arrPoints, 2);
    Point<int> p(2,9);
    
    Points.print();
    Points.push_back(p);
    Points.print();
}

