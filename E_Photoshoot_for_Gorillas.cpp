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
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> save(w + 1), best;
    for (int i = 1; i <= w; i++)
    {
        cin >> save[i];
    }

    vector2d(rect, n + 2, m + 2, int, 0);
    for (int i = k; i <= n; ++i)
    {
        for (int j = k; j <= m; ++j)
        {
            rect[i - k + 1][j - k + 1] += 1;
            rect[i + 1][j + 1] += 1;
            rect[i - k + 1][j + 1] -= 1;
            rect[i + 1][j - k + 1] -= 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        rect[i][0] += rect[i - 1][0];
    for (int i = 1; i <= m; ++i)
        rect[0][i] += rect[0][i - 1];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            rect[i][j] += rect[i - 1][j] + rect[i][j - 1] - rect[i - 1][j - 1];
            best.push_back(rect[i][j]);
        }
    }

    sort(best.begin(), best.end(), greater<int>());
    sort(save.begin() + 1, save.end(), greater<int>());

    int kq = 0;
    for (int i = 1; i <= w; ++i)
    {
        kq += best[i - 1] * save[i];
    }

    cout << kq << "\n";
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