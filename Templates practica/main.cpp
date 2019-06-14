#include <iostream>

using namespace std;

template <class T>
class Point {
    private:
        T x, y;
    public:
        Point(const T u, const T v) : x(u), y(v) {}
        T getX() { return x; }
        T getY() { return y; }
        Point<T> operator+(const Point<T> o) {
            Point<T> tmp(0, 0);
            tmp.x = x + o.x;
            tmp.y = y + o.y;
            return tmp;
        }
        void print(){
            cout<<getX()<<endl;
            cout<<getY()<<endl;
        }

};


template<class T>
class DinamicArray {
    T *data;
    int size;
    void resize(int newSize) {
        T *arr = new int[size];
        int minSize = (newSize > size ? newSize : newSize);
        for(int i = 0; i < minSize; i++){
            arr[i]=data[i];
        }
        delete[] data;
        this->size = newSize;
        data = arr;
    }
    public:
        DinamicArray() {
            data = new int[0];
            this->size = 0;
        }
        DinamicArray(int arr[], int size) {
            this->data = new T[size];
            this->size = size;
            for (int i = 0; i < size; ++i)
                data[i] = arr[i];
        }
        DinamicArray(DinamicArray &o) {
            data = new int[o.size];
            size = o.size;
            for (int i = 0; i < size; ++i)
                data[i] = o.data[i];
        }

        T push_back(int val) {
            resize(size + 1);
            this->data[size-1] = val;
        }

        T insert(const int val, int pos) {
            resize(size + 1);

            for( int i = size; i > pos; i--){
                data[i]= data[i-1];
            }
            data[pos] = val;
        }

        T remove(int pos) {
            if(pos >= 0 && pos < size) {
                for(int i=pos; i<size-1; i++)
                {
                    data[i] = data[i+1];
                }
                resize(size - 1);
            }
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


        ~DinamicArray() {
            delete[] data;
        }
};


/*ostream& operator<<(ostream& output, const Point&o){
            output<<o.getX()<<","<<o.getY()<<endl;
            return output;
        }*/
template <typename T>
T sum(const T a, const T b) {
    return a + b;
}



int main() {
    int arr[] = {1,2,3,4,5};
    DinamicArray<int> a(arr, 5);
    Point <int> p1(1,2);
    Point <int> p2(3,4);
    Point <int> arr2[] = {p1,p2};
    DinamicArray<Point>;
    a.push_back(6);
    a.print();
    a.insert(10,5);
    a.print();
    a.remove(5);
    a.print();
    //cout << a.getSize() << endl; // 4


}
