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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 1, r = n;
    ll sz = n / (2LL * k);
    ll ans = INF;
    vector<pll> save;
    ll maxx = -INF;
    ll minn = INF;

    for (ll j = 1; j < k + 1; j++)
    {
        // cout << j << " " << j + k << "\n";
        save.push_back(make_pair(j, j + k));
        maxx = max(maxx, a[j] + a[j + k]);
        minn = min(minn, a[j] + a[j + k]);
    }
    l = l + 2 * k;

    for (ll j = n; j > n - k; j--)
    {
        // cout << j << " " << j - k << "\n";
        save.push_back(make_pair(j, j - k));
        maxx = max(maxx, a[j] + a[j - k]);
        minn = min(minn, a[j] + a[j - k]);
    }
    r = r - 2 * k;

    // l++;
    // r--;
    while (l < r)
    {
        // cout << l << " " << r << "\n";
        save.push_back(make_pair(l, l + 1));
        maxx = max(maxx, a[l] + a[l + 1]);
        minn = min(minn, a[l] + a[l + 1]);
        l += 2;
    }
    cout << maxx - minn << "\n";
    for (ll i = 0; i < save.size(); i++)
    {
        cout << save[i].first << " " << save[i].second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll numTest = 1;
    cin >> numTest;
    while (numTest--)
    {
        solve();
    }
    return 0;
}