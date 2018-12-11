#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
	int c = a;
	a = b;
	b = c;
}

map<vector<int>,long>prob;
vector<int>permutation(20),minvec,maxvec;

int main()
{
	long maxx,minn,p;
	int T;
	// vector<int>arr(20);
	cin>>T;
	long long N=100000;
	
	maxx=0,minn=10000000;
	while(N--){
		// permutation.clear();
		for (int i = 0; i < T; ++i)
		{
			permutation[i]=i+1;
		}
		for(int i=0;i<T;i++)
		{
			int j = rand()%T;
			swap(permutation[i],permutation[j]);
		}
		
		if(prob.count(permutation) == 0)
		{
			prob.insert(make_pair(permutation,1));
		}else
		{
			prob[permutation]++;
		}
		permutation.clear();		
	}
	for(auto i:prob)//Find max and min permutations.
    {
    	// cout<<"Hello";
        if(i.second>maxx)
        {
            maxx=i.second;
            maxvec=i.first;
        }
        if(i.second<minn)
        {
            minn=i.second;
            minvec=i.first;
        }
    }

	for(int i=0;i<maxvec.size();i++)
	{
		cout<<maxvec[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<minvec.size();i++)
	{
		cout<<minvec[i]<<" ";
	}
	return 0;
}