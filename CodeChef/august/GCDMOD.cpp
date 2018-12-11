#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
 long long int A,B,N,A_,B_,sum,mul;
#define ull  long long int
ull modulo = 0;
ull multiply(ull a,ull b)
{
	ull res = 0;
	a = a%modulo;
	while(b>0)
	{
		if(b%2 == 1)
		{
			res = (res + a)%modulo;
		}
		a = (a*2)%modulo;
		b/=2;
	}
	return res%modulo;
}


ull exponential(ull A,ull N)
{
	if(N == 0)
		return 1;
	mul = multiply(A,A);
	if(N%2 == 0)
		return exponential(mul,N/2);
	else
		return (multiply(A,(exponential(mul,(N-1)/2))))%modulo;
}
ull GCD(ull a,ull b)
{
	if(b == 0)
	{
		return a;
	}
	else
		return (GCD(b,a%b));
 
}
int main()
{
	// freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>A>>B>>N;
		modulo = (A - B);
		if(modulo == 0)
		{
			modulo = MOD;
		}
		// A = modulo;
		// B = modulo;
		A_ = exponential(A,N);
		B_ = exponential(B,N);
		sum = ((A_%modulo) + (B_%modulo))%modulo;
		if(modulo == MOD)
			cout<<sum<<endl;
		else
			cout<<GCD(modulo,sum)%MOD<<endl;
	}
	return 0;
}  