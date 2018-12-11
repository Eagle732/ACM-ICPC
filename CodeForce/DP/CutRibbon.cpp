#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int dp[MAX];
int main(){
	int L,A,B,C,x,y,z;
	cin>>L>>A>>B>>C;

	dp[A] = dp[B] = dp[C] = 1;
	for(int i=1;i<=L;i++){
		x=y=z=-1;
		
		if(i>A && dp[i-A] != -1){
			x = dp[i-A]+1;
		}else if(i == A){
			x = 1;
		}
		if(i>B && dp[i-B] != -1){
			y = dp[i-B]+1;
		}else if(i == B){
			y = 1;
		}
		if(i>C && dp[i-C] != -1){
			z = dp[i-C]+1;
		}else if(i == C){
			z = 1;
		}

		if(x != -1 || y != -1 || z != -1){
			dp[i] = max(x,max(y,z));
		}else
		{
			dp[i] = -1;
		}
		// cout<<i<<"  "<<dp[i]<<"  "<<x<<"  "<<y<<"  "<<z <<endl;

	}
	cout<<dp[L]<<endl;

	return 0;
}