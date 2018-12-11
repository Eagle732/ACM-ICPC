#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
	multiset<lli>ver,hor,verDiff,horDiff;
	lli val1,val2,T,N,M,Q,A,B;
	
	cin>>T;
	while(T--)
	{
		ver.clear();
		hor.clear();
		verDiff.clear();
		horDiff.clear();

		cin>>N>>M>>Q;
		ver.insert(0);ver.insert(N);
		verDiff.insert(N);
		hor.insert(0);hor.insert(M);
		horDiff.insert(M);
		while(Q--)
		{
			cin>>A>>B;
			if(A == 0)
			{
				set<lli>::iterator itr;
				itr = ver.lower_bound(B);
				if(*itr != B)
				{
					val1 = *(--itr);
					val2 = *(++itr);
					itr = verDiff.find(val2-val1);
					verDiff.erase(verDiff.find(val2-val1));
					verDiff.insert(B-val1);
					verDiff.insert(val2-B);
					ver.insert(B);
				}
				cout<<(*(verDiff.rbegin()))*(*(horDiff.rbegin()))<<endl;
			}else if(A==1)
			{
				set<lli>::iterator itr;
				itr = hor.lower_bound(B);
				if(*itr != B)
				{
					val1 = *(--itr);
					val2 = *(++itr);
					horDiff.erase(horDiff.find(val2-val1));
					horDiff.insert(B-val1);
					horDiff.insert(val2-B);
					hor.insert(B);
				}
				cout<<(*(verDiff.rbegin()))*(*(horDiff.rbegin()))<<endl;
			}
		}
	}
	return 0;
}