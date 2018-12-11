#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MAXX 100005
int main()
{
	lli arr[MAXX],T,N,C;
	cin>>T;
	while(T--)
	{
		vector<lli>vec;
		cin>>N>>C;
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+N);
		for(int i=1;i<N;i++)
		{
			cout<<arr[i]<<" "<<arr[i-1]<<" pushed : "<<arr[i]-arr[i-1]<<endl;
			vec.push_back(arr[i]-arr[i-1]);
		}
		for(int i=0;i<vec.size();i++)
		{
			cout<<vec[i]<<" ";
		}
		cout<<endl;
		sort(vec.begin(),vec.end());
		cout<<vec[vec.size()-C+1]<<endl;
	}




	return 0;
}