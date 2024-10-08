#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // min함수만 사용
#include <math.h>
#include <limits> // numeric_limits 포함

using namespace std;

// 테스트용 출력 함수
void PrintArr(vector<pair<int,int> >& coordinate, int n){
    for(int i=0; i<n; i++){
        printf("(%d, %d)\n", coordinate[i].first, coordinate[i].second);
    }
}

// 점과 점 사이의 거리 공식
double distance(pair<int,int> p1, pair<int,int> p2) {
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2); // 제곱근으로 수정
}

// 점이 2개이거나 3개일 때의 최소 거리 계산
double calMinDistance(vector<pair<int,int> >& arr, int left, int right){
    double minD = numeric_limits<double>::max();
    for(int i=left; i < right-1; i++){
        for(int j=i+1; j < right; j++){
            minD = min(minD, distance(arr[i], arr[j]));
        }
    }
    return minD;
}

bool compareX(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
bool compareY(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

double ClosetPair(vector<pair<int,int> >& s, vector<pair<int,int> >& y, int left, int right){
    // 점의 수가 3개 이하면 거리 계산
    if(right - left <= 3){
        return calMinDistance(s, left, right);
    }
    // 분할
    int mid = (left + right) / 2;
    double Sl = ClosetPair(s, y, left, mid);
    double SR = ClosetPair(s, y, mid + 1, right);
    double d = min(Sl, SR);
    
    // 중간 영역에 있는 점의 거리 계산(Y값 이용)
    vector<pair<int, int> > v; // 중간 영역의 점들 저장
    for (int i = left; i < right; i++) {
        if (abs(y[i].first - s[mid].first) < d) {
            v.push_back(y[i]);
        }
    }

    for (int i = 0; i < v.size(); i++){
        for (int j = i + 1; j < v.size() && (v[j].second - v[i].second) < d; j++) {
            d = min(d, distance(v[i], v[j]));
        }
    }

    return d;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    // pair.first : x좌표, pair.second : y좌표
    // 입력 및 저장
    vector<pair<int,int> > coordinate(n);
    vector<pair<int,int> > sortedByY(n);
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y; // x와 y를 입력받음
        coordinate[i] = make_pair(x, y);
    }

    // coordinate 출력
    //PrintArr(coordinate, n);
    //cout << "========================\n";
    
    // x값기준 정렬
    sort(&coordinate[0], &coordinate[0] + n, compareX); // 수정된 부분
    copy(coordinate.begin(), coordinate.end(), sortedByY.begin());
    //PrintArr(coordinate, n);
    //cout << "========================\n";
    sort(&sortedByY[0], &sortedByY[0] + n, compareY); // 수정된 부분
    //PrintArr(sortedByY,n);

    double minDistance = ClosetPair(coordinate, sortedByY, 0, n);
    cout.precision(6);
    cout << minDistance << '\n'; // 소수점 이하 6자리 출력
    //cout << ClosetPair(coordinate) <<'\n';
}