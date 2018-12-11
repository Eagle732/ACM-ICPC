#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> >cont;
int main()
{
	int P,S,SC[35],NC[35],count_t=0;
	cin>>P>>S;
	for(int i=0;i<P;i++)
	{
		map<int,int>seq;
		count_t = 0;
		for(int j=0;j<S;j++)
		{
			cin>>SC[j];
		}
		for(int j=0;j<S;j++)
		{
			cin>>NC[j];
		}

		for(int j=0;j<S;j++)
		{
			seq[SC[j]] = NC[j];
		}
		map<int,int>::iterator itr1 = seq.begin();
		itr1++;
		for(map<int,int>::iterator itr =seq.begin(); itr1 != seq.end(); itr1++,itr++)
		{
		
			int a = itr->second;
			int b = itr1->second;
			if(a>b)
			count_t++;
			// cout<<a<<"  "<<count_t<<endl;
		}

		// cout<<count_t<<"  "<<i+1 <<endl;
		cont.insert(make_pair(count_t,i+1));
		count_t=0;
	}
	for(set<pair<int,int> >::iterator itr = cont.begin();itr != cont.end(); itr++)
	{
		cout<<itr->second<<endl;
	}
	return 0;
}