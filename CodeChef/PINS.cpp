#include<iostream>
using namespace std;
int main()
{
	int T,N,p;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		p = N-1-((N-1)/2);
		cout<<1<<" "<<1;
		for(int i=0;i<p;i++){
			cout<<0;
		}
		cout<<endl;
	}	
	return 0;
}