#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define vt vector
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vt<int> a = {100, 200, 300};
    a.push_back(n);

    FOR(i, 0, a.size())
    {
        cout << a[i] << " ";
    }

    return 0;
}