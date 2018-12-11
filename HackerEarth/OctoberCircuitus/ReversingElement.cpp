#include<bits/stdc++.h>
using namespace std;
#define lli signed long long int
#define MAX 100005
#define inf 10000000

struct Node{
	lli maxPrefixSum;
	lli maxSuffixSum;
	lli maxSubarraySum;
	lli totalSum;
	Node(){
		maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf;
		totalSum = -inf;
	}
};

Node merge(Node leftChild,Node rightChild){
	Node parentNode;
	parentNode.maxSuffixSum = max(rightChild.maxSuffixSum,
								rightChild.totalSum+leftChild.maxSuffixSum);

	parentNode.maxPrefixSum = max(leftChild.maxPrefixSum,
								leftChild.totalSum+rightChild.maxPrefixSum);

	parentNode.maxSubarraySum = max(leftChild.maxSubarraySum,max(
								rightChild.maxSubarraySum,
								leftChild.maxSuffixSum+
								rightChild.maxPrefixSum));

	parentNode.totalSum = leftChild.totalSum + rightChild.totalSum;
	
	return parentNode;
}

void constructTreeUtil(Node* tree,lli arr[],int start,int end,int index){
	if(start == end){
		tree[index].maxPrefixSum = arr[start];
		tree[index].maxSuffixSum = arr[start];
		tree[index].maxSubarraySum = arr[start];
		tree[index].totalSum = arr[start];
		return ; 
	}	
	int mid = (start + end)>>1;
	int p = index << 1;
	int q = index << 1 | 1;
	constructTreeUtil(tree,arr,start,mid,p);
	constructTreeUtil(tree,arr,mid+1,end,q);
	tree[index] = merge(tree[p],tree[q]);
}
Node reverseNode(Node a)
{
	Node b;
	b.maxSubarraySum = a.maxSubarraySum;
	b.maxSuffixSum = a.maxPrefixSum;
	b.maxPrefixSum = a.maxSuffixSum;
	b.totalSum = a.totalSum;
	return b; 
}

Node query(Node* tree,int start,int end,int l,int r,int index){
	Node nullNode;
	if(start > end || start > r || end < l){
		nullNode.totalSum = -inf;
		return nullNode;
	}
	if(start >= l && end <= r){
		return tree[index];
	}
	int mid = (start+end)>>1;
	int p = index <<1;
	int q = (index << 1)| 1;
	Node left = query(tree,start,mid,l,r,p);
	Node right = query(tree,mid+1,end,l,r,q);
	if(left.totalSum != -inf && right.totalSum != -inf){
		return merge(left,right);
	}else
	{
		if(left.totalSum == -inf){
			return right;
		}
		if(right.totalSum == -inf){
			return left;
		}
	}
}

void print(Node a)
{
	cout<<"\n-------------"<<endl;
	cout<<a.maxSuffixSum<<"  "<<a.maxPrefixSum<<"  "<<a.maxSubarraySum<<"  "<<a.totalSum<<endl;
}
void printNode(Node *tree,int N){
	for(int i=1;i<=2*N;i++){
		print(tree[i]);
	}
}
Node tree[3*MAX];
int main()
{
	freopen("input1.txt","r",stdin);
	lli N,Q;
	lli arr[MAX],L,R;
	cin>>N>>Q;
	for(int i=1;i<=N;i++)
		cin>>arr[i];
	
	constructTreeUtil(tree,arr,1,N,1);
	// printNode(tree,N);
	while(Q--){
		cin>>L>>R;
		Node a = query(tree,1,N,1,L-1,1);
		Node b = query(tree,1,N,L,R,1);
		Node c = query(tree,1,N,R+1,N,1);
		Node d = reverseNode(b);
		Node e = merge(a,d);
		Node f = merge(e,c);
		// print(a);
		// print(b);
		// print(c);
		// print(d);
		// print(e);
		// print(f);
		cout<<f.maxSubarraySum<<endl;
	}
	return 0;
}