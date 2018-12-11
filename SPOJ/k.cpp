#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
#define lli long long int
lli T;
int main()
{
	cin>>T;
	while(T--)
	{
		multimap<lli,pair<lli,lli> >cont;
		double sum,cap;
		lli b,d,h,maxHeight,w,N;
 
		cin>>N;
		sum = 0;
		maxHeight = 0;
		for(int i=0;i<N;i++)
		{
			cin>>b>>h>>w>>d;
			cont.insert(make_pair(b,make_pair(d*w,h)));
			sum += h*w*d;
			if(maxHeight < b+h)
				maxHeight = b+h;
		}
		cin>>cap;
 
		if(sum < cap)
		{
			cout<<"OVERFLOW\n";
		}else{
			double l = (cont.begin())->first;
			double r = maxHeight;
			double mid =0;
			while((r-l)>1e-8)
			{
				mid = (r+l)/2;
				sum = 0;
				for(auto itr = cont.begin();itr != cont.end() && (itr->first < mid);itr++)
				{
					if((itr->first+(itr->second).second) <= mid)
						sum += ((itr->second).first)*((itr->second).second);
					else if((mid - (itr->first)) > 0 && (itr->first+(itr->second).second) > mid )
						sum += ((itr->second).first)*(mid - (itr->first)); 
				} 
				if(sum >= cap)
				{
					r = mid;
				}else if(sum < cap)
				{
					l = mid;
				}
			}
			printf("%.2lf\n",mid);
		}
	}
	return 0;
} 
