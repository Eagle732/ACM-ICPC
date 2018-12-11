#include<bits/stdc++.h>
using namespace std;
void funct(int N){
	queue<int>qu;
	for(int i=1;i<=N;i++){
		qu.push(i);
	}
	int sum=0,arr[10],a,b;
	while(qu.size() > 6 ){
		cout<<"?";
		
		for(int i=0;i<5;i++)
		{
			arr[i] = qu.front();
			printf(" %d",arr[i]);
			qu.pop();
		}
		printf("\n");
		fflush(stdout);
		scanf("%d %d",&a,&b);
		if(qu.size() != 2){
			for(int i=0;i<5;i++){
				if(arr[i] != a && arr[i] != b){
					qu.push(arr[i]);
				}
			}
		}else{
			for(int i=0;i<5;i++){
				if(arr[i] != a){
					qu.push(arr[i]);
				}
			}
		}
	}
	a=1;sum=0;
	map<pair<int,int>,vector<int> >cont;
	while(!qu.empty()){
		arr[a++] = qu.front();
		sum += arr[a-1];
		qu.pop();
	}
	for(int i=1;i<=6;i++) 
	{
		cout<<"?";
		for(int j=1;j<=6;j++)
		{
			if(i != j)
				printf(" %d",arr[j]);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d %d",&a,&b);
		if(a < b){
			cont[make_pair(a,b)].push_back(i);
		}else
			cont[make_pair(b,a)].push_back(i);
	}
	for(map<pair<int,int>,vector<int> >::iterator itr = cont.begin();itr != cont.end();itr++)
	{
		if((itr->second).size() == 3){
			sum = sum - (itr->first).first - (itr->first).second - (itr->second)[0] - (itr->second)[1] - (itr->second)[2]; 
			break;
		}
	}
	cout<<"! "<<sum<<endl;
	return ;
}

int main(){
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		funct(N);
	}
	return 0;
}