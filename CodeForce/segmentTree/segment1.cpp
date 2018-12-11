#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n;
int t[2*N];
int h =0;
int d[N];

void printingTree(){
	for(int s = 0;s <h ; s++)
	{
		cout<<setw(20-(1<<(s+1)))<<"";
		for(int i= 1<<s ;i <= (1<<(s+1))-1;i++)
		{
			cout<<setw(5)<<t[i];
		}
		cout<<endl;
	}
}



void build(){	// build the tree
	for(int i=n-1;i>0;i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p,int value){	// set value at position p
	for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l,int r){		// sum on intever [l, r]
	int res = 0;
	for(l += n,r += n; l < r; l >>= 1, r>>=1)
	{
		// if left intervel border is odd then include it
		// in sum and increase the left node value
		if(l&1) res += t[l++];		 
		// if right intevel border is odd then include first
		// substract it by one for considering its adjacent node
		// and add it and divide it by two
		if(r&1) res += t[--r];
	}
	return res;
}

void apply(int p,int value){
	t[p] += value;
	if(p < n) d[p] += value;
}

void build(int p){
	while(p>1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1] + d[p]);
}

void push(int p)
{
	for(int s = h;s > 0;--s)
	{
		int i = p >> s;
		if(d[i] != 0)
		{
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l,int r,int value){
	l += n, r += n;
	int l0 = l, r0 = r;
	for(;l < r;l >>= 1,r >>= 1)
	{
		if(l&1) apply(l++, value);
		if(r&1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

// int query(int l,int r){
// 	l += n, r += n;
// 	push(l);
// 	push(r-1);
// 	int res = -2e9;
// 	for(; l < r; l >>= 1, r >>= 1){
// 		if(l&1) res = max(res,t[l++]);
// 		if(r&1) res = max(t[--r],res);
// 	}
// 	return res;
// }






int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",t+n+i);
	build();
	modify(0,1);
	printf("%d\n",query(3,11));
	h =  sizeof(int) * 8 - __builtin_clz(n);
	printingTree();
	return 0;
}