#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli T,N,curr_val,prev_val,flag,First;
int main()
{
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		cin>>curr_val;
		First = curr_val;
		prev_val = curr_val;
		flag = 0;
		for(int j=1;j<N;j++)
		{
			cin>>curr_val;
			if(curr_val < prev_val)
			{
				flag++;
			}
			prev_val = curr_val;
		}
		// cout<<flag<<"  "<<curr_val<<"  "<<prev_val<<endl;
		if(First >= curr_val && flag == 1)
			cout<<"YES"<<endl;
		else if( flag == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}