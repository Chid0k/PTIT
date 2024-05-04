#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int n, a[100][100], check[100]= {0}, d;
stack <int> f;
vector <int> kq;

void DFS(int i)
{
    d = d + 1;
    check[i] = 1;
    for (int j = 1; j <= n; j++)
        if (check[j] == 0 && a[i][j] == 1)
            DFS(j);
}

void solve()
{
    for (int u = 1; u <= n; u++)
    {
        d = 0;
        memset(check, 0, 100);
        DFS(u);
        if (d != n)
        {
            cout << "not strongly connected";
            return;
        }
    }
    cout << "strongly connected";
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    solve();
}

