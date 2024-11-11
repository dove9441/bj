#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    long int n;
    cin >> n;
    long int r = n;
    
    for(long int k=2; k<=sqrt(n); k++){
        if(n%k == 0){ // 서로소가 아님 (gcd(n,k)!=1)
            r = r - (r/k); // 오일러 곱 공식 pi(n) = n product(1 - 1/p) 이용, 여기서 p는 소인수. for문이 product 역할
            while(n%k == 0){
                n = n/k;
            }
        }
    }

    // 위 for문에서 n에 대한 소인수 n은 체크하지 않았므로 해줘야 함
    if(n > 1){
        r = r - (r/n);
    }
    cout << r << '\n';
}