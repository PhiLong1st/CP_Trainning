
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 10:01:17
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

const int dx[] = { 0, 1 };
const int dy[] = { 1, 0 };

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    int save_x, save_y;
    for (int i = 1; i <= n; ++i) {
        if (__gcd(i, a) == 1) save_x = i;
        if (__gcd(i, b) == 1) save_y = i;
    }
    int ans = 0;
    for (int i = 1; i <= save_x; ++i) {
        ans += 1;
        ans += __gcd(i, a);
    }
    for (int i = 2; i <= save_y; ++i) {
        ans += 1;
        ans += __gcd(i, b);
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    unordered_map<int, int, custom_hash> dist;
    q.push({ 0, save_x, save_y });
    dist[save_x * n + save_y] = 0;
    while (!q.empty()) {
        auto [d, x, y] = q.top();
        q.pop();
        if (x == n && y == n) break;
        if (dist[x * n + y] < d) continue;
        for (int i = 0; i < 2; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx > n || ny > n) continue;
            if (dist.count(nx * n + ny) == 0 || dist[nx * n + ny] > d + gcd(nx, a) + gcd(ny, b)) {
                dist[nx * n + ny] = d + gcd(nx, a) + gcd(ny, b);
                q.push({ d + gcd(nx, a) + gcd(ny, b), nx, ny });
            }
        }
    }
    cout << ans + dist[n * n + n] << '\n';
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