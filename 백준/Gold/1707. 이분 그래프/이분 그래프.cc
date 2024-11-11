#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// visited 집합을 0(방문x), 1, 2로 나눔
bool bfs(vector<vector<int> > &G, int* visited, int n){
    queue<int> q;
    q.push(n);
    int mark = 1;
    visited[n] = mark;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        // 마킹 변경
        if(visited[now] == 1){
            mark = 2;
        }else if(visited[now] == 2){
            mark = 1;
        }

        // 현재 정점의 인접 노드를 검사
        for(int i = 0; i < G[now].size(); i++){  // G[now] -> ?로 향하는 간선들 검사
            int next = G[now][i];
            if(visited[next] == visited[now]){ // G[now] <-> G[next]가 연결된 상테에서 마킹이 같으면 이분 그래프가 아님
                return false;  
            }

            if(visited[next] == 0){  // 방문하지 않았으면 탐색하고 마킹
                q.push(next);
                visited[next] = mark;
            }
        }
    }
    return true;
}


int main(void){
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int v, e;
        cin >> v >> e;
        vector<vector<int> > G(v + 1); // v는 1번부터 시작
        int visited[20001] = {0,};  // 초기화된 방문 배열

        // 간선 입력
        for(int j = 0; j < e; j++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        // 이분그래프라고 가정하고 bfs돌리기
        bool even = true;
        for(int j = 1; j <= v; j++){
            // 첫 방문 시에는 무조건 visited[j]==0때문에 bfs는 false를 return하므로 (G[now](마킹됨)와 G[now][i] 마킹안됨, visited는 0 을 비교함)
            if(visited[j] == 0 && !bfs(G, visited, j)){
                even = false;
                break;
            }
        }

        if(even) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}