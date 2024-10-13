#include <iostream>

using namespace std;

void merge(int* a, int left, int mid, int right){
    // 정렬할 두 배열을 탐색한다
    int n1 = mid - left + 1;  // 왼쪽 배열 크기(mid 포함)
    int n2 = right - mid;     // 오른쪽 배열 크기(mid 제외)

    // 임시 배열 생성
    int* L = new int[n1];
    int* R = new int[n2];
    
    // L과 R에 값을 복사
    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }
    
    // i,j는 각각 왼쪽, 오른쪽 배열을 탐색할 인덱스
    int i=0;
    int j=0; // 오른쪽 배열
    int k=left; // 정렬된 순서대로 넣을 인덱스

    // 비교해서 정렬해서 넣기
    while(i < n1 && j <n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            k++;
            i++;
        }else{
            a[k] = R[j];
            k++;
            j++;
        }
    }
    // 남은 요소 넣기
    while(i < n1){
        a[k] = L[i];
        k++;
        i++;
    }
    while(j < n2){
        a[k] = R[j];
        k++;
        j++;
    }
    delete[] L;
    delete[] R;
}

void merge_sort(int* a, int left, int right){
    if(left<right){
        int mid = left + (right - left)/2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);

        merge(a, left, mid, right);
    }
}

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
    int* a= new int[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    merge_sort(a,0,n-1);
    for(int i=n-1;i>=0;i--){
        cout <<  a[i] << '\n';
    }

    delete[] a;

}
