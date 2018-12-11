#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
#define MAXXX 1000000009
#define lli long long int
lli T,N,arr[MAXX],counter,st[3*MAXX];
map<lli,int>cont;
void buildSegmentTree(int ss, int se, int si) 
{ 

    if(ss > se)
    	return ;
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return ;
    } 
  
    int mid = (ss+se)/2; 
    buildSegmentTree(ss, mid, si*2);
    buildSegmentTree(mid+1, se, si*2+1);

    st[si] = max(st[si*2], st[si*2+1]); 
    return ;
}
int getMax( int ss, int se, int qs, int qe, int si) 
{ 
    if (qs <= ss && qe >= se) 
        return st[si]; 
  
    if (se < qs || ss > qe) 
        return 0; 
  
    int mid = (ss+se)/2;  
    return max(getMax(ss, mid, qs, qe, 2*si), 
           getMax(mid+1, se, qs, qe, 2*si+1)); 

}

int dynamic(int l,int r)
{
	if(l > r)
		return 0;
	if(l == r)
		return 1;
	long long element = getMax(1,N,l,r,1);
	int index = cont[element];
	if(index == r || index == l)
	{
		return 1;
	}

	int a =  1 + min(dynamic(l,index-1),dynamic(index+1,r));
	return a;		
}

int main()
{
	cin>>T;
	while(T--)
	{
		memset(st,0,sizeof st);
		counter=0;
		cont.clear();
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			cin>>arr[i];
			cont[arr[i]] = i;
		}
		buildSegmentTree(1,N,1);
		int l = 1;
		int r = N;
		counter = dynamic(l,r);
		cout<<counter<<endl;
	}



	return 0;

}