#include<bits/stdc++.h> 
using namespace std;
set<int>positive,negative;
void func(vector<int>vec,int sum)
{
	
}





int main()
{
	int N,S,posSum=0,negSum=0;
	cin>>N>>S;
	int maxPos = (N*(N-1))/2;
	int maxNeg = 2-maxPos;
	if(S >= 0)
	{
		int rem = maxPos - S;
	}
	if(rem%2 != 0)
	{
		cout<<"Impossible"<<endl;
	}else
	{
		for(int i=1;i<=N;i++)
		{
			if(i%2!=0){
				positive.insert(i);
				posSum += i;
			}
			else{
				negSum += i;
				negative.insert(i);
			}
		}

		while(posSum - negSum != S)
		{
			int diff = (posSum-negSum) - S;
			cout<<"DIFF  :  "<<diff<<endl;
			if(diff < 0)
			{
				auto it = negative.lower_bound(diff);
				if(it != negative.end())
				{
					positive.insert(*it);
					posSum+=*it;
					negSum-=*it;
					negative.erase(it);
				}
			}else
			{
				auto it = positive.lower_bound(diff);
				if(it != positive.end()){
					negative.insert(*it);
					posSum-=*it;
					negSum+=*it;
					positive.erase(it);
				}
			}
		}
		auto it = positive.begin();
		auto itr = negative.begin();
		for(int i=0;i<N;i++)
		{
			if(*it<*itr && it != positive.end() && itr != negative.end())
			{
				if(*it ==1){
					cout<<1;
					it++;
				}
				else
					cout<<"+"<<*it++;
			}else if(*it > *itr  && it != positive.end() && itr != negative.end())
			{
				if(*itr == 1){
					itr++;
					cout<<-1;
				}
				else
					cout<<"-"<<*itr++;
			}
			if(it == positive.end() && itr != negative.end())
			{
				cout<<"+"<<*itr++;
			}
			if(itr == negative.end() && it != positive.end())
			{
				cout<<"-"<<*it++;
			}
		}
	}
	return 0;
}