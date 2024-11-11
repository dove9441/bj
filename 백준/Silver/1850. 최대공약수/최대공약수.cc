#include <iostream>
#include <string>
using namespace std;

long long GCD(long long a, long long b){
    while(b!=0){
        long long temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main(void){
    long long a, b;
    cin >> a >> b;
    for(int i=0;i<GCD(a,b); i++){
        cout << '1';
    }
}