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
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<vector<int>> save(30);
    for (int i = 1; i <= n; i++)
    {
        int g = s[i] - 'a';
        save[g].push_back(i);
    }
    for (int i = 0; i < 30; i++)
    {
        if (save[i].size() == 0)
        {
            continue;
        }
        for (int j = 1; j < save[i].size(); j++)
        {
            if ((save[i][j] - save[i][j - 1]) % 2 != 0)
            {
                cout << "NO\n";
                return;
            }
        }
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