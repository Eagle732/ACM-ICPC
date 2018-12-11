#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,int>cont;
	int T,A,B,N,flag;
	bool arr[10005];
	cin>>T;
	while(T--)
	{
		cont.clear();

	memset(arr,false,sizeof arr);
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>A;
			if(arr[A])
				cont[A]++;
			else{
				arr[A]=true;
				cont[A]=1;
			}
		}
		flag = 0;

		for(auto i = cont.begin();i != cont.end(); i++)
		{
			// cout<<i->first<<" lkj "<<i->second<<endl;
			if((i->second) >= 4)
			{
				if(flag == 0)
				{
					for(int j=0;j<4;j++)
					{
						cout<<i->first<<" ";
						flag=2;
					}
				}
				else
				{
					for(int j=0;j<2;j++)
					{
						cout<<i->first<<" ";
						flag=2;
					}
				}
			}else if((i->second >=2 && i->second < 4))
			{
				for(int j=0;j<2;j++)
				{
					cout<<i->first<<" ";
				}
				flag++;
			}
			if(flag == 2){
				cout<<endl;
				break;
			}
		}
	}









	return 0;

}