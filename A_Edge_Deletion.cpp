

/*
    Code by: KoKoDuDu
    Created: 14.10.2024 14:45:23
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
struct DSU
{
    /*
    numEdge is the number of edges is joined
    */
    int n, numEdge;
    vector<int> par, num;
    DSU(int sz)
    {
        n = sz;
        numEdge = 0;
        par.assign(n + 1, 0);
        num.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int findPar(int x)
    {
        if (x == par[x])
        {
            return x;
        }
        return par[x] = findPar(par[x]);
    }
    bool join(int x, int y)
    {
        x = findPar(x);
        y = findPar(y);
        if (x == y)
        {
            return false;
        }
        if (num[x] < num[y])
        {
            num[y] += num[x];
            par[x] = y;
        }
        else
        {
            num[x] += num[y];
            par[y] = x;
        }
        numEdge++;
        return true;
    }
};
struct edge {
    int u, v, w, t;
    edge(int x, int y, int z, int s) {
        u = x;
        v = y;
        w = z;
        t = s;
    }
};
struct cmp {
    bool operator()(edge const& a, edge const& b) {
        return a.w > b.w;
    }
};
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 3>>>adj(n + 1, vector<array<int, 3>>());
    vector<int>vst(m + 1), dist(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v,i });
        adj[v].push_back({ w,u,i });
    }
    priority_queue<edge, vector<edge>, cmp> pq;
    for (auto e : adj[1]) {
        pq.push(edge(1, e[1], e[0], e[2]));
        dist[e[1]] = e[0];
    }
    DSU dsu(n);
    int cnt = 0;
    while (!pq.empty() && cnt < k) {
        auto e = pq.top();
        pq.pop();
        // cout << e.u << " " << e.v << " " << e.w << "\n";
        if (dsu.join(e.u, e.v)) {
            cnt++;
            vst[e.t] = 1;
            for (auto g : adj[e.v]) {
                pq.push(edge(e.v, g[1], g[0] + e.w, g[2]));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += vst[i];
    }
    cout << ans << '\n';
    for (int i = 1; i <= m; ++i) {
        if (vst[i]) cout << i << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}