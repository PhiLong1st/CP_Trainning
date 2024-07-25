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
    int l, r, n;
    cin >> l >> r >> n;
    if (l * r % n != 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    int val = (l * r) / n;
    vector<vector<int>> ans(l + 2, vector<int>(r + 2));
    for (int i = 1; i <= val; i++)
    {
        if (val % i == 0)
        {
            int j = val / i;
            bool ok1 = (l % i == 0 && r % j == 0);
            bool ok2 = (l % j == 0 && r % i == 0);
            if (ok1 || ok2)
            {
                int ansX, ansY;
                if (ok1)
                {
                    ansX = i;
                    ansY = j;
                }
                else
                {
                    ansX = j;
                    ansY = i;
                }
                int type = 0;
                // cout << i << " " << j << "\n";
                for (int i = 1; i <= l; i += ansX)
                {
                    for (int j = 1; j <= r; j += ansY)
                    {
                        // cout << i << " " << j << "\n";
                        for (int t = i; t < i + ansX; t++)
                        {
                            for (int p = j; p < j + ansY; p++)
                            {
                                ans[t][p] = type;
                                // cout << t << " " << p << "\n";
                            }
                        }
                        type++;
                    }
                }
                for (int i = 1; i <= l; i++)
                {
                    for (int j = 1; j <= r; j++)
                    {
                        // cout << ans[i][j] << " ";
                        cout << (char)(ans[i][j] + 'a');
                    }
                    cout << "\n";
                }
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
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