#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll cubic_root(long long cube)
{
    // Slow solution - Linear search
    // for (long long i = 1; i * i * i <= cube; i++)
    // {
    //     if (i * i * i == cube) return i;
    // }
    // return -1;

    // Fast solution - Binary search
    ll left = 1;
    ll right = 1e4 + 1;
    while (right - left > 1)
    {
        long long m = (right + left) / 2;
        if (m * m * m <= cube) left = m;
        else right = m;
    }
    if (left * left * left != cube) return -1;
    return left;
}

int main()
{
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        bool is_representable = false;
        long long x;
        cin >> x;

        for (int a = 1; (ll)a * a * a <= x; a++)
        {
            ll b_cubed = x - (ll)a * a * a;
            if (cubic_root(b_cubed) == -1) continue;
            is_representable = true;
        }

        if (is_representable) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}
