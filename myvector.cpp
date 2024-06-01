#include <iostream>
#include <stdexcept>

using namespace std;

class my_vector : public exception {
    public:
        my_vector(const int &s, const int &val){
            size=s;
            arr = new int [size];
            for(int i=0; i<size; i++){
                arr[i]=val;
            }
        }
        my_vector(const int& s){
           size=s;
           arr = new int [size];
           for(int i=0; i<size; i++){
            arr[i]=0;
           } 
        }
        ~my_vector(){
            delete [] arr;
        }
        friend my_vector operator+(const my_vector&v1, const my_vector &v2) throw(logic_error){
            if(v1.size!=v2.size) throw("different sizes!");
            my_vector result(0, v1.size);
            for(int i=0; i<v1.size; i++){
                result[i]=v1[i]+v2[i];
            }
            return result;
        }
        int &operator[] (int i) throw(logic_error){
            if(i>=size) throw("out of bounds");
            return arr[i];
        }
        int operator[] (int i) const throw(logic_error){
            if(i>=size) throw("out of bounds");
            return arr[i];
        }
        const my_vector& operator= (const my_vector &v){
            size = v.size;
            delete [] arr;
            int *arr = new int [size];
            for(int i=0; i<size; i++){
                arr[i]=v[i];
            }
            return *this;
        }
        friend ostream& operator<< (ostream &out, const my_vector &v){
            out<<v[0];
            for(int i=1; i<v.size; i++){
                out<<' '<<v[i];
            }
            out<<endl;
            return out;
        }
    private:
        int size;
        int *arr;
};

int main(){
    my_vector a(5,10), b(6,12), c(7,10);
    a[6]=9;
    cout << "Array a + c: " << a + c << endl;
    cout << "element a[6]: " << a[6] << endl;
   // my_vector d = a + b; //Exception 1
    //cout << a[12]; //Exception 2
}