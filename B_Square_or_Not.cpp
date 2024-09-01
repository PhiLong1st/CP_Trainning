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
    int x = sqrt(n);
    if (x * x == n)
    {
        vector<vector<char>> a(x, vector<char>(x));
        vector<vector<char>> b(x, vector<char>(x, '0'));

        int dem = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < x; j++)
            {
                a[i][j] = s[dem];
                dem++;
            }
        }
        for (int i = 0; i < x; i++)
        {
            b[0][i] = '1';
            b[i][0] = '1';
            b[i][x - 1] = '1';
            b[x - 1][i] = '1';
        }
        // for (int i = 0; i < x; i++)
        // {
        //     for (int j = 0; j < x; j++)
        //     {
        //         cout << b[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        if (a == b)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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