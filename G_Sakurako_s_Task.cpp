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
    vector<int> a(n + 1);
    int gcd = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        gcd = __gcd(gcd, a[i]);
    }
    if (n == 1)
    {
        if (a[1] < k)
        {
            cout << k << "\n";
        }
        else
        {
            cout << k - 1 << "\n";
        }
        return;
    }
    int maxx = (n - 1) * gcd;
    int du = maxx - n + 1;
    if (k <= du)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (k - gcd + 1 <= 0)
            {
                cout << k + max(0LL, i) * gcd << "\n";
                return;
            }
            k -= gcd - 1;
        }
    }
    else
    {
        k -= du;
        cout << maxx + k << "\n";
    }
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