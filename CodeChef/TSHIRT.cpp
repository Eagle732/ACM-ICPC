#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll unsigned long long 
ll dp[1025][101];
vector<ll>capList[101];
int allmask,mask;
ll  Dynamic_Programming(int mask,int i)
{
	if(mask == allmask)
	{
		return 1;
	}
	if(i > 100)
	{
		return 0;
	}
	if(dp[mask][i] != -1) return dp[mask][i];


	ll ways = Dynamic_Programming(mask,i+1);
	int size = capList[i].size();
	for(int j=0;j<size;j++)
	{
		if(mask & (1 << capList[i][j])) continue;
		else ways += Dynamic_Programming(mask | (1 << capList[i][j]),i+1);
		ways %= MOD;
	}
	dp[mask][i] = ways;
	return ways;
}

int main()
{
	int T,N;
	cin>>T;
	for(int i=0;i<T;i++)
	{	
		string temp,str;
		int x;
		cin>>N;
		cin.ignore();
		for(int j=0;j<N;j++){
			getline(cin,str);
			stringstream ss(str);
			while(ss >> temp)
			{
				stringstream s;
				s << temp;
				s >> x;
				capList[x].push_back(j);
			}
		}
		allmask = (1<<N) -1;
		mask = 0;
		memset(dp,-1,sizeof dp);
		cout<<Dynamic_Programming(mask,1)<<endl;;
		for(int k=0;k<101;k++){
			capList[k].clear();
		}
	}

	return 0;
}