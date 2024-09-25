/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

struct info
{
    int x, y, z;
    info(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    bool operator<(const info &other) const
    {
        if (x != other.x)
            return x < other.x;
        if (y != other.y)
            return y < other.y;
        return z < other.z;
        // return false;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    // vector<int> a1, a2, a3;
    int sz1, sz2, sz3;
    cin >> sz1;
    vector<int> s1(sz1);
    for (int j = 0; j < sz1; j++)
    {
        cin >> s1[j];
    }
    cin >> sz2;
    vector<int> s2(sz2);
    for (int j = 0; j < sz2; j++)
    {
        cin >> s2[j];
    }
    cin >> sz3;
    vector<int> s3(sz3);
    for (int j = 0; j < sz3; j++)
    {
        cin >> s3[j];
    }
    int lv1 = 0, lv2 = 0, lv3 = 0;
    // vector<vector<vector<int>>> dp(sz1 + 1, vector<vector<int>>(sz2 + 1, vector<int>(sz3 + 1, 0)));
    map<info, int> check;
    // dp[0][0][0] = 1;
    check[info(0, 0, 0)] = 1;
    while (lv1 < sz1 || lv2 < sz2 || lv3 < sz3)
    {
        int x = s1[sz1 - lv1 - 1];
        int y = s2[sz2 - lv2 - 1];
        int z = s3[sz3 - lv3 - 1];
        if (x == y)
        {
            lv1++;
            lv2++;
            // dp[lv1][lv2][lv3] = 1;
            check[info(lv1, lv2, lv3)] = 1;
            continue;
        }
        if (y == z)
        {
            lv2++;
            lv3++;
            // dp[lv1][lv2][lv3] = 1;
            check[info(lv1, lv2, lv3)] = 1;

            continue;
        }
        if (z == x)
        {
            lv1++;
            lv3++;
            // dp[lv1][lv2][lv3] = 1;
            check[info(lv1, lv2, lv3)] = 1;
            continue;
        }
        break;
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        // cout << x << " " << y << " " << z << " ";
        // cout << ((dp[sz1 - x][sz2 - y][sz3 - z]) ? "MofK" : "Lihwy") << "\n";
        // check[info(lv1, lv2, lv3)] = 1;

        cout << ((check[info(sz1 - x, sz2 - y, sz3 - z)] != 0) ? "MofK" : "Lihwy") << "\n";
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