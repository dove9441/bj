#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) != abs(b)){
            return abs(a) > abs(b);
        }else{
            return a > b;
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    priority_queue<int, vector<int>, cmp> q;
    for(int i=0; i<x; i++){
        int n;
        cin >> n;
        if(n!=0){
            q.push(n);
        }else{
            if(q.empty()){
                cout << "0\n";
            }else{
                cout  << q.top() << '\n';
                q.pop();
            }
        }
    }


}