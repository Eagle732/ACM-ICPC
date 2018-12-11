#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
ull N,K,V,val,num;
static int query=0;
map<pair<int,int> ,bool>visited;
ull findingNum(pair<int,int>p)
{

	// cout<<query<<"  ";
	printf("1 %d %d\n",p.first,p.second);
	fflush(stdout);
	scanf("%lld",&num);
	cout<<num<<endl;
	query++;
	// num =rand()%1000;
	// cout<<"  NUM : "<<num<<endl;
	return num;
}

void RecursiveFunct(pair<int,int>center,int N,int level,ull V)
{

	if(query >= K)
		return ;
	int pivot = N/pow(2,level);
	multimap<ull,pair<int,int> >cont;
	vector<pair<int,int> >vec;
	// cout<<"Pivot : "<<pivot<<endl;
	if(pivot == 0)
	{
		return ;
	}
	// cout<<"Hello : "<<center.first<<"  "<<center.second<<"  "<<pivot<<endl; 
	if(center.first - pivot > 0 && center.second - pivot > 0){
		vec.push_back(make_pair(center.first - pivot,center.second - pivot));
	}
	if(center.first - pivot > 0 && center.second + pivot <= N ){
		vec.push_back(make_pair(center.first - pivot,center.second + pivot));
	}
	if(center.first + pivot <= N && center.second - pivot > 0){
		vec.push_back(make_pair(center.first + pivot,center.second - pivot));
	}
	if(center.first + pivot <= N && center.second + pivot <= N){
		vec.push_back(make_pair(center.first + pivot,center.second + pivot));
	}
	if(center.first - pivot > 0 ){
		vec.push_back(make_pair(center.first - pivot,center.second ));
	}
	if(center.first + pivot <= N  ){
		vec.push_back(make_pair(center.first + pivot,center.second ));
	}
	if(center.second - pivot > 0){
		vec.push_back(make_pair(center.first ,center.second - pivot));
	}
	if(center.second + pivot <= N){
		vec.push_back(make_pair(center.first ,center.second + pivot));
	}
	for(int i=0;i<vec.size();i++)
	{
		if(visited[vec[i]])
			continue;

		num = findingNum(vec[i]);
		visited.insert(make_pair(vec[i],true));
		if(V == num)
		{
			printf("2 %d %d",vec[i].first,vec[i].second);
			fflush(stdout);
			return ;
		} 
		if(num < V){
			cont.insert(pair<ull,pair<int,int> >(V-num, vec[i]));
			// cout<<"  Diff : "<<V-num<<endl;
		}
		else{
			cont.insert(pair<ull,pair<int,int> > (num-V,vec[i]));
			// cout<<"  Diff : "<<num-V<<endl;
		}

	}

	for(multimap<ull,pair<int,int> >::iterator itr = cont.begin();itr != cont.end();itr++)
	{
		if(!visited[itr->second])
			RecursiveFunct(itr->second,N,level+1,V);
	}
	return ;
}

int main()
{
	
	cin>>N>>K>>V;

	num = findingNum(make_pair(N/2,N/2));
	if(V == num)
	{
		printf("2 %lld %lld",N/2,N/2);
		fflush(stdout);
		return 0;
	} 
	RecursiveFunct(make_pair(N/2,N/2),N,1,V);
	
	return 0;
}