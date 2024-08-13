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
    int n, m;
    cin >> n >> m;
    map<int, int> check;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        check[x] = 1;
    }
    int dem = 1;
    while (m > 0)
    {
        if (check[dem] == 0)
        {
            m -= dem;
            check[dem] = 1;
        }
        dem++;
        if (m < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    int ans = 0, last = 0;
    for (int i = 1; i <= 1000; i++)
    {
        ans += check[i];
        if (check[i])
        {
            last = i;
        }
    }
    if (ans == last)
    {

        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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