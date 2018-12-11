#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
#define lli long long int
multimap<lli,pair<lli,lli> >cont;
lli sum,cap;
lli b,d,h,maxHeight;
lli T,w,N;	
int main()
{
	cin>>T;
	while(T--)
	{
		cont.clear();
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
				// cout<<l<<" <-l ||  r-> "<<r<<endl;
				sum = 0;
				for(auto itr = cont.begin();itr != cont.end() && (itr->first < mid);itr++)
				{
					if((itr->first+(itr->second).second) <= mid)
						sum += ((itr->second).first)*((itr->second).second);
					else if((mid - (itr->first)) > 0 && (itr->first+(itr->second).second) > mid )
						sum += ((itr->second).first)*(mid - (itr->first)); 
				} 
				// cout<<"Sum : "<<sum<<endl;
				if(sum >= cap)
				{
					r = mid;
				}else if(sum < cap)
				{
					l = mid;
				}
				// cout<<r<<"  "<<l<<endl;
			}
			printf("%.2lf\n",mid);
			// cout<<fixed<<showpoint<<setprecision(2)<<val<<endl;
		}
	}
	return 0;
}