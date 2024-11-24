#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 간선이 연결하는 정점과 가중치를 저장하는 클래스
class E{
    public:
    int u;
    int v;
    int w;
    E(){}
    E(int start, int end, int weight){
        u = start;
        v = end;
        w = weight;
    }
    void printEdge(){
        printf("%d %d %d\n",u,v,w);
    }
    // 정렬을 위해 오버라이딩
    bool operator<(const E &e) const {
        return w > e.w;
    }
};



 class UnionFind {
    public:
    // 각 노드의 부모 노드 / 노드의 트리 높이를 저장 
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n); // n개의 정점이 있다
        rank.resize(n, 1); // 높이는 1로 설정
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // 초기에는 자기 자신을 부모로 설정 -> 각각 다른 집합에 속함
        }
    }

    // 특정 정점의 루트 노드를 찾는다
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // 경로압축 : 각 노드들이 부모 노드를 통하지 않고 
            // 직접 루트 노드를 가리키게 하여 트리의 높이를 낮춘다
        }
        return parent[u];
    }

    // 트리(집합)의 노드 수가 더 많은 트리의 루트가 합집합의 루트 노드가 된다
    bool unionSet(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        // 루트 노드 각각 찾고, 서로 다르면(다른 집합이라면) 높이가 작은 트리가 큰 트리에 붙음
        // 
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++; // 두 개의 트리 높이가 같은 경우에 어쩔 수 없이
                // 합쳐진 트리의 높이는 증가함
            }
            return true;  // 두 집합을 성공적으로 합침
        }
        return false;  // 이미 같은 집합에 속해 있음 (사이클 발생)
    }
};





int main(){
    // 입력받아서 벡터 L에 간선들을 저장
    int n, m;
    cin >> n >> m;
    vector<E> L;
    for(int i=0;i<m;i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        L.push_back(E(start, end, weight));
    }

    // 벡터를 사용했으므로 가중치의 내림차순으로 정렬(끝에서 가중치가 작은 간선을 빼기 위해서)
    sort(L.begin(), L.end());

    UnionFind uf(n+1); // 정점 번호가 1부터 시작함
    int total_weights = 0;
    // 최소신장트리 찾기
    vector<E> T;
    while(T.size() < n-1){
        E e = L.back(); // 가장 작은 가중치를 가진 간선 선택
        L.pop_back(); // 선택한 간선은 제거
        if(uf.unionSet(e.v, e.u)){// 선택한 간선의 정점 2개가 같은 집합이 아니면
        // (사이클이 안생긴다면)
            T.push_back(e); // 선택한 간선을 최소신장트리에 추가
            total_weights += e.w;
        }else{
            continue; // 사이클이 생기면 버린 채로 진행
        }
    }
    cout << total_weights << '\n';
    
    return 0;
}