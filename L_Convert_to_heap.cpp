/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pll pair<ll, ll>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), b(q + 1), need(n + 1);
    vector<vector<ll>> adj(n + 1, vector<ll>());
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll sum = 0;
    for (ll i = 1; i <= q; i++)
    {
        cin >> b[i];
        sum += b[i];
    }
    vector<int> dp(sum + 10, 0);
    bool ok = true;
    dp[0] = 1;
    for (ll i = 1; i <= q; i++)
    {
        for (ll j = sum; j >= b[i]; j--)
        {
            dp[j] |= dp[j - b[i]];
        }
    }
    vector<int> save;
    for (ll i = 1; i <= sum; i++)
    {
        if (dp[i])
        {
            save.push_back(i);
        }
    }
    function<void(ll x, ll par)> dfs = [&](ll x, ll par)
    {
        need[x] = a[x];
        for (ll g : adj[x])
        {
            if (g != par)
            {
                dfs(g, x);
                need[x] = max(need[x], a[g]);
            }
        }
        if (need[x] > a[x])
        {
            int vt = lower_bound(save.begin(), save.end(), need[x] - a[x]) - save.begin();
            if (vt >= save.size())
            {
                ok = false;
            }
            else
            {
                a[x] += save[vt];
            }
        }
    };
    dfs(1, 0);
    if (!ok)
    {
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans += a[i];
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}