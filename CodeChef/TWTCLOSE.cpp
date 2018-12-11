#include<bits/stdc++.h>
using namespace std;
int N,T,K,open=0;
int main(){
	bool arr[1005];
	char str[200];
	memset(arr,false,sizeof arr);
	cin>>N>>K;
	for(int i=0;i<K;i++)
	{
		scanf("%s",str);
		if(!strcmp(str,"CLICK")){
			scanf("%d",&T);
		}

		if(!strcmp(str,"CLICK"))
		{
			if(arr[T])
			{
				arr[T] =0;
				open--;
			}else
			{
				arr[T] = 1;
				open++;
			}
		}
		if(!strcmp(str, "CLOSEALL"))
		{
			open = 0;
			memset(arr,0,sizeof arr);
		}
		cout<<open<<endl;
	}
	return 0;
}