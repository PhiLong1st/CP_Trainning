/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const int MOD = 1e9 + 7;
const int INF = 1e18;
struct DSU
{
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
struct LCA
{
    /* HOW TO USE?
    Just LCA(vector) with vector is your vector of edges of tree
    */
    int numNode;
    vector<vector<int>> adj, parLevel;
    vector<int> dist;
    LCA(int n, vector<vector<int>> adjList)
    {
        numNode = n;
        adj = adjList;
        parLevel.assign(numNode + 1, vector<int>(21, 0));
        dist.assign(numNode + 1, 0);
        prepare();
    }
    void showTree()
    {
        for (int node = 1; node <= numNode; node++)
        {
            cout << node << "\n";
            for (int child : adj[node])
            {
                cout << child << " ";
            }
            cout << "\n";
        }
    }
    void dfs(int node, int par)
    {
        for (int child : adj[node])
        {
            if (child != par)
            {
                parLevel[child][0] = node;
                dist[child] = dist[node] + 1;
                dfs(child, node);
            }
        }
    }
    void prepare()
    {
        dfs(1, 0);
        for (int bit = 1; bit < 20; bit++)
        {
            for (int node = 1; node <= numNode; node++)
            {
                parLevel[node][bit] = parLevel[parLevel[node][bit - 1]][bit - 1];
            }
        }
    }
    int getLca(int x, int y)
    {
        if (dist[x] < dist[y])
        {
            return getLca(y, x);
        }
        for (int bit = 19; bit >= 0; bit--)
        {
            if (dist[parLevel[x][bit]] >= dist[y])
            {
                x = parLevel[x][bit];
            }
        }
        if (x == y)
        {
            return x;
        }
        for (int bit = 19; bit >= 0; bit--)
        {
            if (dist[parLevel[x][bit]] != dist[parLevel[y][bit]])
            {
                x = parLevel[x][bit];
                y = parLevel[y][bit];
            }
        }
        return parLevel[x][0];
    }
    int getDistance(int x, int y)
    {
        int lca = getLca(x, y);
        cout << dist[x] << " " << dist[y] << " " << dist[lca] << "\n";
        return dist[x] + dist[y] - 2 * dist[lca];
    }
};
void solve()
{
    int n, marcel, valeriu;
    cin >> n >> marcel >> valeriu;
    vector<pll> edges(n + 1);
    vector<int> check(n + 1), dist(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    DSU tree(n);
    int pos = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!tree.join(edges[i].first, edges[i].second))
        {
            pos = i;
        }
    }
    vector<vector<int>> tmpAdj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        if (i != pos)
        {
            tmpAdj[edges[i].first].push_back(edges[i].second);
            tmpAdj[edges[i].second].push_back(edges[i].first);
            // cout << edges[i].first << " " << edges[i].second << "\n";
        }
    }
    cout << pos << "\n";
    LCA treeLCA(n, tmpAdj);
    // cout << treeLCA.getLca(edges[pos].first, edges[pos].second);
    // treeLCA.showTree();
    cout << treeLCA.getLca(10, 5) << "\n";
    cout << treeLCA.getDistance(10, 5);
    // đang sai lca
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--)
    {
        solve();
    }
    return 0;
}