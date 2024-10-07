#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 선택 정렬(기본 오름차순)
void Selection_Sort(int* a,int n){
    int min;
    for(int i=0; i<n-1; i++){
        min = a[i];
        for(int j=i+1; j<n; j++){
            if(min > a[j]) swap(a[i], a[j]);
        }
    }
}

int main(void){
    // 입출력 속도 향상을 위한 코드
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 자리수 분리를 위해 string으로 받아옴
    string str;
    cin >> str;

    // 정렬을 위해 string으로 받은 값을 int배열로 바꾸어줘야 함, 아스키코드 이용
    int arr[str.length()];
    for(int i=0; i<str.length(); i++){
        arr[i] = str[i] - '0';
    }
    Selection_Sort(arr, str.length());
    
    // 출력
    for(int i=str.length()-1; i>=0; i--){
        cout << arr[i];
    }
    cout << '\n';


}
