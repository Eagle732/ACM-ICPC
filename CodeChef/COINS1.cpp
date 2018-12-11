#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>coinsBrk;
ll recursion(ll coin){
	if(coin == 0){
		return 0;
	}
	if(coinsBrk.count(coin) != 0){
		return coinsBrk[coin];
	}
	ll n2 = recursion(coin / 2);
	ll n3 = recursion(coin / 3);
	ll n4 = recursion(coin / 4);
	
	ll sum=0;

	if(n2 + n3 + n4 >= coin){
		sum =  n2 + n3 + n4;
		coinsBrk[coin] = sum;
		// cout<<coin<<"  "<<sum<<endl;
	}else{
		return coin;
	}
	return sum;
}


int main(){
	ll T,N;

	string str,temp;
	do 
	{
		getline(cin,str);

		stringstream ss(str);
		while(ss >> temp){
			stringstream s;
			s << temp;
			s >> N;
			coinsBrk.clear();
			cout<<recursion(N)<<endl;
		}
	
	}while(str != "\0");




	return 0;
}