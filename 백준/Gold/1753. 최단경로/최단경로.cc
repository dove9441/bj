#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

void Dijkstra_V2(int n, vector<vector<pair<int,int> > >& graph, int start){
    // 맨 처음 거리는 모두 무한대
    vector<int> D(n+1,numeric_limits<int>::max()); // 정점 번호가 1부터 시작하므로
    vector<bool> visited(n+1,false);
    // 출발점의 거리는 0
    D[start] = 0;
    
    for(int i=0; i<n; i++){

        // 다음으로 탐색할 노드를 정하는 과정
        int next = -1; // 다음으로 탐색할 노드를 저장 (노드번호 -1은 없으므로 -1로 초기화)
        for(int j=1; j<n+1; j++){ // 노드 번호는 1부터
            // 아직 탐색하지 않았고 아직 탐색할 노드을 선택하지 않았거나 새로운 노드까지의 거리가 더 가까우면 그 노드를 선택
            if(!visited[j] && (next == -1 || D[j] < D[next])){
                next = j;
            }
        }
        
        // 더 이상 탐색할 노드가 없음
        if(next == -1) break;

        // 선택 노드 탐색
        visited[next] = true;

        // 거리배열 업데이트
        for(int j=0; j<graph[next].size(); j++){
            int u = graph[next][j].first; // 탐색한 노드와 연결되어있는 간선 탐색
            int weight = graph[next][j].second;

            // 아직 탐색하지 않았고 (출발점 -> next -> u) 거리 < (출발점 -> u) 거리이면 업데이트
            if(!visited[u] && (D[next] + weight < D[u])){
                D[u] = D[next] + weight;
            }
        }
    }
    
    for(int i=1; i<n+1; i++){
        if(D[i]==numeric_limits<int>::max()){
            cout << "INF\n";
            continue;
        }
        cout << D[i]<< '\n';
    }
}

void Dijkstra_pq(int n, vector<vector<pair<int,int> > >& graph, int start){
    // 맨 처음 거리는 모두 무한대
    vector<int> D(n+1,numeric_limits<int>::max()); // 정점 번호가 1부터 시작하므로
    vector<bool> visited(n+1,false);
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    D[start] = 0;
    pq.emplace(0, start); 

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        int dist = top.first;
        int current = top.second;
        pq.pop();

        if (visited[current]) continue; // 이미 방문한 노드는 건너뛰기(거리배열 업데이트 불필요)
        visited[current] = true;

        // 거리 배열 업데이트
        for (auto edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;

            // 더 짧은 경로 발견 시 업데이트
            if (D[current] + weight < D[next]) {
                D[next] = D[current] + weight;
                pq.emplace(D[next], next); // 업데이트된 거리와 노드를 우선순위 큐에 삽입
            }
        }
    }
        for(int i=1; i<n+1; i++){
        if(D[i]==numeric_limits<int>::max()){
            cout << "INF\n";
            continue;
        }
        cout << D[i]<< '\n';
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_v, num_E, k;
    cin >> num_v >> num_E;
    cin >> k;
    // 인접 리스트를 표현한 그래프
    vector<vector<pair<int, int> > > G(num_v+1); // 정점 번호는 1부터 시작한다고 함

    int u, v, w;
    for(int i=0; i<num_E;i++){
        cin >> u >> v >> w;
        G[u].emplace_back(make_pair(v,w)); // u -> v로 가중치 w의 간선 존재, 유향그래프이니 반대는 넣지 않음
    }

    Dijkstra_pq(num_v, G, k);
}