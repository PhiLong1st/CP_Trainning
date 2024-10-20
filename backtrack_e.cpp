/*
    Code by: KoKoDuDu
    Created: 16.10.2024 21:41:58
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), save;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << (a[1] % m == 0) << "\n";
        return;
    }
    // 0 1 2 3 -> + - * /
    int ans = 0;
    function< void(int)> backtrack = [&](int pos) {
        if (pos == n - 1) {
            int val = 0;
            stack<int>st;
            st.push(a[1]);
            for (int i = 0; i < save.size(); ++i) {
                if (save[i] == 2) {
                    st.top() *= a[i + 2];
                    st.top() %= m;
                }
                else {
                    st.push((save[i] == 0) ? a[i + 2] : -a[i + 2]);
                }
            }
            while (!st.empty()) {
                val += st.top();
                val %= m;
                st.pop();
            }
            ans += (val % m == 0);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            save.push_back(i);
            if (pos < n - 1) {
                backtrack(pos + 1);
            }
            save.pop_back();
        }
        };
    backtrack(0);
    cout << ans << '\n';

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