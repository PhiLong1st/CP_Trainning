/*
  Code by: KoKoDuDu
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pll pair<int,int>

const int INF = 1e18;
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void solve()
{
    int R, C, N, r, c, ans = 0, res = 0;
    cin >> R >> C >> N >> r >> c;
    vector<pll> s(N), wa, pm;
    vector<vector<char>> a(R, vector<char>(C, ' '));
    vector<vector<int>> dp(R, vector<int>(C, INF));
    queue<pll> pl;
    vector<vector<vector<int>>> d(N, vector<vector<int>>(R, vector<int>(C, INF)));
    --r, --c;
    for (int i = 0; i < N; ++i) {
        cin >> s[i].first >> s[i].second;
        --s[i].first, --s[i].second;
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> a[i][j];
            if (a[i][j] != 'W') {
                pm.push_back({ i, j });
            }
            else {
                wa.push_back({ i, j });
            }
        }
    }
    pl.push({ r, c });
    dp[r][c] = 0;
    function< bool(int, int) > ok = [&](int a, int b) {
        return (a < 0 || a >= R || b < 0 || b >= C);
        };
    while (!pl.empty()) {
        int x = pl.front().first, y = pl.front().second;
        pl.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (!ok(xx, yy)) {
                if (a[xx][yy] == '.' && dp[xx][yy] == INF) {
                    dp[xx][yy] = dp[x][y] + 1;
                    pl.push({ xx, yy });
                }
                if (a[xx][yy] != '.') {
                    dp[xx][yy] = min(dp[xx][yy], dp[x][y] + 1);
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        queue<pll> q;
        q.push(s[i]);
        d[i][s[i].first][s[i].second] = 0;
        while (q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int xx = x + dx[k], yy = y + dy[k];
                if (!ok(xx, yy)) {
                    if (a[xx][yy] == '.' && d[i][xx][yy] == INF) {
                        d[i][xx][yy] = d[i][x][y] + 1;
                        q.push({ xx, yy });
                    }
                    if (a[xx][yy] != '.') {
                        d[i][xx][yy] = min(d[i][xx][yy], d[i][x][y] + 1);
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        ans += d[i][r][c];
    }
    for (int i = 0; i < wa.size(); ++i) {
        int save = 0, x = wa[i].first, y = wa[i].second;
        for (int j = 0; j < N; ++j) {
            save += min(d[j][x][y] + dp[x][y], d[j][r][c]);
        }
        res += max(0LL, ans - save);
    }
    cout << ans << ' ' << res << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}