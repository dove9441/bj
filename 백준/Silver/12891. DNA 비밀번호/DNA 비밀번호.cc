#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int s, p;
    cin >> s >> p;
    char str[1000001];
    cin >> str;
    int ACGT[4] = {0, 0, 0, 0};
    int cnt = 0;
    int a, c, g, t;
    cin >> a >> c >> g >> t;
    
    for (int i = 0; i < p; i++) {
        if (str[i] == 'A') ACGT[0]++;
        if (str[i] == 'C') ACGT[1]++;
        if (str[i] == 'G') ACGT[2]++;
        if (str[i] == 'T') ACGT[3]++;
    }
    
    if (ACGT[0] >= a && ACGT[1] >= c && ACGT[2] >= g && ACGT[3] >= t) {
        cnt++;
    }
    
    for (int i = p; i < s; i++) {
        if (str[i - p] == 'A') ACGT[0]--;
        if (str[i - p] == 'C') ACGT[1]--;
        if (str[i - p] == 'G') ACGT[2]--;
        if (str[i - p] == 'T') ACGT[3]--;
        
        if (str[i] == 'A') ACGT[0]++;
        if (str[i] == 'C') ACGT[1]++;
        if (str[i] == 'G') ACGT[2]++;
        if (str[i] == 'T') ACGT[3]++;
        
        if (ACGT[0] >= a && ACGT[1] >= c && ACGT[2] >= g && ACGT[3] >= t) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}