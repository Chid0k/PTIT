#include <bits/stdc++.h>
using namespace std;

int n, a[100][100], check[10000] = {0};

void DFS(int i)
{
    cout << i << ' ';
    check[i] = 1;
    for (int j = 1; j <= n; j++)
        if (check[j] == 0 && a[i][j] == 1)
            DFS(j);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    DFS(10);
}