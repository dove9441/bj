#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        int temp=q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front() << '\n';
    return 0;
}