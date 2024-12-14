/*
  Code by: linvg
  Created: 05.12.2024 16:46:01
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG


const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> max_left(n + 2, vector<int>(m + 2));
    vector<vector<int>> max_right(n + 2, vector<int>(m + 2));
    vector<vector<int>> max_up(n + 2, vector<int>(m + 2));
    vector<vector<int>> max_down(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            max_left[i][j] = max_left[i][j - 1] + 1;
            if (a[i][j] != '.') max_left[i][j] = 0;

            max_up[i][j] = max_up[i - 1][j] + 1;
            if (a[i][j] != '.') max_up[i][j] = 0;
        }
        for (int j = m; j >= 1; --j) {
            max_right[i][j] = max_right[i][j + 1] + 1;
            if (a[i][j] != '.') max_right[i][j] = 0;
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            max_down[i][j] = max_down[i + 1][j] + 1;
            if (a[i][j] != '.') max_down[i][j] = 0;
        }
    }

    int res = 0;
    vector<int> hor, ver;
    vector<vector<int>> vsth(n + 1, vector<int>(m + 1));
    vector<vector<int>> vstv(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '.') {
                int noleft = max_up[i - 1][j] + max_down[i + 1][j] + max_right[i][j + 1] + 1;
                int noright = max_up[i - 1][j] + max_down[i + 1][j] + max_left[i][j - 1] + 1;
                int noup = max_down[i + 1][j] + max_left[i][j - 1] + max_right[i][j + 1] + 1;
                int nodown = max_up[i - 1][j] + max_left[i][j - 1] + max_right[i][j + 1] + 1;
                res = max({ res, noleft, noright, noup, nodown });
                if (!vsth[i][j]) {
                    hor.push_back(max_left[i][j - 1] + max_right[i][j + 1] + 1);
                    for (int x = j - max_left[i][j - 1]; x <= j + max_right[i][j + 1]; ++x) {
                        vsth[i][x] = max_left[i][j - 1] + max_right[i][j + 1] + 1;
                    }
                }
                if (!vstv[i][j]) {
                    ver.push_back(max_up[i - 1][j] + max_down[i + 1][j] + 1);
                    for (int x = i - max_up[i - 1][j]; x <= i + max_down[i + 1][j]; ++x) {
                        vstv[x][j] = max_up[i - 1][j] + max_down[i + 1][j] + 1;
                    }
                }
            }
        }
    }
    sort(all(ver), greater<int>());
    sort(all(hor), greater<int>());
    if (sz(ver) > 1) res = max(res, ver[0] + ver[1]);
    if (sz(hor) > 1) res = max(res, hor[0] + hor[1]);

    vector<vector<int>> vst(n + 1, vector<int>(m + 1));
    vector<int> max_in_comp;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vst[i][j] && a[i][j] == '.') {
                queue<pair<int, int>> q;
                q.push({ i, j });
                int maxHor = 0, maxVer = 0;
                vst[i][j] = 1;
                while (!q.empty()) {
                    // auto [x, y] = q.front();
                    pair<int, int> t = q.front();
                    int x = t.first, y = t.second;
                    q.pop();

                    maxHor = max(maxHor, max_left[x][y - 1] + max_right[x][y + 1] + 1);
                    maxVer = max(maxVer, max_up[x - 1][y] + max_down[x + 1][y] + 1);

                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = dx[dir] + x;
                        int ny = dy[dir] + y;
                        if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                        if (vst[nx][ny] || a[nx][ny] != '.') continue;
                        q.push({ nx, ny });
                        vst[nx][ny] = 1;
                    }
                }

                max_in_comp.push_back(max(maxVer, maxHor));
            }
        }
    }

    sort(all(max_in_comp), greater<int>());
    // dbg(max_in_comp);
    if (sz(max_in_comp) > 1) res = max(res, max_in_comp[0] + max_in_comp[1]);

    cout << res << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}