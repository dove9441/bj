#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.emplace_back(x);
    }

    int cnt =0;
    int remain = k;
    for(int i=n-1; i>=0; i--){
        if(remain>=v[i] && remain > 0){
            cnt = cnt + remain / v[i];
            remain = remain % v[i];
            //printf("remain : %d, cnt = %d\n",remain, cnt);
        }else if(remain == 0){
            break;
        }
    }
    cout << cnt;
}