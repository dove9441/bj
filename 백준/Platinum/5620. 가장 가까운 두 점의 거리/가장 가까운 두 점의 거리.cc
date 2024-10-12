#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool compareX(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}
bool compareY(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}




// 테스트용 출력 함수
void PrintArr(vector<pair<int,int> >& coordinate, int n){
    for(int i=0; i<n; i++){
        printf("(%d, %d)\n", coordinate[i].first, coordinate[i].second);
    }
}

// 점과 점 사이의 거리 공식
double distance(pair<int,int> p1, pair<int,int> p2) {
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}

// 점이 2개이거나 3개일 때의 최소 거리 계산 (브루트포스)
double calMinDistance(vector<pair<int,int> >& arr, int left, int right){
    double minD = numeric_limits<double>::max();
    for(int i=left; i < right-1; i++){
        for(int j=i+1; j < right; j++){
            minD = min(minD, distance(arr[i], arr[j]));
        }
    }
    return minD;
}


double ClosetPair(vector<pair<int,int> >& s, int left, int right){
    // 점의 수가 3개 이하면 거리 계산
    if(right - left <=3){
        return calMinDistance(s, left, right);
    }
    // SL과 SR 분할(점의 개수가 3개 이하일 때까지)
    int mid = (left+right) / 2;
    double Sl = ClosetPair(s,left, mid);
    double SR = ClosetPair(s, mid+1, right);
    // d = 각 분할 영역에서의 거리의 최솟값
    double d = min(Sl, SR);
    
    // 중간 영역에 있는 점의 거리 계산(Y값 이용)
    vector<pair<int, int> > v; // 중간 영역의 점들을 저장
    
    // 중간 영역(mid-d < x < mid+d)의 점 구하기
    for (int i = left; i < right; i++) {
        if (abs(s[i].first - s[mid].first) < d) {
            v.push_back(s[i]);
        }
    }

    // 중간 영역의 점들을 y좌표 기준으로 정렬
    sort(v.begin(), v.end(), compareY);

    // 중간 영역에서 y값 기준으로 거리를 비교하여 더 작은 점이 있으면 그 값을 최소로.
    for (int i = 0; i < v.size()-1; i++){
        for (int j = i + 1; j < v.size(); j++) {
            // 위에 있는 값이 d보다 크면 이후 비교는 의미가 없으므로 다음 점 비교
            if((v[j].second - v[i].second) * (v[j].second - v[i].second) >= d){
                break;
            }else{
                d = min(d, distance(v[i], v[j]));
            }
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
    for(int i=0; i<n; i++){
         int x, y;
        cin >> x >> y; // x와 y값 입력 받기
        //cout << "x : " << x << ", y : " << y << '\n';
        coordinate[i] = make_pair(x, y);
    }
    


    // coordinate 출력
    //PrintArr(coordinate, n);
    //cout << "========================\n";
    
    // x값기준 정렬
    sort(coordinate.begin(),coordinate.end(),compareX);
    //PrintArr(coordinate, n);
    //cout << "========================\n";
    //PrintArr(sortedByY,n);

    double minDistance = ClosetPair(coordinate, 0, n);
    cout << minDistance << '\n'; 
    //cout << ClosetPair(coordinate) <<'\n';

}
