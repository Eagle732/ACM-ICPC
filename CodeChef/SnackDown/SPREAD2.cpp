#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T,N,arr[100005],days=1,people,limit;
	cin>>T;
	while(T--)
	{	
		days=0,limit=0,people=0;
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
			people += arr[i];
			if(i >= limit && limit < N-1)
			{
				days++;
				limit += people;
			}
			
		}
		cout<<days<<endl;
	}




	return 0;
}