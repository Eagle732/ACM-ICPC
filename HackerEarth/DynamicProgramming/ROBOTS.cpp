#include<bits/stdc++.h>
using namespace std;
char res[4][4];
const char resOp[4][4]  = {'g','r','i','d','s','n','o','t','p','o','s','s','i','b','l','e'};
map<string,int>cont;
int main()
{
	string str[40];
	
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>str[i];
			if(cont.count(str[i]))
			{
				cont[str[i]]++;
			}else
			{
				cont[str[i]] = 0;
			}
			string rev = str[i];
			reverse(rev.begin(),rev.end());
			if(cont.count(rev))
			{
				cont[rev]++;
			}else
			{
				cont[rev] = 0;
			}
		}

	}




	return 0;
}