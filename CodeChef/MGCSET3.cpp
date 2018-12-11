#include<bits/stdc++.h>
using namespace std;
void DP_Solution(vector<int>seq,set<pair<int,vector<int> > > container,int SUM)
{
	if(container.find(make_pair(SUM,seq)) != container.end())
	{
		return ;
	}
	vector<int>vec;
	copy(seq.begin(),seq.end(),vec.begin());
	for(vector<int>::iterator itr = seq.begin(); itr != seq.end(); itr++)
	{
		container.insert(make_pair((SUM-*itr),seq-*itr));
		
		DP_Solution()
	}




}
int main()
{





	return 0;
}