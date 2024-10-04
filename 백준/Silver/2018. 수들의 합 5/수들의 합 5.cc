#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int c = 1;
    for(int i=1; i<n ; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += j;
            if(sum==n){c++;}
            else if(sum > n){break;}
        }
    }
    cout << c;
}