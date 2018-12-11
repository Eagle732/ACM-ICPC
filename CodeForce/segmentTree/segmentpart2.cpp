#include<bits/stdc++.h>
using namespace std;
void calc(int p,int k){
	if(d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
	else t[p] = k*d[p];
}

void apply(int value,int k){
	t[p] = value*k;
	if(p<n) d[p] = value;
}

void build(int l,int r){
	// bottom up approach
	k = 2;
	for(l += n,r += n-1; l > 1; k <<= 1){
		l >>= 1,r >>= 1;
		for(int i = r;i >= l;i--) calc(i,k);
	}
}

void push(int l,int r){
	// top to bottom approach
	int s = h,k=1<<(h-1);
	for(l += n,r += n-1;s > 0;--s,k>>=1){
		for(int i=l>>s;i<=r>>s;i++) if (d[p] != 0){
			apply(i<<1, d[p], k);
			apply(i<<1|1, d[p], k);
			d[p]=0;
		}
	}
}

void modify(int l,int r,int value){
	if(value == 0) return ;
	push(l,l+1);
	push(r-1,r);
	int l0= l,r0 = r,k=1;
	for( l += n,r += n; l< r; l >>= 1,r >>= 1,k <<= 1){
		if(l&1) apply(l++,value,k);
		if(r&1) apply(--r,value,k);
	}
	build(l0,l0+1);
	build(r0-1,r0);
}

int query(int l,int r){
	push(l,l+1);
	push(r-1,r);
	int res = 0;
	for(l += n,r += n;l < r;l>>=1,r >>=1){
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}

void modify(int l, int r, int value) {
  if (value == 0) return;
  push(l, l + 1);
  push(r - 1, r);
  bool cl = false, cr = false;
  int k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l - 1, k);
    if (cr) calc(r, k);
    if (l&1) apply(l++, value, k), cl = true;
    if (r&1) apply(--r, value, k), cr = true;
  }
  for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l, k);
    if (cr && (!cl || l != r)) calc(r, k);
  }
}

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