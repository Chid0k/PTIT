#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int n, st, a[100][100], dist[1000], check[1000], bak[1000];

void init()
{
    memset(check, 0, sizeof(check));
    memset(bak, 0, sizeof(bak));
    for (int i = 1;i <= n; i++)
    {
        dist[i] = 9999;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                a[i][j] = 9999;
        }
    }
    dist[st] = 0;
}

void solve()
{
    queue<int> q;
    q.push(st);
    check[st] = 1;
    while (q.empty() == false)
    {
        int i = q.front();
        q.pop();
        check[i] = 0;
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 9999 && check[j] == 0)
            {
                if (dist[j] > dist[i] + a[i][j])
                {
                    dist[j] = dist[i] + a[i][j];
                    bak[j] = i;
                    if (check[j] == 0)  
                    {
                        q.push(j);
                        check[j] = 1;
                    }
                }
                
            }
        check[i] = 1;
        for (int i = 1; i <= n; i++)
            cout << dist[i] << ' ';
        cout << endl;
    }
}

int main()
{
    cin >> n >> st;
    init();
    solve();
}