#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[100001];
    int acc_sum[100001];
    acc_sum[0] = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        acc_sum[i+1] = acc_sum[i] + a[i];
    }
    for(int x=0; x<m; x++){
        int i,j;
        cin >> i >> j;
        cout << acc_sum[j] - acc_sum[i-1] << '\n';
    }

}