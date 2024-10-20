

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 09:44:13
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
vector<string> split(string str) {
    vector<string> result;
    stringstream ss(str);
    string t;
    while (ss >> t) {
        result.push_back(t);
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>>adj(2 * n + 2, vector<int>());
    vector<vector<int>>tree(n + 1, vector<int>());
    vector<int>h(n + 1);
    for (int i = 1; i <= n + 1; ++i) {
        string x;
        getline(cin, x);
        vector<string> save = split(x);
        for (auto g : save) {
            adj[i - 1].push_back(stoi(g));
            adj[stoi(g)].push_back(i - 1);
        }
    }
    int t;
    cin >> t;
    function<void(int, int, int)> dfs = [&](int par, int x, int lv) {
        h[x] = lv;
        tree[lv].push_back(x);
        for (int g : adj[x]) {
            if (g != par) {
                dfs(x, g, lv + 1);
            }
        }
        };
    dfs(0, 1, 0);
    // cout << t << '\n';
    // cout << h[t] << '\n';
    bool check = false;
    for (int g : tree[h[t]]) {
        if (g != t) {
            cout << g << ' ';
            check = true;
        }
        // cout << g << " ";
    }
    if (!check) {
        cout << -1;
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