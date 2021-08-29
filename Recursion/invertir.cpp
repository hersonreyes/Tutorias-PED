#include <iostream>
using namespace std;

void invertir(int n){
    cout<<n%10;
    if(n>10){
        invertir(n/10);
    }
}

int main(){
invertir(123);
 return 0;
}