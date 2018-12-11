#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,c,C=1000,l,r,val,a;
	cin>>N>>c;
	l=1,r=N;
	int range = 300; 
	for(l = 1; l <= r; l += range){
		printf("%d %d\n",1,l);
		C -= 1;
		fflush(stdout);
		scanf("%d",&val);
		if(val == 0){
			if(l==1)
				l--;
			if(l + range > r){
				l = r-range;
			}
			continue;
		}else if(val == 1){
			printf("2\n");
			C -= c;
			if(l == 1){
				cout<<3<<" "<<l<<endl;
				return 0;
			}
			break;
		}

	}
	if(l > range){
		r = l;
		l = l-range+1;
		a = l;
	}
	else{
		r = l;
		l = 2;
		a = l;
	}
	while(l <= r){
		printf("%d %d\n",1,l);
		fflush(stdout);
		scanf("%d",&val);
		if(val == 1 &&  l == a)
		{
			cout<<2<<endl<<3<<" "<<l<<endl;
			return 0;
		}
		if(val == 0 && l+10 <= r){
			l += 10;	
		}else if(val == 1 || l+10 > r)
		{
			if(val == 1)
				printf("2\n");
			if(l > 10){
				for(int j=l-9;j<=r;j++){
					printf("%d %d\n",1,j);
					fflush(stdout);
					scanf("%d",&val);
					if(val == 1){
						printf("2\n");
						cout<<3<<" "<<j<<endl;
						return 0;
					}		
				}
			}else
			{
				for(int j=l+1;j<=r;j++){
					printf("%d %d\n",1,j);
					fflush(stdout);
					scanf("%d",&val);
					if(val == 1){
						printf("2\n");
						cout<<3<<" "<<j<<endl;
						return 0;
					}		
				}
			}
		}
	}
	return 0;
}