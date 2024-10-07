#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n;
    cin >> m;
    int a[15000];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int c = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(a[i]+a[j]==m){
                c++;
            }
        }
    }
    cout << c << '\n';
}