#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <time.h>
#include <utility>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> ipair;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define pi(n) printf("%d",n)
#define pp printf(" ")
#define pn printf("\n")
#define MAX 100005
#define LN 18
ll arr[MAX];
ll tree[4 * MAX];
ll lazy1[4 * MAX];
ll lazy2[4 * MAX];
ll inv;
ll calcNth(ll a, ll d, ll r) {
	ll val = (a + (r - 1) * d)%mod;
	return val;
}
ll calcSum(ll a, ll d, ll r) {
	ll sum = (2 * a + (r - 1) * d)%mod;
	sum = (sum * r)%mod;
	sum = (sum * inv)%mod;
	return sum;
}
void build(ll node, ll start, ll end) {
	if(start == end) {
		tree[node] = arr[start];
		return;
	}
	ll mid, p, q;
	mid = (start + end) >> 1;
	p = node << 1;
	q = p|1;
	build(p, start, mid);
	build(q, mid + 1, end);
	tree[node] = (tree[p] + tree[q])%mod;
}
void relax(ll node, ll start, ll end) {
	ll a = lazy1[node];
	ll d = lazy2[node];
	if(a || d) {
		ll sum = calcSum(a, d, end + 1 - start);
		tree[node] = (tree[node] + sum)%mod;
		if(start^end) {
			ll p = node << 1;
			ll q = p|1;
			ll mid = (start + end) >> 1;
			ll nth = calcNth(a, d, mid + 2 - start);
			lazy1[p] = (lazy1[p] + lazy1[node])%mod;
			lazy2[p] = (lazy2[p] + lazy2[node])%mod;
			lazy1[q] = (lazy1[q] + nth)%mod;
			lazy2[q] = (lazy2[q] + lazy2[node])%mod;
		}
		lazy1[node] = lazy2[node] = 0;
	}
}
void update(ll node, ll start, ll end, ll l, ll r, ll val, ll d) {
	relax(node, start, end);
	if(start > r || end < l) {
		return;
	}
	ll mid, p, q;
	mid = (start + end) >> 1;
	p = node << 1;
	q = p|1;
	if(start >= l && end <= r) {
		ll nval = calcNth(val, d, start + 1 - l);
		ll sum = calcSum(nval, d, end + 1 - start);
		tree[node] = (tree[node] + sum)%mod;
		if(start^end) {
			ll nth = calcNth(val, d, mid + 2 - l);
			lazy1[p] = (lazy1[p] + nval)%mod;
			lazy2[p] = (lazy2[p] + d)%mod;
			lazy1[q] = (lazy1[q] + nth)%mod;
			lazy2[q] = (lazy2[q] + d)%mod;
		}
		return;
	}
	update(p, start, mid, l, r, val, d);
	update(q, mid + 1, end, l, r, val, d);
	tree[node] = (tree[p] + tree[q])%mod;
}
ll query(ll node, ll start, ll end, ll l, ll r) {
	if(start > r || end < l) {
		return 0;
	}
	relax(node, start, end);
	if(start >= l && end <= r) {
		return tree[node];
	}
	ll mid, p, q;
	mid = (start + end) >> 1;
	p = node << 1;
	q = p|1;
	ll left = query(p, start, mid, l, r);
	ll right = query(q, mid + 1, end, l, r);
	return (left + right)%mod;
}
int main() {

	freopen("input1.txt","r",stdin);
	inv = 500000004;
	ll n, q;
	gl(n);
	gl(q);
	ll i;
	fu(i, 1, n) {
		gl(arr[i]);
	}
	build(1, 1, n);
	while(q--) {
		int ch;
		gi(ch);
		if(ch == 1) {
			ll id, val;
			gl(id);
			gl(val);
			ll num = n + 1 - id;
			if(val <= num) {
				update(1, 1, n, id, id + val - 1, val, mod - 1);
			}
			else {
				update(1, 1, n, id, n, val, mod - 1);
				val = val - num;
				ll k = val/n;
				ll st = calcSum(val, mod - n, k);
				cout<<st<<"  "<<k<<endl;
				update(1, 1, n, 1, n, st, mod - k);
				val = val%n;
				if(val) {
					update(1, 1, n, 1, val, val, mod - 1);
				}
			}
		}
		else {
			ll l, r;
			gl(l);
			gl(r);
			if(l <= r) {
				ll ans = query(1, 1, n, l, r);
				pl(ans);
				pn;
			}
			else {
				ll ans = (query(1, 1, n, l, n) + query(1, 1, n, 1, r))%mod;
				pl(ans);
				pn;
			}
		}
	}
	return 0;
}