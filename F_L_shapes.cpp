
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 16:56:03
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    vector<vector<int>> vst(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vst[i][j] && a[i][j] == '*') {
                int dem = 1;
                queue<pll> save;
                set<int> save_x, save_y;
                save_x.insert(i);
                save_y.insert(j);
                save.push({ i, j });
                int cnt = 0;
                vst[i][j] = 1;
                while (!save.empty()) {
                    pll cell = save.front();
                    save.pop();
                    for (int i = 0; i < 8; ++i) {
                        int xx = cell.first + dx[i];
                        int yy = cell.second + dy[i];
                        if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] == '*' && !vst[xx][yy]) {
                            dem++;
                            save.push({ xx,yy });
                            save_x.insert(xx);
                            save_y.insert(yy);
                            vst[xx][yy] = 1;
                        }
                    }
                }
                if ((int)save_x.size() == 3 || (int)save_y.size() == 3 || dem != 3) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}