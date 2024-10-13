#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[1000001];
    

    // 삽입 정렬(이거 쓰면 시간초과)
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    sort(a,a+n);

    // for(int i=1;i<n;i++){
    //     int j=i-1;
    //     int key = a[i];
    //     while(j>=0 && a[j]<key){
    //         a[j+1] = a[j];
    //         j--;
    //     }
    //     a[j+1] = key;
    // }
    
    for(int i=0;i<n;i++){
        cout << a[i] <<'\n';
    }
}