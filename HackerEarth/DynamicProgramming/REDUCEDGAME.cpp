#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
vector<int>vec,vec2;
int main()
{
	int counter,T,N,K,arr[MAXX];
	cin>>T;
	while(T--)
	{
		counter = 0;
		vec.clear();vec2.clear();
		
		cin>>N>>K;
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
			
		}
		sort(arr,arr+N);
		for(int i=0;i<N;i++)
		{
			if(arr[i]<=K)
			 	counter += arr[i];
			if(arr[i]>K && i != N-1)
			{
				vec.push_back(arr[i]);
			}
		}
		cout<<counter<<endl;
		counter += vec.size()*K;

		cout<<counter<<endl;
		int len = vec.size();
		while(len > 1)
		{
			vec2.clear();
			sort(vec.rbegin(),vec.rend());
			for(int i=0;i<len;i+=2)
			{

				if(i+1 != len)
				{
					int diff = vec[i+1] - K;
					if(vec[i]-diff != K)
						vec2.push_back(vec[i]-diff); 
				}
			}
			if(len%2 != 0)
				vec2.push_back(vec[len-1]);
			len=vec2.size();
			vec.clear();
			copy(vec2.begin(),vec2.end(),vec.begin());
		}
		if(vec.size()!=0)
		{
			int diff = vec[0] - K;
			counter += arr[N-1] -diff;
		}else
		{
			counter += arr[N-1];
		}
		cout<<counter<<endl;




	}






	return 0;

}