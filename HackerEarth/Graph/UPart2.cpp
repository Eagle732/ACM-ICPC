    #include<bits/stdc++.h>
    #include<vector>
    #include<algorithm>
    int count_t=0;
    using namespace std;
    int cycle2[1000];
int num=0;
    // bool uniVisited[2000];
    void DFS(vector<int>graph[],int node,int height,bool visited[],int source,string p){
    	if(graph[node].size() == 0 || visited[node ]== true){
    		return ;
    	}
     
    	if(height == 2){
            p += "@"+to_string(node)+" ";
            
        }else
        p += to_string(node)+" ";
            // cout<<node<<" ";
    	visited[node] = true;
        if(height == 3 && find(graph[node].begin(),graph[node].end(),source) != graph[node].end()){
    	p += to_string(source)+" ";
        	
            
            for(int h=0;h<p.length();h++){
                if(p[h] == '@'){
                    if(p[h+2] !=' ')
                        num = 10*((int)(p[h+1]-'0'))+(int)(p[h+2]-'0');
                    else{
                        num = (int)(p[h+1]-'0');
                    }
                    // cout<<num<<endl;
                    break;
                }
            }
            num--;
            if(num == 81 || num == 64 || num == 58 )
            cout<<p<<endl;
            cycle2[num]++;
            count_t++;
            // cout<<endl;
    	}
     
    	if(height == 3){
    		return ;
    	}
     
    	for(int i=0;i<graph[node].size();i++){
    		if(!visited[graph[node][i]]){
    			DFS(graph,graph[node][i],height+1,visited,source,p);
    		    visited[graph[node][i]] = false;
            }
            
    	}
     
    }
     
    int main(){
     int N,a;
     freopen("input.txt","r",stdin);
        vector<int>tree[2005];
        cin>>N;

        bool visited[2005];
        for(int i=1;i<=N;i++){
            // cout<<i<<"     ";
            for(int j=1;j<=N;j++){
                cin>>a;
                if(a == 1 ){
                    tree[i].push_back(j);
                    // cout<<j<<" ";
                }
            }
            // cout<<endl;
        }
        
    //     tree[0].push_back(5);
    // tree[0].push_back(1);
    // tree[0].push_back(7);
    // tree[1].push_back(3);
    
    // tree[1].push_back(4);
    // tree[1].push_back(2);
    // tree[1].push_back(9);
    // tree[1].push_back(0);
    // tree[1].push_back(8);
    
    // tree[2].push_back(3);
    // tree[2].push_back(10);
    // tree[2].push_back(7);
    // tree[2].push_back(1);
        
    // tree[3].push_back(6);
    // tree[3].push_back(4);
    // tree[3].push_back(2);
    // tree[3].push_back(11);
    // tree[1].push_back(8);
    
    // tree[4].push_back(1);
    // tree[4].push_back(5);
    // tree[4].push_back(3);
    // tree[4].push_back(8);
        
    // tree[5].push_back(0);
    // tree[5].push_back(4);
    // tree[5].push_back(6);
    
    // tree[6].push_back(3);
    // tree[6].push_back(7);
    // tree[6].push_back(5);
    
    // tree[7].push_back(6);
    // tree[7].push_back(2);
    // tree[7].push_back(0);
    
    // tree[8].push_back(9);
    // tree[8].push_back(11);
    // tree[8].push_back(4);
    
    // tree[9].push_back(8);
    // tree[9].push_back(10);
    // tree[9].push_back(1);
    
    // tree[10].push_back(11);
    // tree[10].push_back(2);
    // tree[10].push_back(9);
    
    // tree[11].push_back(3);
    // tree[11].push_back(8);
    // tree[11].push_back(10);
    
        int cycle;
        count_t = 0;
     memset(cycle2,0,sizeof cycle2);
        for(int i=1;i<=1;i++){
        	for(int j=i;j<=N;j++){
        		visited[j] = false;
        	}
        	DFS(tree,i,0,visited,i,"");
            visited[i] = true;
            // cout<<i<<"         count        "<<count_t/2<<endl;;
        }
        // for(int i=0;i<100;i++){
        //     if(cycle2[i] !=0 )
        //     cout<<i<<"   "<<cycle2[i]/2<<endl;
        // }
        cout<<count_t/2<<endl;
     
        
    }