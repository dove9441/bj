#include <iostream>
using namespace std;

int main(){
    	ios_base::sync_with_stdio(0);
	    cout.tie(0);
	    cin.tie(0);
        char a[101];
        int n;
        cin >> n;
        cin >> a;
        int s=0;
        for(int i=0;i<n;i++){
            s += a[i]-'0';
        }
        cout << s << '\n';
}