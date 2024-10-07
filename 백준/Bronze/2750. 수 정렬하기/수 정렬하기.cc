#include <iostream>
using namespace std;


int main(void){
	int n;
	cin>>n;
	int *numbers=new int[n];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		numbers[i] = k;
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(numbers[i]>numbers[j]){
				int temp=0;
				temp=numbers[i];
				numbers[i]=numbers[j];
				numbers[j]=temp;
			}
		}
		

	}
	
	for(int i=0;i<n;i++){
		cout<<numbers[i]<<'\n';
	}
	delete[] numbers;
	
}