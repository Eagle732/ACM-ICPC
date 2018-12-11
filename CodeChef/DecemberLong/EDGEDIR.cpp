#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,N,A,B,M;
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=0;i<M;i++)
		{
			cin>>A>>B;
		}
		if(M%2 == 1){
			cout<<-1<<endl;
		}else{
			for(int i=0;i<M/2;i++){
				cout<<0<<" ";
			}
			for(int i=0;i<M/2;i++){
				cout<<1<<" ";
			}
			cout<<endl;
			
		}
	}



}