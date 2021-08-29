#include <iostream>
using namespace std;

int producto(int a, int b){
    if(b==0){
        return 0;
    } 
    else {
        return a+producto(a,b-1);
    }
}

int main(){
cout<<"El producto es "<<producto(3,5)<<endl;
}