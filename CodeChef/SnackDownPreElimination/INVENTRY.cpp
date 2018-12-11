#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int T,N,prev = -1,counter,flag,counter1;
	string str;
	cin>>T;
	while(T--)
	{
		counter=0;
		flag = 0;
		prev = -1;
		counter1 = 1;
		cin>>N;
		cin>>str;
		for(int i=N-1;i>=0;i--)
		{
			if(str[i] == '.')
			{
				dotCounter++;
			}
			if(str[i] == '#')
			{
				hashCounter++;
			}
			if()



		}
	}



	return 0;
}