#include <iostream>
using namespace std;

int suma(int n){
    if(n==1){
        return 1;
    }
    else {
        return n+ suma(n-1);
    }
}
int main (){
cout<<"Suma es "<<suma(5)<<endl;
}