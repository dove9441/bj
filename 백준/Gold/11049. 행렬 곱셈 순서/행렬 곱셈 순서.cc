#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void mat_chain_X_DP(vector<int>& C, vector<vector<int> > &S, vector<vector<int> >& T, int n){
    int d, i, j, k;
    // 대각선 원소 0으로 초기화
    // 대각선 0 (S[0][0], S[1][1],S[2][2], S[3][3]... 은 모두 0)
    for(int i=1; i<=n; i++){
        S[i][i] = 0;
        T[i][i] = 0;
    }

    // S,T 벡터 모두 대각선은 1 ~ n-1까지 채워야 한다
    for(int d=1; d<=n-1; d++){
        // 대각선 d에는 원소가 n-d개만큼 있다 (ex: 대각선 3에는 S[1][4], S[2][5], S[3][6], ... S[n-3][n]이 있음)
        // i는 행 기준 증가
        for(int i=1; i<=n-d; i++){
            // d=3 일때  S[1][4], S[2][5], S[3][6] ..이므로 d = j-i 
            // d = j - i에서 j = i + d 
            j = i + d;
            // 아직 최소 스칼라 곱셈 횟수를 계산하지 않았으므로 MAX로 설정
            S[i][j] = numeric_limits<int>::max();
            // k는 분할지점을 의미하므로 1부터 j-1까지
            // S[i][j]의 정의 이용해서 계산해서 기존 값보다 작으면 업데이트, 업데이트시 k도 벡터 T에 저장
            for(int k=i; k<=j-1; k++){
                if(S[i][k] + S[k+1][j] + C[i-1]*C[k]*C[j] < S[i][j]){
                    S[i][j] = S[i][k] + S[k+1][j] + C[i-1]*C[k]*C[j];
                    T[i][j] = k;
                }
            }
        }
    }
    return;

}

// 순서 표시하는 함수
// 최초 입력은 T와 i=1, j=n이 될 것
void optimal_order(vector<vector<int> > &T, int i, int j){
    if(i==j){
        printf("M%d", i);
    }else{
        printf("(");
        optimal_order(T, i, T[i][j]);
        optimal_order(T, T[i][j]+1, j);
        printf(")");
    }
}

int main(void){
    // 입력
    int n;
    cin >> n;
    // 입력 전체를 저장하는 input과 열의 수를 저장하는 벡터 C, 1부터 세기 위해 n+1 크기 지정
    vector<pair<int, int> > input(n+1,make_pair(0,0));
    vector<int> C(n+1,0);
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        // C에는 따로 열만 빼서 저장
        input[i] = make_pair(x,y);
        C[i]= y;
    }
    // C[0]에는 M1의 행 크기 넣기
    C[0] = input[1].first;

    // Mi ~ Mj의 최소 스칼라 곱셈 횟수를 저장하는 2차원 벡터 S
    // S[i][j]의 값이 최소가 되는 (분할 지점을 정하는) k를 저장하는 2차원 벡터 T
    // 예를 들어 M1, M2, M3, M4의 곱셈에서 T[1][4]==1, T[2][4]=2라면 (M1)(M2(M3M4))가 최적 순서이다.
    vector<vector<int> > S(n+1, vector<int>(n+1, 0));
    vector<vector<int> > T(n+1, vector<int>(n+1, 0));
    mat_chain_X_DP(C, S, T, n);
    // S[1][n]에는 주어진 행렬의 최종 최소 스칼라 곱셈 횟수가 저장되어 있다.
    cout << S[1][n] << '\n';
    //optimal_order(T,1,n);


}