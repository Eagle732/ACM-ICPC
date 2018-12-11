#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<int>set1,set2;
	int N,T,arr[100005],A,flag=0,prevv;
	cin>>T;
	while(T--)
	{
		cin>>N;
		flag = 0;
		set1.clear();
		set2.clear();
		prevv=0;
		
		for(int i=0;i<N;i++)
		{
			cin>>A;
			arr[i+1] = A;
			set1.insert(A);
			
		}

		for(auto itr=set1.begin();itr != set1.end();itr++)
		{
			if(*itr <= N)
			{	
				// cout<<"ITR"<<*itr<<"  "<<arr[*itr]<<endl;
				set2.insert(arr[*itr]);	
				if(prevv == set2.size())
				{
					cout<<"Truly Happy"<<endl;
					flag = 1;
					break;
				}
				prevv = set2.size();
			}
		}
		
		if(flag == 0)
			cout<<"Poor Chef"<<endl;
	}

return 0;
}