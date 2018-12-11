#include<bits/stdc++.h>
using namespace std;
#define MAX 2000+5
vector<int>tree[MAX];
void takeInput(int N)
{
	bool A;
	for(int i=0;i<N;i++)
	{
		// cout<<i<<"   ";
		for(int j=0;j<N;j++)
		{
			cin>>A;
			if(A != 0){
				tree[i].push_back(j);

                    // cout<<j<<" ";
			}
		}
		// cout<<endl;
	}
	// tree[0].push_back(1);
	// tree[0].push_back(3);
	// tree[0].push_back(5);
	// tree[0].push_back(7);
	
	// tree[1].push_back(0);
	// tree[1].push_back(2);
	// tree[1].push_back(4);
	// tree[1].push_back(8);
	// tree[1].push_back(9);
	
	// tree[2].push_back(1);
	// tree[2].push_back(3);
	// // tree[2].push_back(5);
	// tree[2].push_back(7);
	// tree[2].push_back(10);
		
	// tree[3].push_back(0);	
	// tree[3].push_back(2);
	// tree[3].push_back(4);
	// tree[3].push_back(6);
	// tree[3].push_back(8);
	// tree[3].push_back(11);
	
	// tree[4].push_back(1);
	// tree[4].push_back(3);
	// tree[4].push_back(5);
	// tree[4].push_back(8);
		
	// tree[5].push_back(0);
	// // tree[5].push_back(2);
	// tree[5].push_back(4);
	// tree[5].push_back(6);
	
	// tree[6].push_back(3);
	// tree[6].push_back(5);
	// tree[6].push_back(7);
	
	// tree[7].push_back(0);
	// tree[7].push_back(2);
	// tree[7].push_back(6);
	
	// tree[8].push_back(1);
	// tree[8].push_back(3);
	// tree[8].push_back(4);
	// tree[8].push_back(9);
	// tree[8].push_back(11);
	
	// tree[9].push_back(1);
	// tree[9].push_back(8);
	// tree[9].push_back(10);
	
	// tree[10].push_back(2);
	// tree[10].push_back(9);
	// tree[10].push_back(11);
	
	// tree[11].push_back(3);
	// tree[11].push_back(8);
	// tree[11].push_back(10);
	
	vector<bool>VIST(N,false);
	long long int Count=0;// i being the root node for cycle
	for(int i=0;i<N;i++)
	{
		// vector visited for diagonal node 
		// cout<<i<<endl;
		map<int,int>cycle;
		vector<bool>visited(N,false),VST2(N,false);
		VIST[i] = true;			// root node must be avoided
		// VST2[i] = true;		// root node must be avoided
		// for(int j=0;j<tree[i].size();j++)
		// 	VST2[tree[i][j]] = true;		// adjacent node of root must not be diagonal


		for(int j=0;j<tree[i].size();j++)
		{
			if(!VIST[tree[i][j]] ) 		// excluding any earlier visited root node
			{
				for(int k=0;k<tree[tree[i][j]].size();k++)
				{
					// excluding any earlier visited root node
					// excluding any adjacent node of root node for diagonally opposite of root node 
					if(!VIST[tree[tree[i][j]][k]] )		
					{
						// 1. if any diagonal node is revisited then it must be part of cycle with other middle node
						// 2. diagonal node must not be adjacent of root node or root node itself
						if(visited[tree[tree[i][j]][k]])
						{
							// cycle++;
							cycle[tree[tree[i][j]][k]]++;
							// cout<<i<<" "<<tree[tree[i][j]][k]<<"  "<<tree[i][j]<<endl;
						}else{
							cycle[tree[tree[i][j]][k]] = 1;
							visited[tree[tree[i][j]][k]] = true;
						}
					}
				}
			}

		}
		for(map<int,int >::iterator itr = cycle.begin(); itr != cycle.end(); itr++){
			Count += ((itr->second)*(itr->second -1))/2;
			// if(itr->second != 1)
			// cout<<itr->first<<" "<<((itr->second)*(itr->second -1))/2<<endl;
		}
		cycle.clear();

		// cout<<i<<"       "<<Count<<endl;
		
	
	}
	cout<<Count<<endl;
}
int main(){
	int N;
	freopen("input2.txt","r",stdin);
	cin>>N;
	takeInput(N);
	return 0;
}