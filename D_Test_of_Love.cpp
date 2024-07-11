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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = "L" + s + "L";
    vector<int> dp(n + 2, 0);
    int state = 0, cntW = 0;
    for (int i = 0; i <= n; i++)
    {
        // cout << i << ": ";
        if (s[i] == 'C')
        {
            cout << "NO\n";
            return;
        }
        if (s[i] == 'L')
        {
            state = 0;
            int posL = -1, posW = -1;
            for (int j = i + 1; j <= min(n + 1, i + m); j++)
            {
                if (s[j] == 'L')
                {
                    posL = j;
                }
                if (s[j] == 'W')
                {
                    posW = j;
                }
            }
            if (posL == -1 && posW == -1)
            {
                cout << "NO\n";
                return;
            }
            if (posL != -1)
            {
                state = 0;
                // cout << i << " " << posL << "a\n";
                i = posL - 1;
            }
            else
            {
                // cout << i << " " << posW << "b\n";
                i = posW - 1;
                state = 1;
            }
            continue;
        }
        if (s[i] == 'W')
        {
            cntW++;
            if (cntW > k)
            {
                cout << "NO\n";
                return;
            }
        }
        // cout << i << " ";
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