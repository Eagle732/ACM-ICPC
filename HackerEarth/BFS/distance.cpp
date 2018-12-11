#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int bfs(vector<int >vec[],int t,int source)
{
    int height[MAX],count_t=0;
    queue<int>Q;
    
    bool visited[MAX];
    memset(visited,false,sizeof visited);
    height[source] = 0;
    visited[source] = true;
    memset(height,0,sizeof height);
    
    Q.push(source);
    while(!Q.empty())
    {
        int q = Q.front();
        Q.pop();
        for(int i=0;i<vec[q].size();i++)
        {
            if(!visited[vec[q][i]])
            {
                visited[vec[q][i]] = true;
                height[vec[q][i]] = height[q]+1;
                if(height[vec[q][i]] == t)
                count_t++;
                if(height[vec[q][i]] < t)
                    Q.push(vec[q][i]);
            }
        }
    }
    
    return count_t;
}
int main()
{
    vector<int >vec[MAX];
    int n,e,a,b,T;
    cin>>T;
    T--;
    while(T--){
        
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    
        cin>>a;
        cout<<bfs(vec,a,1)<<endl;
    }
    return 0;
}