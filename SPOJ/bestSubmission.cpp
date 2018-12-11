#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,m1;
	char str[1000][1001];
	vector<int> v,v1;
	vector<int>:: iterator itr;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n-1;i++)
	{
		scanf("%s",str[i]);
	}
	m1=0;
	while(v.empty()==1 and m1<m)
	{
		for(i=0;i<=n-1;i++)
		{
			if(str[i][m1]=='1')
			{
				v.push_back(i);
			}
		}
		m1++;
	}
	if(v.size()==0)
	{
		printf("1");
	}else if(v.size()==1)
	{
		itr=v.begin();
		printf("%d",*itr+1);
	}else
	{
		while(v.size()>1 and m1<m)
		{
			int count=0;v1.clear();
			for(itr=v.begin();itr!=v.end();itr++)
			{
				if(str[*itr][m1]=='1')
				{
					v1.push_back(*itr);
				}
			}
			if(v1.size()==0)
			{
				m1++;
			}
			else
			{
				v.clear();
				v=v1;
				m1++;
			}
		}
		itr=v.begin();
		printf("%d",*itr+1);
	}
	return 0;
}