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
    vector<int> a(10);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x % 10]++;
    }
    vector<tuple<int, int, int>> save;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if ((i + j + k) % 10 == 3)
                {
                    save.push_back(make_tuple(i, j, k));
                }
            }
        }
    }
    for (auto x : save)
    {
        int u = a[get<0>(x)];
        int v = a[get<1>(x)];
        int w = a[get<2>(x)];
        a[get<0>(x)]--;
        a[get<1>(x)]--;
        a[get<2>(x)]--;
        if (min({a[get<0>(x)], a[get<1>(x)], a[get<2>(x)]}) < 0)
        {
        }
        else
        {
            cout << "YES\n";
            return;
        }
        a[get<0>(x)] = u;
        a[get<1>(x)] = v;
        a[get<2>(x)] = w;
    }
    cout << "NO\n";
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