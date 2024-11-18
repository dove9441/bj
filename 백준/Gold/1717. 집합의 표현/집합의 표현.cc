#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
    public:
    // 각 노드의 부모를 저장하는 배열과 트리의 높이의 상한을 저장하는 배열
    vector<int> parent, rank;
    UnionFind(int n){
        parent.resize(n); // n개의 집합이 있다
        rank.resize(n, 1); // 각 트리의 높이는 처음에는 모두 1
        for(int i=0; i<n; i++){
            parent[i] = i; // 처음에는 각자의 부모가 자기 자신
        }
    }
    int Find(int s){
        if(parent[s] != s){
            parent[s] = Find(parent[s]); // 루트 노드를 찾기 위한 과정, 경로압축
        }
        return parent[s];
    }

    // 노드 수가 적은 트리가 더 많은 트리에 합쳐짐(그래야 높이를 줄일 수 있음 : weighting rule)
    bool Union(int a, int b){
        int root_a = Find(a);
        int root_b = Find(b);

        // 서로 같은 트리에 있지 않아야 합집합 가능
        if(root_a != root_b){
            if(rank[root_a] > rank[root_b]){
                parent[root_b] = root_a;
            }else if(rank[root_b] > rank[root_a]){
                parent[root_a] = root_b;
            }else{
                parent[root_a] = root_b; // 상한 높이가 같으면 임의로 집어넣음
                rank[root_b]++; // 트리의 높이가 같으면 합쳐진 트리의 높이가 1 증가할 수밖에 없음
            }
            return true;
        }
        return false;
    }

};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n,m;
    cin >> n >> m;
    // 초기화
    UnionFind U = UnionFind(n+1);
    int flag, a, b;

    for(int i=0; i<m; i++){
        cin >> flag >> a >> b;
        if(flag){
            // 1 a b : FIND
            (U.Find(a) == U.Find(b)) ? cout<<"YES\n" : cout <<"NO\n";
        }else{
            U.Union(a,b);
        }
    }

}