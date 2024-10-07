#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int arr[100000];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<char> v;
    int now = 1;
    stack<int> s;

    for(int i = 0; i < n; i++) {
        while(now <= arr[i]) {
            s.push(now);
            now++;
            v.push_back('+');
        }

        if(s.top() == arr[i]) {
            s.pop();
            v.push_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    vector<char>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << '\n';
    }
    
    return 0;
}