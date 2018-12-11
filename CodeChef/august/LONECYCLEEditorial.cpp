#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define fi first
#define sec second

const int MAX = 200005;
const int LIM = 5000006;

int n, m;
int A[LIM], B[LIM];
vector<pii> adj[MAX];
int cycle_idx;
int cycle[MAX];
int par[MAX];
int color[MAX];
int tree_root[MAX];
long long subtree[MAX];
long long total[MAX];
long long direct_cycle[MAX];
long long ans[LIM];

// O(N + M) as each vertex is traversed atmost once and each edge can be
// traversed atmost twice (once while traversing and other while marking
// vertices for cycle indices).
void dfs_cycle(int u, int p) {
  if (color[u] == 2) {
    // already (completely) visited vertex.
    return;
  }
  if (color[u] == 1) {
    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    cycle_idx++;
    int cur = p;
    cycle[cur] = cycle_idx;
    while (cur != u) {
      cur = par[cur];
      cycle[cur] = cycle_idx;
    }
    return;
  }
  par[u] = p;
  color[u] = 1;   // partially visited.
  for(auto it : adj[u]) {
    int v = it.fi;
    if (v == par[u]) {
      continue;
    }
    dfs_cycle(v, u);
  }
  color[u] = 2;   // completely visited.
}

// O(N + M)
void dfs(int u, int p, int root) {
  subtree[u] = 1;
  tree_root[u] = root;
  for(auto it : adj[u]) {
    int v = it.fi;
    if (v == p) continue;
    // avoid traversing a cycle edge.
    if (!cycle[u] || cycle[u] != cycle[v]) {
      dfs(v, u, root);
      subtree[u] += subtree[v];
    }
  }
}

// O(N + M). Same traversal as above.
void dfs2(int u, int p) {
  for(auto it : adj[u]) {
    int v = it.fi, idx = it.sec;
    if (v == p) continue;
    // avoid traversing a cycle edge.
    if (!cycle[u] || cycle[u] != cycle[v]) {
      dfs2(v, u);
      int tr = tree_root[u];
      // Paths which pass through no cycle edge. This means the traversal of
      // edge is through a tree like structure. This means find the subtree
      // size of vertices on the edges and their product is number of possible
      // paths.
      long long no_cycle_cnt = (subtree[tr] - subtree[v]) * subtree[v];
      // Paths which pass through exactly one cycle edge.
      // Paths which pass through one cycle edge containing vertex "u". This
      // means first subtracting total_contribution to cycle paths for "u"
      // which contain "v" in them and them extending path through no cycle
      // paths which start from "v" and end on some vertex.
      long long cycle_cnt = (total[tr] - direct_cycle[v]) * subtree[v];
      // Paths which pass through one cycle edge containing vertex "v". This
      // means first subtracting contribution on non_cycle paths of "v" from
      // "u" i.e now paths are those which start from vertex "u" and don't pass
      // through any cycle edge and then multiplying it with number of paths
      // passing through one cycle edge starting from "v".
      cycle_cnt += (subtree[tr] - subtree[v]) * direct_cycle[v];
      // Number of paths: Path through no cycle + Paths through 1 cycle.
      ans[idx] = cycle_cnt + no_cycle_cnt;
      direct_cycle[u] += direct_cycle[v];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    // Clear.
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      cycle[i] = 0;
      color[i] = 0;
      tree_root[i] = 0;
      total[i] = 0; direct_cycle[i] = 0;
    }
    // Input.
    cycle_idx = 0;
    for (int i = 1; i <= m; i++) {
      cin >> A[i] >> B[i];
      adj[A[i]].push_back({B[i], i});
      adj[B[i]].push_back({A[i], i});
    }
    // Find all cycles and mark all vertices to their corresponding cycle index.
    for (int i = 1; i <= n; i++) {
      dfs_cycle(i, 0);
    }
    // Find subtree sizes for nodes such that you never traverse cycle edge.
    for (int i = 1; i <= n; i++) {
      if (!tree_root[i]) {
        dfs(i, 0, i);
      }
    }
    // Find the answer for cycle edges.
    for (int i = 1; i <= m; i++) {
      // Note: vertices not part of any cycle are marked 0. So, first check is
      // important.
      if (cycle[A[i]] && cycle[A[i]] == cycle[B[i]]) {
        ans[i] = subtree[tree_root[A[i]]] * subtree[tree_root[B[i]]];
        direct_cycle[A[i]] += subtree[tree_root[B[i]]];
        direct_cycle[B[i]] += subtree[tree_root[A[i]]];
        total[tree_root[A[i]]] += subtree[tree_root[B[i]]];
        total[tree_root[B[i]]] += subtree[tree_root[A[i]]];
      }
    }
    // Find the answer for remaining edges.
    for (int i = 1; i <= n; i++) {
      // DFS traversal is same as before. So, start only from root of trees.
      if (tree_root[i] == i) {
        dfs2(i, 0);
      }
    }
    // Output.
    for (int i = 1; i <= m; i++) {
      cout << ans[i] << "\n";
    }
  }
  return 0;
}