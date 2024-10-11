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
    E(){} // 없으면 오류남
    E(int start, int end, int weight){
        u = start;
        v = end;
        w = weight;
    }
    void printEdge(){
        //printf("(%d, %d, %d)",u,v,w);
        printf("%d %d %d\n",u,v,w);
    }
    // 정렬을 위해 오버라이딩
    bool operator<(const E &e) const {
        return w > e.w;
    }
};


// 유니온 파인드 클래스 (Disjoint Set Union)
 class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // 초기에는 자기 자신을 부모로 설정
        }
    }

    // Find 연산: 루트를 찾음 (경로 압축 기법 사용)
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // 경로 압축
        }
        return parent[u];
    }

    // Union 연산: 두 집합을 합침
    bool unionSet(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
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
        L.push_back(E(start - 1, end - 1, weight)); // 1-based index를 0-based로 변환
    }

    // 벡터를 사용했으므로 가중치의 내림차순으로 정렬(끝에서 빼기 위해서)
    sort(L.begin(), L.end());

    UnionFind uf(n);
    int total_weights = 0;
    // 최소신장트리 찾기
    vector<E> T;
    while(T.size() < n-1){
        E e = L.back(); // 가장 작은 가중치를 가진 간선 선택
        L.pop_back(); // 선택한 간선은 제거
        if(uf.unionSet(e.v, e.u)){ // 선택한 간선의 정점 2개가 같은 집합이 아니면(사이클이 안생긴다면)
            T.push_back(e); // 선택한 간선을 최소신장트리에 추가
            total_weights += e.w;
        }else{
            continue; // 사이클이 생기면 버린 채로 진행
        }
    }
    
    cout << total_weights << '\n';
    
    return 0;
}