#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
int T,N,C,arr[MAXX];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>C;
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+N);
		int left = arr[0];
		int right = arr[N-1];
		int counter = 0;
		int gap=0;
		int prev = arr[0];
		while(left < right && left+1 != right)
		{
			gap = (left+right)/2;
			counter = 1;
			prev = arr[0];
			for(int i=1;i<N;i++)
			{
				if((arr[i]-prev) >= gap)
				{
					prev = arr[i];
					counter++;
				}
			}
			if(counter >= C)left = gap;
			else right = gap;
			// cout<<left<<" "<<right<<endl;
		}
		cout<<left<<endl;
	}
	return 0;
}