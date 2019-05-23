#include <iostream>

using namespace std;

class IntegerArray {
		int *data;
        int size_;
    public:
        IntegerArray() {
            this->size_ = 0;
			this->data = new int[0];
        }
		IntegerArray(int arr[], int size_){
			this->size_ = size_;
			this->data = new int[size_];
			for(int i = 0; i < size_; i++){
				this->data[i] = arr[i];
			}
		}
		void insertFinal(int n){
            size_+=1;
            int *p=new int[size_];
            for(int i=0;i<size_-1;i++){
                p[i]=data[i];
            }
            p[size_-1]=n;
            delete[] data;
            data=p;
		}
		void insertPos(int n,int pos){
            size_+=1;
            int *p=new int[size_];
            bool j=false;
            for(int i=0;i<size_;i++){
                if(i==pos){
                    j=true;
                    p[i]=n;
                    continue;
                }
                if(j){
                    p[i]=data[i-1];
                }else{
                    p[i]=data[i];
                }
            }
            delete[] data;
            data=p;
		}
		void eliminarPos(int pos){
            size_-=1;
            int *p=new int[size_];
            bool j=false;
            for(int i=0;i<size_;i++){
                if(i==pos){
                    j=true;
                }
                if(j){
                    p[i]=data[i+1];
                }else{
                    p[i]=data[i];
                }
            }
            delete[] data;
            data=p;

		}

        void print(){
            for(int i=0;i<size_;i++)
                cout<<data[i]<<endl;
		}
		int getSize(){
			return size_;
		}
		~IntegerArray(){
			delete[] this->data;
		}
};

int main()
{
    int array[]={1,2,3,4,5};
    IntegerArray arr(array,5);
    IntegerArray *p=&arr;
    p->print();
    cout<<endl;
    p->eliminarPos(2);
    p->print();
    cout<<endl;
    p->insertFinal(1000);
    p->print();
    cout<<"--------------------"<<endl;
    IntegerArray arr2;
    IntegerArray *p2=&arr2;
    p2->insertFinal(1);
    p2->insertPos(20,4);
    p2->insertPos(15,3);

    p2->print();
    p2->printPos(2);

    return 0;
}

