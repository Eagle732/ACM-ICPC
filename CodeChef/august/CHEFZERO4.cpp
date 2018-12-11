#include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef long double dbl;
    typedef vector <int> vi;
    typedef pair <int, int> pii;

    int const N = 1002;
    int const MD = 1000000007;

    #define FOR(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
    #define RFOR(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
    #define REP(i, n) FOR(i, 0, n - 1)
    #define pb push_back
    #define mp make_pair
    #define X first
    #define Y second
    #define sz(v) int(v.size())

    int res[N][N];

    int main() {
        int N, M, K;
        scanf("%d%d%d", &N, &M, &K);
        vector <pii> parts;
        FOR (i, 1, N) {
            FOR (j, 1, M) {
                if (i & 1) {
                    parts.pb(mp(i, j));
                } else {
                    parts.pb(mp(i, M - j + 1));
                }
            }
        }
        int X = (N * M) / K;
        int ptr = 0;
        FOR (it, 1, (N * M) % K) {
            FOR (i, 1, X + 1) {
                res[parts[ptr].X][parts[ptr].Y] = it;
                ++ptr;
            }
        }
        FOR (it, (N * M) % K + 1, K) {
            FOR (i, 1, X) {         
                assert (ptr < sz(parts));
                res[parts[ptr].X][parts[ptr].Y] = it;
                ++ptr;
            }
        }
        assert (ptr == sz(parts));
        FOR (i, 1, N) {
            FOR (j, 1, M) {
                printf("%d%c", res[i][j], j == M ? '\n' : ' ');
            }
        }
        return 0;
    }