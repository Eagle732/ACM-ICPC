#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
#define PMOD 1000000007 
#define lli long long int
lli ways=1;
int main()
{
	lli T,N,a;
	map<lli,lli>cont;
	vector<lli>vec;
	cin>>T;
	
	while(T--)
	{	
		ways = 1;
		cin>>N;
		cont.clear();
		vec.clear();
		for(int i=0;i<N;i++)
		{
			cin>>a;
			if(cont.count(a))
			{
				cont[a]++;
			}else
			{
				cont[a] = 1;
			}
		}
		map<lli,lli>::reverse_iterator itr = cont.rbegin(),itr1 = cont.rbegin();
		
		for(map<lli,lli>::iterator i = cont.begin(); i != cont.end(); i++)
		{
			vec.push_back(i->second);
		}

		signed int len = vec.size();
		lli  cur = vec[len-1];
		if(len == 1)
		{
			ways *= ((cur*(cur-1))/2);
			cout<<ways<<endl;
			continue;
		}
		lli prev = vec[len-2];
		if(len == 2)
		{
			if(prev == cur)
			{
				while(cur != 0){
					ways *= cur--;
					ways %= PMOD;
				}
			}else if(prev > cur)
			{
				while(cur--)
				{
					ways *= prev--;
					ways %= PMOD;
				}
				ways *= (prev*(prev-1))/2;

				ways %= PMOD;
			}else if(cur > prev)
			{
				while(prev--)
				{
					ways *= cur--;
					ways %= PMOD;
				}
				ways *= (cur*(cur-1))/2;
				ways %= PMOD;
				cur = 0;
			}

		}
		signed int i = len-3;
		while(cur > 0)
		{
			while(cur > prev && i >= 0)
			{
				prev += vec[i--];
				if(i < 0 && cur > prev)
				{
					while(prev != 0)
					{
						ways *= prev;
						cur--;prev--;
						ways %= PMOD;
					}
					ways *= ((cur*(cur-1))/2);
					cur = prev = 0;
				}
			}
			while(cur != 0 && prev != 0)
			{
				ways *= prev;
				cur--;prev--;
				ways %= PMOD;
			
			}
			if(i < 0 && cur != 0)
			{
				ways *= ((cur*(cur-1))/2);
				break;
			}
			if(prev != 0)
			{
				cur = prev;
				if(i < 0)
				{
					ways *= ((cur*(cur-1))/2);
					break;
				}
				prev = vec[i--];
			}
			else
			{
				if(i < 0)
					continue;
				cur = vec[i--];
				if(i < 0)
				{
					ways *= ((cur*(cur-1))/2);
					break;
				}
				prev = vec[i--];
			}
			ways %= PMOD;
		}
		cout<<ways<<endl;
	}
	return 0;
}