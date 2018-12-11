#include<bits/stdc++.h>
using namespace std;
#define MAX 300005
#define MOD 1000000007
#define inv 500000004
#define lli long long int
lli tree[MAX],arr[MAX],lazy[MAX][2];

lli calcNth(lli a,lli n,lli d){
	return (a + (n-1) * d) % MOD;
}

lli calcSum(lli a,lli n,lli d){

	lli sum = (2*a + (n-1) * d)%MOD;
	sum = (sum * n) % MOD;
	sum = (sum * inv) % MOD;
	return sum;
}

void buildSegmentTree(lli ss,lli se,lli node)
{
	if(ss == se)
	{
		tree[node] = arr[ss];
		return ;
	}
	if(ss > se)
		return ;
	lli mid = (ss+se)/2;
	buildSegmentTree(ss,mid,2*node);
	buildSegmentTree(mid+1,se,2*node+1);
	tree[node] = (tree[2*node] + tree[2*node+1]) % MOD;
}

void updateLazy(lli node,lli ss,lli se)
{
	lli interval = se-ss+1;
	lli mid = (ss+se)/2;
	lli sum = calcSum(lazy[node][0],interval,lazy[node][1]);
	tree[node] += sum;
	tree[node] %= MOD;
	if(ss != se)
	{
		lazy[2*node][0] += lazy[node][0];
		lazy[2*node][0] %= MOD;
		lazy[2*node][1] = (lazy[2*node][1]+lazy[node][1])%MOD;

		lli an = calcNth(lazy[node][0],mid+2-ss,lazy[node][1]);
		lazy[2*node+1][0] += an; 
		lazy[2*node+1][0] %= MOD;
		lazy[2*node+1][1] = (lazy[2*node+1][1]+lazy[node][1])%MOD; 

	} 
	lazy[node][0] = 0;
	lazy[node][1] = 0; 
}

void update(lli ss,lli se,lli us,lli ue,lli node,lli val,lli diff)
{
	lli mid = (ss+se)/2;
	if(lazy[node][0] != 0)
		updateLazy(node,ss,se);

	if(ss > ue || se < us || ss > se)
		return ;

	if(ss >= us && se <= ue)
	{
		lli interval = se - ss + 1;
		lli an = calcNth(val,ss+1-us,diff);
		lli sum = calcSum(an,interval,diff);
		tree[node] += sum;
		tree[node] %= MOD;
		if(ss != se)
		{
			lazy[2*node][0] = (lazy[2*node][0] + an)%MOD;
			lazy[2*node][1] = (lazy[2*node][1] + diff)%MOD;
			lazy[2*node+1][0] = (lazy[2*node+1][0] + calcNth(val,(mid+2-us),diff))%MOD;
			lazy[2*node+1][1] = (lazy[2*node+1][1] + diff)%MOD;		
		}
		return ;
	}
	update(ss,mid, us,ue, 2*node, val,diff);
	update(mid+1,se, us,ue, 2*node+1, val,diff);

	tree[node] = (tree[2*node] + tree[2*node+1])%MOD;
}

lli query(lli ss,lli se,lli us,lli ue,lli node)
{
	if(lazy[node] != 0)
	{
		updateLazy(node,ss,se);
	}
	if(ss > ue || se < us || ss > se)
		return 0;
	if(ss >= us && se <= ue)
	{
		return tree[node];
	}
	lli mid = (ss+se)/2;
	return ((query(ss,mid,us,ue,2*node)+query(mid+1,se,us,ue,2*node+1))%MOD);
}

int main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	memset(lazy,0,sizeof(lazy));
	lli A,B,C,N,Q,L,R;
	freopen("input1.txt","r",stdin);
	scanf("%lli %lli",&N,&Q);

	for(int i=1;i<=N;i++)
	{
		scanf("%lli",&arr[i]);
	}
	buildSegmentTree(1,N,1);
	while(Q--)
	{
		scanf("%lli %lli %lli",&A,&B,&C);
		if(A == 1)
		{
			lli a = N-B+1;
			if(C>a)
			{
				update(1,N,B,N,1,C,MOD-1);
				C -= a;
				lli rem = C % N;
				lli quo = C / N;
				update(1,N,1,N,1,N*(quo*(quo+1)/2)+(quo*rem),MOD-quo);
				if(rem != 0)
				update(1,N,1,rem,1,rem,MOD-1);
			}else
			{
				update(1,N,B,B+C-1,1,C,MOD-1);	
			}	
			
		}else{
			if(B<=C){
				printf("%lli\n",query(1,N,B,C,1));
			}
			else
				printf("%lli\n",(query(1,N,1,C,1)+query(1,N,B,N,1))%MOD);
		}
	}
	return 0;
}