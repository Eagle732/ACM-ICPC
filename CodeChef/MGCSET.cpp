#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,M,N,A,counter=0;
	cin>>T;
	for(int i=0;i<T;i++)
	{	
		counter = 0;
		cin>>N>>M;
		for(int j=1;j<=N;j++){
			cin>>A;
			if(A % M == 0){
				counter++;
			}
		}
		cout<<(long long)pow(2,counter)-1<<endl;
	}
	return 0;
}