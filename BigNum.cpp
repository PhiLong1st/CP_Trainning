const int maxN = 1010;
const int LGM = 20;
int a[maxN][maxN];
int st[LGM + 1][maxN][LGM + 1][maxN];
int n;

void preprocess() {
    for (int k = 0; k <= LGM; ++k) {
        for (int i = 1; i + (1 << k) - 1 <= n; ++i) { // Loop through rows
            for (int l = 0; l <= LGM; ++l) {
                for (int j = 1; j + (1 << l) - 1 <= n; ++j) { // Loop through columns
                    if (k == 0) { // Row interval of length 1
                        if (l == 0) { // Column interval of length 1
                            st[0][i][0][j] = a[i][j];
                        }
                        else { // Preprocess column intervals
                            st[0][i][l][j] = min(st[0][i][l - 1][j], st[0][i][l - 1][j + (1 << (l - 1))]);
                        }
                    }
                    else { // Preprocess row intervals
                        st[k][i][l][j] = min(st[k - 1][i][l][j], st[k - 1][i + (1 << (k - 1))][l][j]);
                    }
                }
            }
        }
    }
}

// Function to query the minimum value in a submatrix defined by (x, y) to (a, b)
int getMin(int x, int y, int a, int b) {
    int k = __lg(a - x + 1); // Logarithm base 2 for the row length
    int l = __lg(b - y + 1); // Logarithm base 2 for the column length
    // return min({
    //     st[k][x][l][y],
    //     st[k][x][l][b - (1 << l) + 1],
    //     st[k][a - (1 << k) + 1][l][y],
    //     st[k][a - (1 << k) + 1][l][b - (1 << l) + 1]
    //     });
    return 1;
}
for (int i = k; i <= n; i += s) {
        for (int j = k; j <= n; j += s) {
            cout << spt2d.get_max(i - k + 1, j - k + 1, i, j) << ' ';
        }
        cout << '\n';
    }
struct SparseTable
{
    const int LGMAX = 20;
    vector<vector<int>> spt;
    vector<int> arr;

    SparseTable(vector<int> arr)
    {
        this->arr = arr;
        spt.assign(LGMAX, vector<int>(arr.size()));
        build();
    }

    void build()
    {
        for (int i = 0; i < arr.size(); i++) {
            spt[0][i] = arr[i];
        }
        for (int bit = 1; bit < LGMAX; bit++)
        {
            for (int i = 0; i + (1 << (bit - 1)) < arr.size(); i++)
            {
                spt[bit][i] = min(spt[bit - 1][i], spt[bit - 1][i + (1 << (bit - 1))]);
            }
        }
    }
    int get_min(int l, int r) {
        if (l > r) {
            return INT_MAX;
        }
        int lg = 31 - __builtin_clz(r - l + 1);
        return min(spt[lg][l], spt[lg][r - (1 << lg) + 1]);
    }
};