#include <iostream>
#include <string>
#include <random>
using namespace std;

void quick_sort(long int* arr, long int start, long int end){
    if(start>=end){
        return;
    }

    int pivot = start;
    int i = start + 1;
    int j = end;

    while(i<=j){
        while(arr[pivot]>=arr[i] && i<=end){
            i++;
        }
        while(arr[pivot]<=arr[j] && j>start){ //j>=start이라면 j==0일 떄 j--가 실행되어 j가 -1이 되고 없는 인덱스에 접근하여 오류가 남
            j--;
        }
        if(i>j){
            int t = arr[pivot];
            arr[pivot] = arr[j];
            arr[j] = t;
        }else{
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        // 엇갈리면 모두 pivot과 j를 바꾼 후 배열을 분할하여 퀵 정렬을 재귀적으로 실행한다
        quick_sort(arr, start,j-1);
        quick_sort(arr, j+1, end);
    }
}

int main(void){
    long int temp;
    string str;
    cin >> temp;
    str = to_string(temp); // 00481 입력시 맨 앞에 0의미없는것 삭제
    long int* n= new long int[str.length()]; //12345 str.length : 5
    for(int i=0;i<str.length();i++){
        n[i] = (int)str[i] - '0';
    }
    quick_sort(n, 0, str.length()-1);

    for(int i=str.length()-1;i>=0;i--){
        cout << n[i];
    }
    delete[] n;
}