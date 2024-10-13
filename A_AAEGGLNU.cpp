

/*
    Code by: KoKoDuDu
    Created: 11.10.2024 21:59:23
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n;
    vector<string> a(n + 1);
    vector < pair<string, pair<string, int>> > save;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        string tmp = a[i];
        sort(a[i].begin(), a[i].end());
        save.push_back({ a[i], make_pair(tmp, 0) });
    }
    cin >> m;
    vector<string> b(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        string tmp = b[i];
        sort(b[i].begin(), b[i].end());
        save.push_back({ b[i], make_pair(tmp, i) });
    }
    function<bool(pair<string, pair<string, int> >, pair<string, pair<string, int>>)>cmp = [&](pair<string, pair<string, int> >  a, pair<string, pair<string, int>> b) {
        if (a.first == b.first) {
            if (a.second.first == b.second.first) {
                return a.second.second > b.second.second;
            }
            return a.second.first < b.second.first;
        }
        return a.first < b.first;
        };
    sort(save.begin(), save.end(), cmp);
    vector<int> ans(m + 1);
    int cnt = 0;
    for (auto s : save) {
        // cout << s.first << " " << s.second.second << "\n";
        cnt += (s.second.second == 0);
        if (s.second.second != 0) {
            ans[s.second.second] = cnt;
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}