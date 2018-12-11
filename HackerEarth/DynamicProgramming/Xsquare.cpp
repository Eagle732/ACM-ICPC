#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
long long int DP1[MAX],DP2[MAX],N,Q,L,R,C;
int main(){
    cin>>N>>Q;
    DP1[0] = 0;
    DP2[0] = 0;
    for(int i=1;i<=N;i++){
        cin>>C;
        if(i > 2)
            DP1[i] = DP1[i-2] + C;
        else
            DP1[i] = C;
    }
    for(int i=1;i<=N;i++){
        cin>>C;
        if(i > 2)
            DP2[i] = DP2[i-2] + C;
        else
        DP2[i] = C;
    }
    while(Q--){
        cin>>C>>L>>R;
        diff = R-L+1;
        if(diff % 2 == 0){
            
        }
        
        if(C==1){
        	
            cout<<DP1[R] - DP1[L] + DP2[R] - DP2[L]<<endl;
        }else{
            cout<<DP1[R] - DP1[L] + DP2[R] - DP2[L]<<endl;
        }
    }
    
    
 
	return 0;
}