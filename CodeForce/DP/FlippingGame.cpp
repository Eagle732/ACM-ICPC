#include<bits/stdc++.h>
using namespace std;
#define inf 100000
#define MAX 100000
struct Node{
	int maxSubarraySum;
	int maxSuffixSum;
	int maxPrefixSum;
	int totalSum;
	Node(){
		maxPrefixSum = maxSuffixSum = maxSubarraySum = totalSum = -inf;
	}
};

Node merge(Node a1,Node a2){
	Node c;
	c.maxSuffixSum = max(a2.maxSuffixSum, a2.totalSum+a1.maxSuffixSum);
	c.maxPrefixSum = max(a1.totalSum + a2.maxPrefixSum, a1.maxPrefixSum );
	c.totalSum = a1.totalSum+a2.totalSum;
	c.maxSubarraySum = max(a1.maxSuffixSum+a2.maxPrefixSum,max(a1.maxSubarraySum,a2.maxSubarraySum));
	return c;
}

void constructTree(Node *tree,int arr[],int start,int end,int index){
	if(start == end){
		tree[index].maxSubarraySum = arr[start]; 
		tree[index].maxSuffixSum = arr[start];
		tree[index].totalSum = arr[start];
		tree[index].maxPrefixSum = arr[start];
		return ;
	}
	// cout<<"index";
	int mid = (start+end)/2;
	constructTree(tree,arr,start,mid,2*index);
	constructTree(tree,arr,mid+1,end,2*index+1);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
}
Node tree[3*MAX];
int main(){
	int N,a;
	int arr[MAX];
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a;
		if(a==0){
			arr[i] = 1; 
		}else
		{
			arr[i] = -1;
		}
	}
	constructTree(tree,arr,0,N-1,0);
	cout<<tree[0].maxSubarraySum<<endl;
	return 0;
}