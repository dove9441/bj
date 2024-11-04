#include <iostream>
#include <algorithm>
using namespace std;

int Binary_Search(int* a, int low, int high, int n){
    if(low > high) return -1;
    int mid = low + (high-low)/2;
    if(a[mid]==n) return mid;

    if(n > a[mid]){
        return Binary_Search(a, mid+1, high, n);
    }else if(n < a[mid]){
        return Binary_Search(a, low, mid-1, n);
    }else{
        return -1;
    }
    
}


int main(){
    int N[100000];
    int M[100000];

    int n,m,x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        N[i] = x;
    }
    sort(N, N + n);
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> x;
        M[i] = x;
    }
    
    for(int i=0; i<m; i++){
        if(Binary_Search(N, 0, n-1, M[i]) != -1){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }
    return 0;
}