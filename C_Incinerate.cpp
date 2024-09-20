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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> maxx;
    set<int> save;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        save.insert(b[i]);
        maxx[b[i]] = max(maxx[b[i]], a[i]);
    }
    int sum = k;
    for (int i : save)
    // int i = 1;
    {
        if (sum >= maxx[i])
        {
            continue;
        }
        k -= i;
        int l = 0, r = ((k + i - 1) / i) + 1;
        int res = -1;
        // cout << i << " " << maxx[i] << " " << r << " " << k << "a\n";
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int val = mid * k - i * mid * (mid - 1) / 2;
            int du = maxx[i] - sum;
            if (val >= du)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        // cout << res << "\n";
        if (res == -1)
        {
            cout << "NO\n";
            return;
        }
        sum += res * k - i * res * (res - 1) / 2;
        k -= i * (res - 1);
        if (k < 0)
        {
            cout << "NO\n";
            return;
        }
        // cout << res << " " << sum << " " << k << "\n";
    }
    cout << "YES\n";
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