/*
    Code by: KoKoDuDu
    Created: 02.10.2024 18:39:31
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pint pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), prefix_xor(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>());
    map<int, int> save;
    int cnt = 0;
    adj[0].push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix_xor[i] = prefix_xor[i - 1] ^ a[i];
        if (save.find(prefix_xor[i]) == save.end()) {
            cnt++;
            save[prefix_xor[i]] = cnt;
        }
        adj[save[prefix_xor[i]]].push_back(i);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int val = prefix_xor[r] ^ prefix_xor[l - 1];
        if (val == 0) {
            cout << "YES\n";
        }
        else {
            auto it = lower_bound(adj[prefix_xor[r]].begin(), adj[prefix_xor[r]].end(), l);
            if (*it < r) {
                int l1 = *it + 1;
                int need = prefix_xor[l1 - 1] ^ val;
                it = lower_bound(adj[need].begin(), adj[need].end(), l1);
                if (it != adj[need].end() && *it < r) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
            else {
                cout << "NO\n";
            }
        }
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}
