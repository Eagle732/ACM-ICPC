#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(){
	int N,arr[MAX],l,r,val,count=0;
	bool flag1=false;
	cin>>N;
	int maxVal=0;
	val = 0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		if(arr[i] == 0){
			val++;
			count++;
			if(maxVal< val){
				maxVal = val;
				r = i;
			}
			if(flag1 == false){
				l=i;
				flag1 = true;
			}
		}if(arr[i] == 1){
			if(val == 0){
				count=0;
				flag1 = false;
				l = i;
			}
			if(val > 0){
				val--;
			}
		}

	}
	count=0;
	for(int i=0;i<N;i++){

		if(i>=l && i<=r && arr[i] == 0){
			count++;
		}else if((i < l || i > r) && arr[i] == 1){
			count++;
		}
	}
	cout<<count<<endl;







}