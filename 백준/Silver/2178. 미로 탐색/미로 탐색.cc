#include <iostream>
#include <queue>
#include <string>
using namespace std;

int mvRow[4] = {-1, 1, 0, 0};
int mvCol[4] = {0, 0, -1, 1};

void bfs(int** a, int visited[102][102], int n, int m){
    queue<pair<int, int> > q;
    q.push(make_pair(n,m));
    visited[n][m] = 1;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();


        for(int i=0; i<4; i++){
            int nextRow = row + mvRow[i];
            int nextCol = col + mvCol[i];

            if(a[nextRow][nextCol]==1 && visited[nextRow][nextCol]==0){
                q.push(make_pair(nextRow, nextCol));
                visited[nextRow][nextCol] = visited[row][col] + 1;
            }
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    // 배열 선언
    int** maze = new int*[n+2];
    for(int i=0; i<n+2; i++){
        maze[i] = new int[m+2];
    }
    int visited[102][102] = {0,};

    // 테두리 부분을 모두 1로 초기화
    for(int i=0; i<n+2; i++){
        maze[i][0] = 0;        // 각 행의 첫 번째 열을 1로
        maze[i][m+1] = 0;      // 각 행의 마지막 열을 1로
    }
    for(int j=0; j<m+2; j++){
        maze[0][j] = 0;        // 첫 번째 행을 1로
        maze[n+1][j] = 0;      // 마지막 행을 1로
    }

    // 입력 전처리 및 배열에 넣기
    string line;
    for(int i=1; i<n+1; i++){
        cin >> line;
        for(int j=1;j<m+1;j++){
            maze[i][j] = line[j-1]-'0';
        }
    }


    // 출력
    // for(int i=0;i<n+2;i++){
    //     for(int j=0;j<m+2;j++){
    //         cout << maze[i][j];
    //     }
    //     cout << '\n';
    // }


    bfs(maze, visited, 1,1);
    cout << visited[n][m] <<'\n';


    // 동적 할당 해제
    for(int i=0; i<n+2; i++){
        delete[] maze[i];
    }
    delete[] maze;

}