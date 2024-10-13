#include <iostream>
#include <algorithm>
using namespace std;


// 피봇을 기준으로 왼쪽은 작은 수, 오른쪽은 큰 수를 넣고 피봇의 인덱스 반환
int partition(int* a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quicksort(int* a, int low, int high){
    if(low < high){
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    // int n;
    // cin >> n;
    // int* a = new int[n];

    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    // }

    // //quicksort(a, 0, n - 1); 메모리초과 난다 이 문제는 반드시 계수정렬(카운팅 정렬) 사용해야 함

    // for(int i = 0; i < n; i++){
    //     cout << a[i] << '\n';
    // }

    // // 동적 메모리 해제
    // delete[] a;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[10001] = { 0, };
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[input]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		if (arr[i])
			for (int j = 0; j < arr[i]; j++)
				cout << i << '\n';
	}
	return 0;
} 