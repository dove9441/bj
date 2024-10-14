#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

bool compareX(const pair<int,int>& a,const pair<int,int>& b) {
    return a.first < b.first;
}
bool compareY(const pair<int,int>& a,const pair<int,int>& b) {
    return a.second < b.second;
}

// 점과 점 사이의 거리 공식 (제곱한 거리)
double distance(pair<int,int> p1,pair<int,int> p2) {
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}

// 점이 2개이거나 3개일 때의 최소 거리 계산 (브루트포스)
double calMinDistance(vector<pair<int,int> >& arr,int left,int right){
    double minD = numeric_limits<double>::max();
    for(int i=left;i < right-1;i++){
        for(int j=i+1;j < right;j++){
            minD = min(minD,distance(arr[i],arr[j]));
        }
    }
    return minD;
}

double ClosetPair(vector<pair<int,int> >& s,int left,int right){
    if(right - left <= 3){
        return calMinDistance(s,left,right);
    }

    int mid = (left + right) / 2;
    double Sl = ClosetPair(s,left,mid);
    double SR = ClosetPair(s,mid,right);
    double d = min(Sl,SR);
    vector<pair<int,int> > v;
    for(int i=left;i < right;i++) {
        if(abs(s[i].first - s[mid].first) < d) {
            v.push_back(s[i]);
        }
    }

    sort(v.begin(),v.end(),compareY);

    for(int i=0;i+1 < v.size();i++) {
        for(int j=i + 1;j < v.size();j++) {
            if((v[j].second - v[i].second) * (v[j].second - v[i].second) >= d) {
                break;
            } else {
                d = min(d,distance(v[i],v[j]));
            }
        }
    }

    return d;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int> > coordinate(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        coordinate[i] = make_pair(x,y);

    }

    sort(coordinate.begin(),coordinate.end(),compareX);

    double minDistance = ClosetPair(coordinate,0,n);
    cout << fixed;
    cout.precision(0);
    cout << minDistance << '\n'; 
}