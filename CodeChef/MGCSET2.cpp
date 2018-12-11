    #include<bits/stdc++.h>
    using namespace std;
    #define First *itr1
    #define Second *itr2
    int counter = 0;
    map<pair<int,int>,bool>container;
    int Finding_Sequence(int arr[],int l,int r,int M){
    	if(container.count(make_pair(l,r)) != 0){
    		// cout<<r-l+1<<"  "<<l<<"   "<<arr[l]<<"   "<<arr[r]<<endl;
    		return 1;
    	}
    	if(l == r)
    	{
    		if(arr[l] % M ==0)
    		{
    			container[make_pair(l,r)] = 1;
    			cout<<r-l+1<<"  "<<l<<"   "<<arr[l]<<"   "<<arr[r]<<endl;
    			counter++;
    			return 1;
    		}
    		else
    		{
    			return 0;
    		}
    	}
    	
    	int b = Finding_Sequence(arr,l,r-1,M);
    	int a = Finding_Sequence(arr,l+1,r,M);
    	int Sum=0;
    	if(a != 0 || b != 0)
    	{
    		for(int i=l;i<=r;i++)
    		{
    			Sum += arr[i]; 
    		}
    		if(Sum % M == 0)
    		{
    			cout<<r-l+1<<"  "<<l<<"   "<<arr[l]<<"   "<<arr[r]<<endl;
    			container[make_pair(l,r)] = 1;
    			counter++;
    			return 1;
    		}
    		else return 0;
    	}
    	else
    	{
    		return 0;
    	}
    }
     
     
    int main(){
    	int T,M,N,count_t=0,arr[1000];
    	vector<int>seq;
    	cin>>T;
    	for(int i=0;i<T;i++)
    	{
    		cin>>N>>M;
    		seq.push_back(0);
    		for(int j=1;j<=N;j++){
    			cin>>arr[j];
    			
    		}
    		Finding_Sequence(arr,1,N,M);
    		cout<<counter<<endl;
    		container.clear();
    		counter = 0;
    	}
    	return 0;
    } 