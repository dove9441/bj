#include <iostream>
#include <queue>
#include <vector>

using namespace std;


vector<int> Top_sort(vector<vector<int>>& graph, vector<int>& in_degree){
    queue<int> q;
    vector<int> result;
    for(int i=0; i<in_degree.size(); i++){
        if(in_degree[i]==0) q.push(i); // 진입차수가 0인 모든 노드 넣기
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        result.push_back(now);
        // now ->v 향하는 간선들이 있음
        for(auto v : graph[now]){
            in_degree[v]--;
            if(in_degree[v]==0) q.push(v);
        }
    }

    return result;
}

int main(void){
    int n, m;
    cin >> n >> m;
    // 학생 번호는 1번부터 n번
    vector<int> in_degree(n+1,0);
    vector<vector<int>> graph(n+1);
    int a,b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    vector<int> res = Top_sort(graph,in_degree);
    for(int i=1; i<=n; i++){
        cout << res[i] << ' ';
    }
}