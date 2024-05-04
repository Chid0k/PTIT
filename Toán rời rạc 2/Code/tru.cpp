#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int n, m, check[100], min_lt = 0;
vector <int> a[100];

void DFS(int i, int pass)
{
    check[i] = 1;
    for (auto j : a[i])
        if (check[j] == 0 && j != pass)
            DFS(j, pass);
}

int ct(int pass)
{
    min_lt = 0;
    for (int i = 1; i <= n; i++)
        if (check[i] == 0 && i != pass)
        {
            DFS(i, pass);
            min_lt++;
        }
    return min_lt;
    
}

void init()
{
    for (int i = 1; i <= n; i++)
        a[i].clear();
    memset(check, 0 , sizeof(check));
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        memset(check, 0 , sizeof(check));
        if (ct(i) > ct(0))
            cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        init();
        solve();
    }
}

// Loại bỏ đỉnh làm tăng thành phần liên thông của đồ thị