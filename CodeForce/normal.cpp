#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int T,A;
	cin>>T;
	while(T--)
	{
		cin>>A;
		if(360%(180-A) == 0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}




}