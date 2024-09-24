#include <iostream>
using namespace std;


int arr[129][129];
int white = 0;
int blue = 0;

void dc(int x, int y, int N){
    int init = arr[x][y];
    bool k = false;
    for(int i=x; i<x+N; i++){
        for(int j=y; j<y+N; j++){
            if(arr[i][j]!=init){
                k = true;
                break;
            }
        }
        if(k){
            break;
        }
    }
    if(k){
        dc(x, y, N/2); //4사분면 (자르는 직선의 교점을 0,0이라 하면)
        dc(x, y+N/2, N/2); // 3사분면
        dc(x+N/2, y, N/2); // 1사분면
        dc(x+N/2, y+N/2, N/2); //2사분면

    }else{
        if(init==0){
            white++;
        }else{
            blue++;
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(0);
	    cout.tie(0);
	    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    dc(0,0,n);
    cout << white << '\n' << blue << '\n';
}