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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> saveA(1010, 0);
    vector<int> saveB(1010, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        saveA[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        saveB[b[i]]++;
    }
    for (int val = 0; val <= 1000; val++)
    {
        if (saveA[val] == 0 || saveB[val] == 0)
        {
            continue;
        }
        int tmp = min(saveA[val], saveB[val]);
        ans += tmp;
        saveA[val] -= tmp;
        saveB[val] -= tmp;
    }
    int maxx = 0, cnt = 0;
    for (int i = 0; i <= 1000; i++)
    {
        cnt += saveB[i];
    }
    if (cnt != 0)
    {
        for (int i = 0; i <= 1000; i++)
        {
            if (saveA[i] != 0)
            {
                maxx = 1;
            }
        }
    }
    cout << ans + maxx;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}