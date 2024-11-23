#include <iostream>
#include <vector>
#include <limits>
using namespace std;


bool BellmanFord(int n, int start, vector<vector<pair<int, int>>> &G, vector<long long> &distance){
    // 출발점으로부터 각 정점까지의 거리가 저장됨
    distance[start] = 0; // 출발점은 거리가 0
    
    
    // V-1번 간선 검사, 정점 0은 있지만 사용하지 않음
    for(int i=1; i<n; i++){ 

        // start -> u -> v로 가는 간선들 검사
        for(int u=1; u<=n; u++){
            for(pair<int,int> &edge : G[u]){
                int v = edge.first;
                int w = edge.second;

                if(distance[u] != numeric_limits<int>::max() && (distance[u] + w < distance[v])){
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // 음수 사이클 검사 : 그냥 1번 더 실행해서 값 업데이트가 일어나면 음수 사이클이 있는 것(음수 사이클을 돌 때마다 거리가 감소함)
    for(int u=1; u<=n; u++){
        for(pair<int,int> &edge : G[u]){
            int v = edge.first;
            int w = edge.second;

            if(distance[u] != numeric_limits<int>::max() && (distance[u] + w < distance[v])){
                return false;
            }
        }
    }

    return true;

}
int main(void){
    int n,m;
    // n : num_V, m : num_E
    cin >> n >> m;
    vector<vector<pair<int,int> > > G(n+1); // 도시 번호는 1부터 시작, n개의 도시
    // 거리 배열 초기화
    vector<long long> distance (n+1, numeric_limits<int>::max());
    int u,v,w;

    // 그래프 입력받기
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        G[u].emplace_back(make_pair(v,w));
    }

    int start = 1;
    bool x = BellmanFord(n,start, G, distance);
    if(!x){
        cout << "-1"<<'\n';
    }else{
        for(int i=2; i<=n; i++){
            if(distance[i]==numeric_limits<int>::max()){
                cout << "-1\n";
            }else{
                cout << distance[i] << "\n";
            }
        }
    }
}