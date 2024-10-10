

/*
    Code by: KoKoDuDu
    Created: 05.10.2024 15:43:06
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 2), prefix_sum(n + 2), prefix_operation(m + 2);
    vector<array<int, 3>>operation(m + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> operation[i][0] >> operation[i][1] >> operation[i][2];
    }
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        prefix_operation[x]++;
        prefix_operation[y + 1]--;
    }
    for (int i = 1; i <= m; ++i) {
        prefix_operation[i] += prefix_operation[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
        operation[i][2] *= prefix_operation[i];
        prefix_sum[operation[i][0]] += operation[i][2];
        prefix_sum[operation[i][1] + 1] -= operation[i][2];
    }
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] += prefix_sum[i - 1];
        cout << a[i] + prefix_sum[i] << " ";
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