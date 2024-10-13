#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// n번째 자리수(0,1,2,3..)(자리수:digit)을 반환하는 함수
int getDigit(int number,int digit){
    return (number/static_cast<int>(pow(10,digit)))%10; // n= 12345, d=2인 경우 12345/(10^2)=123, 123%10 = 3 -> 2번째 자리수 3 반환
}

void radixSort(int* a,int n){
    // 가장 큰 수와 가장 작은 수 찾기
    int maxNum = *max_element(a,a+n);
    int minNum = *min_element(a,a+n);
    
    // 음수의 경우, 오른쪽으로 옮길 자릿수
    int shift = 0;
    if (minNum < 0) {
        shift = abs(minNum);
    }

    // 가장 큰 수의 자리수 구하기
    int maxDigit = 0;
    while(maxNum + shift >0){ // shift를 고려하여 최대 수를 계산
        maxNum /=10;
        maxDigit++;
    }

    // maxDigit-1번째(getDigit은 0번째 자리수부터 시작이지만 maxDigit은 1자리부터 시작이므로) 자리수까지 정렬
    for(int digit=0;digit < maxDigit;digit++){
        vector<queue<int> > buckets(10); // 큐가 담긴 길이 10의 벡터(0~9) 생성 (큐에 넣은 순서대로 나중에 빼야 한다)

        for(int i=0;i<n;i++){
            int d = getDigit(a[i] + shift,digit); // 해당 수의 k번째 자리수 구하기
            buckets[d].push(a[i]); // 구한 자리수에 해당하는 숫자를 bucket에 넣기
        }

        // n번째 자리수(n=0,1..)대로 정렬(오름차순)된 숫자들을 순서대로 다시 배열에 넣기
        int idx = 0;
        for(int i=0;i<10;i++){
            while(!buckets[i].empty()){
                a[idx] = buckets[i].front(); // queue는 back에서 들어오고 front에서 나간다
                buckets[i].pop();
                idx++;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    //radixSort(a,n);
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        cout << a[i] << '\n'; 
    }
    delete[] a;
}