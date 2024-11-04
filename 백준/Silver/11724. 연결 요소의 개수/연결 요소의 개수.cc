#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &G,int* visited, int u){
    stack<int> s;
    s.push(u);
    visited[u] = 1;
    while(!s.empty()){
        int current = s.top();
        s.pop();
        
        // 1 2
        // 2 5
        // 5 1
        // 3 4
        // 4 6
        // 일 때, 
        // u = 1이라면 G[1]에는 2, 5가 있음
        for(int i=0; i<G[current].size(); i++){
            int next = G[current][i];
            if(!visited[next]){
                s.push(next);
                visited[next] = 1;
            }
        }
    }
    
    
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N+1);
    int cnt = 0;
    // 인접리스트로 표현한 그래프
    // G[u]에는 u -> ? 로 향하는 모든 간선들이 있음
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int visited[1001] = {0,};
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(G, visited, i);
            cnt++;
        }
    }
    cout << cnt << '\n';
    
    return 0;
}