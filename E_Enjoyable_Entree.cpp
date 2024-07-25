/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const int MOD = 1e9 + 7;
const int INF = 1e18;

vector<vector<db>> multiplyMatrices(const vector<vector<db>> &matrix1, const vector<vector<db>> &matrix2)
{
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();
    // Resultant matrix of size rows1 x cols2
    vector<vector<db>> result(rows1, vector<db>(cols2, 0));

    // Multiply the matrices
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            for (int k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}
vector<vector<db>> lt(vector<vector<db>> a, int x)
{
    if (x == 1)
    {
        return a;
    }
    vector<vector<db>> tmp = lt(a, x / 2);
    if (x % 2 == 0)
    {
        return multiplyMatrices(tmp, tmp);
    }
    else
    {
        vector<vector<db>> z = multiplyMatrices(tmp, tmp);
        return multiplyMatrices(a, z);
    }
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        return void(cout << 100 << " " << 0);
    }
    if (n == 2)
    {
        return void(cout << 0 << " " << 100);
    }
    vector<vector<db>> matrix1 = {
        {100, 0}};

    vector<vector<db>> matrix2 = {
        {0.5, 1},
        {0.5, 0}};
    vector<vector<db>> ans = multiplyMatrices(matrix1, lt(matrix2, n - 2));
    // vector<vector<db>> ans = lt(matrix2, n - 2);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[0].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << fixed << setprecision(6) << (db)100 - ans[0][0] << " " << ans[0][0];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}