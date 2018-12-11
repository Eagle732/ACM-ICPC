#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <stack>
#include <cassert>
#include <queue>
 
using namespace std;
 
const int MAX_Q = 1e6;
const int MAX_N = 1e3;
const int MAX_M = 1e3;
 
vector<int> g[MAX_N * MAX_M + 2];
int x[MAX_Q+2], y[MAX_Q+2], x2[MAX_Q+2], y2[MAX_Q+2], t[MAX_Q+2];
int rg[MAX_N+2][MAX_M+2];
int dn[MAX_N+2][MAX_M+2];
int color[MAX_N+2][MAX_M+2];
int cnt[MAX_N * MAX_M + 2];
int p[MAX_N * MAX_M + 2];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int MX;
 
int n, m;
 
int ver(int x, int y) {
    return (x-1)*m + y;
}
 
bool norm(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
 
int bfs(int x, int y, int col, int par) {
    int cnt = 1;
    color[x][y] = col;
    p[par] = par;
    queue< pair<int,int> > q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if (x+1 <= n)
            if (dn[x][y] == 0)
                if (color[x+1][y] == 0) {
                    color[x+1][y] = col;
                    cnt++;
                    p[ver(x+1, y)] = par;
                    q.push(make_pair(x+1, y));
                }
        if (y+1 <= m)
            if (rg[x][y] == 0)
                if (color[x][y+1] == 0) {
                    color[x][y+1] = col;
                    cnt++;
                    p[ver(x, y+1)] = par;
                    q.push(make_pair(x, y+1));
                }
        if (x-1 >= 1)
            if (dn[x-1][y] == 0)
                if (color[x-1][y] == 0) {
                    color[x-1][y] = col;
                    cnt++;
                    p[ver(x-1, y)] = par;
                    q.push(make_pair(x-1, y));
                }
        if (y-1 >= 1)
            if (rg[x][y-1] == 0)
                if (color[x][y-1] == 0) {
                    color[x][y-1] = col;
                    cnt++;
                    p[ver(x, y-1)] = par;
                    q.push(make_pair(x, y-1));
                }
    }
    return cnt;
}
 
int get_p(int x) {
    if (p[x] == x)
        return x;
    return p[x] = get_p(p[x]);
}
 
void union_ps(int a, int b) {
    a = get_p(a);
    b = get_p(b);
    if (a != b) {
        if (rand()%2)
            swap(a, b);
        
        p[a] = b;
        cnt[b] += cnt[a];
        MX = max(MX, cnt[b]);
    }
}
 
 
int main() {
    int T;
    cin >> T;
    //assert(1 <= T && T <= 100);
    int SQ = 0;
    while (T > 0) {
        int q;
        scanf("%d %d %d", &n, &m, &q);
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                dn[i][j] = rg[i][j] = 0;
    
        //assert(1 <= n && n <= 1e3);
        //assert(1 <= m && m <= 1e3);
        //assert(1 <= q && q <= 1e6);
        
        SQ += q;
        for(int i = 0; i < q; ++i) {
            scanf("%d", &t[i]);
            //assert(1 <= t[i] && t[i] <= 4);
            if (t[i] == 1) {
                scanf("%d %d", &x[i], &y[i]);
                //assert(1 <= x[i] && x[i] <= n);
                //assert(1 <= y[i] && y[i] <= m-1);
                rg[x[i]][y[i]]++;
            }
            else if (t[i] == 2) {
                scanf("%d %d", &x[i], &y[i]);
                //assert(1 <= x[i] && x[i] <= n-1);
                //assert(1 <= y[i] && y[i] <= m);
                dn[x[i]][y[i]]++;
            }
            else if (t[i] == 3) {
                scanf("%d %d %d %d", &x[i], &y[i], &x2[i], &y2[i]);
                //assert(1 <= x[i] && x[i] <= n);
                //assert(1 <= y[i] && y[i] <= m);
                //assert(1 <= x2[i] && x2[i] <= n);
                //assert(1 <= y2[i] && y2[i] <= m);
            }
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                color[i][j] = 0;
        
        int col = 1;
        MX = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if (color[i][j] == 0) {
                    cnt[ver(i, j)] = bfs(i, j, col, ver(i, j));
                    MX = max(MX, cnt[ver(i,j)]);
                    col++;
                }
        
        long long ans = 0;
        for(int i = q-1; i >= 0; --i) {
            if (t[i] == 1) {
                rg[x[i]][y[i]]--;
                if (rg[x[i]][y[i]] == 0)
                    union_ps(ver(x[i], y[i]), ver(x[i], y[i]+1));
            }
            else if (t[i] == 2) {
                dn[x[i]][y[i]]--;
                if (dn[x[i]][y[i]] == 0)
                    union_ps(ver(x[i], y[i]), ver(x[i]+1, y[i]));
            }
            else if (t[i] == 3) {
                if (get_p(ver(x[i], y[i])) == get_p(ver(x2[i], y2[i])))
                    ans++;
            }
            else {
                ans += MX;
            }
        }
        printf("%lld\n", ans);
    }
    //assert(0 <= SQ && SQ <= 1e6);
    return 0;
}