#include <iostream>
#include <string>
using namespace std;

int main(void){
	int n,m=0;
	double sum=0;
	double score[1000]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>score[i];
	}
	
	
	for(int i=0;i<n;i++){
		score[i]=(double)score[i];
		if(score[i]>m){
			m=score[i];
		}
	}
	
	
	
	for(int i=0;i<n;i++){
		score[i]=score[i]/(double)m*100;
	}
	
	
	for(int i=0;i<n;i++){
		sum+=score[i];
	}
	cout<<sum/n;
	
	
	
	
	
}