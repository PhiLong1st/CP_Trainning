

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 08:57:57
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
struct Point {
    int x, y;
};

void solve() {
    Point x1, x2, x3, y1, y2, y3;
    cin >> x1.x >> x1.y >> x2.x >> x2.y >> x3.x >> x3.y;
    cin >> y1.x >> y1.y >> y2.x >> y2.y >> y3.x >> y3.y;
    Point min1, max1, min2, max2;
    min1.x = min({ x1.x, x2.x, x3.x });
    min1.y = min({ x1.y, x2.y, x3.y });
    min2.x = min({ y1.x, y2.x, y3.x });
    min2.y = min({ y1.y, y2.y, y3.y });
    max1.x = max({ x1.x, x2.x, x3.x });
    max1.y = max({ x1.y, x2.y, x3.y });
    max2.x = max({ y1.x, y2.x, y3.x });
    max2.y = max({ y1.y, y2.y, y3.y });

    bool ok1 = !(max1.x < min2.x || max2.x < min1.x);
    bool ok2 = !(max1.y < min2.y || max2.y < min1.y);

    if (ok1 && ok2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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

