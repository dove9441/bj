#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long MAX = numeric_limits<long>::max();

void AllPairShortest(vector<vector<long long>>& D, int v){
    // k는 경유지, i, j는 각각 출발지와 목적지
    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                // i -> k경로와 i->j경로가 모두 존재하면
                // 여기에 추가로 D[i][j]!=MAX조건 넣으면 안 된다
                // 그렇게 하면 i -> j 경로는 없고 i -> k -> j경로가 존재해도 업데이트가 일어나지 않게 됨
                if(D[i][k] != MAX && D[k][j] != MAX){ 
                    // k를 경유하는 것과 경유하지 않는 것 중 짧은 것으로 업데이트
                    D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
                }
            }
        }
    }
}

int main(void){
    int v, e;
    cin >> v >> e;
    vector<vector<long long>> D(v+1, vector<long long>(v+1, MAX)); // 거리를 저장할 2차원 배열, 연결되지 않았다는 의미의 -1 저장(가중치는 자연수라는 조건)

    // 입력받기
    int a, b, w;
    for(int i=0; i<e; i++){
        cin >> a >> b >> w;
        D[a][b] = w;
    }

    AllPairShortest(D, v); 
    // for(auto i : D){
    //     for(auto j : i){
    //         printf("%d ",j );
    //     }
    //     printf("\n");
    // }
    
    // 최소거리 사이클 찾기
    long long  minDistance = MAX; // w <= 10000
    for(int i=1; i<=v; i++){
        minDistance = min(minDistance, D[i][i]);
    }

    printf("%lld\n", (minDistance!=MAX) ? minDistance : -1);

}