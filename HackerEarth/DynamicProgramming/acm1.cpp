#include<bits/stdc++.h>
using namespace std;
set<pair<int,pair<int,int> > >cont;
int main()
{
	int T,A,B,C;
	cin>>T;
	while(T--)
	{
		cont.clear();
		for(int i=0;i<3;i++)
		{
			cin>>A>>B>>C;
			cont.insert(make_pair(A,make_pair(B,C)));
		}
		auto itr = cont.begin();
		pair<int,pair<int,int> >p1 = *itr;
		pair<int,int> p2 = p1.second;
		int counter = 0;
		for(++itr;itr != cont.end();itr++)
		{
			pair<int,pair<int,int> >p3 = *itr;
			pair<int,int> p4 = p3.second;
			
			if(p1.first <= p3.first && p2.first <= p4.first && p2.second <= p4.second)
			{
				if(p1.first < p3.first || p2.first < p4.first || p2.second < p4.second)
					counter++;
				p1 = p3;
				p2 = p4;
			}
		}
		if(counter == 2)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	

	return 0;
}