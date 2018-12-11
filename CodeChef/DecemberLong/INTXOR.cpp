#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
long long int a2,a3,arr[MAX],ans[MAX],a,b;
int main(){
	int N,T,w;
	scanf("%d",&T);
	while(T--){
		a2 = a3 = 0;
		scanf("%d",&N);
			printf("1 %d %d %d\n",1,2,3);
			fflush(stdout);
			scanf("%lld",&arr[1]);
			printf("1 %d %d %d\n",2,3,4);
			fflush(stdout);
			scanf("%lld",&arr[2]);
			printf("1 %d %d %d\n",1,4,5);
			fflush(stdout);
			scanf("%lld",&arr[3]);
			printf("1 %d %d %d\n",1,4,6);
			fflush(stdout);
			scanf("%lld",&arr[4]);
			ans[5] = arr[1] ^ arr[2] ^ arr[3];
			ans[6] = arr[1] ^ arr[2] ^ arr[4];
			// cout<<ans[5]<<" ---- "<<ans[6]<<endl;
		for(int i=7;i<=N;i++){
			printf("1 %d %d %d\n",i-2,i-1,i);
			fflush(stdout);
			scanf("%lld",&arr[i]);
			ans[i] = ans[i-1] ^ ans[i-2] ^ arr[i];
			// cout<<"ans --- "<<i<<"  "<<ans[i]<<endl;
		}
			printf("1 %d %d %d\n",2,5,N);
			fflush(stdout);
			scanf("%lld",&arr[5]);
			printf("1 %d %d %d\n",3,N-1,N);
			fflush(stdout);
			scanf("%lld",&arr[6]);
			
		
		ans[2] = arr[5] ^ ans[5] ^ ans[N];
		ans[3] = arr[6] ^ ans[N-1] ^ ans[N];
		ans[4] = arr[2] ^ ans[2] ^ ans[3];
		ans[1] = arr[1] ^ ans[2] ^ ans[3];

		cout<<2<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3];
		for(int i=2;i<=N-2;i++){
			cout<<" "<<ans[i+2];
		}
		cout<<endl;
		fflush(stdout);
		scanf("%d",&w);
		if(w == -1 )
			return 0;
	}

	return 0;
}