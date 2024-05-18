#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n, a[100][100], check[100], st, en;
int dist[100], back[100];

void init()
{
    memset(check, 0, sizeof(check));
    memset(a, 0 , sizeof(a));
    memset(back, 0 , sizeof(back));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        if ( i == st)
            dist[i] = 0;
        else
            dist[i] = 9999;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void dijkstra(int s)
{
    int k = 0;
    queue <int> q;
    q.push(s);
    while ((k++) < (2 *n ))
    {
        int i = q.front();
        q.pop();
        cout << i << ": ";
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 0 && check[j] == 0)
            {
                q.push(j);
                cout << j << ' ';
                if (dist[j] > dist[i] + a[i][j])
                {
                    dist[j] = dist[i] + a[i][j];
                    back[j] = i;
                }
            }
        cout << endl;
        for (int i = 1; i <= n; i++)
            cout << dist[i] << ' ';
        cout << endl;
    }
}

void solve()
{
    dijkstra(st);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != 9999)
        {
            printf("K/c %d -> %d = %d;\t", st, i, dist[i]);
            cout << i;
            if (i == st)
                cout << " <- " << i << endl;
            else
            {
                int b = back[i];
                while (b != 0)
                {
                    cout << " <- " << b;
                    b = back[b];
                }
                cout << endl;
            }
        }
        else
            printf("K/c %d -> %d = INF;\n", st, i);
        
    }
    
}
        


int main()
{
    cin >> n >> st;
    init();
    solve();
}
