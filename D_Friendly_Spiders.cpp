
/*
    Code by: KoKoDuDu
    Created: 25.09.2024 18:53:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, s, t;
    cin >> n;
    vector<int> a(n + 1), vst(1000000), trace(1000000);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int> >adj(1000000, vector<int>());
    cin >> s >> t;
    for (int i = 1; i <= n; ++i) {
        int val = a[i];
        for (int j = 2; j * j <= a[i]; ++j) {
            if (val % j == 0) {
                adj[i].push_back(n + j);
                adj[n + j].push_back(i);
                while (val % j == 0) {
                    val /= j;
                }
            }
        }
        if (val != 1) {
            adj[i].push_back(n + val);
            adj[n + val].push_back(i);
        }
    }
    queue<int> save;
    save.push(s);
    vst[s] = 1;
    while (!save.empty()) {
        int x = save.front();
        save.pop();
        if (x == t) {
            cout << (vst[x] + 1) / 2 << '\n';
            vector<int> path;
            path.push_back(t);
            while(trace[x] != 0) {
                path.push_back(trace[x]);
                x = trace[x];
            }
            reverse(path.begin(),path.end());
            for (int i = 0; i < path.size(); i += 2) {
                cout << path[i] << ' ';
            }
            break;
        }
        for (int g: adj[x]) {
            if (!vst[g]) {
                vst[g] = vst[x] + 1;
                trace[g] = x;
                save.push(g);
            }
        }
    }
    if (vst[t] == 0) {
        cout << -1 ;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
} 