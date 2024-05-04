#include <iostream>
#include <queue>
using namespace std;

int n, a[100][100], kq[100] = {0}, ckd[100] ={0}, ckb[100] = {0}, s, t;
queue <int> f;

int d[100] = {}, b[100] = {};


void DFS(int i, int k)
{
    d[k] = i;
    ckd[i] = 1;
    if (i == t)
    {
        cout << "DFS path: ";
        for (int i = k; i >= 1; i--)
            cout << d[i] << ' ';
    }
    for (int j = 1; j <= n; j++)
        if (a[i][j] == 1 && ckd[j] == 0)
            DFS(j, k + 1);
}

void BFS(int i)
{
    f.push(i);
    ckb[i] = 1;
    while (f.empty() == false)
    {
        int vt = f.front();
        f.pop();
        for (int j = 1; j <= n; j++)
            if (a[vt][j] == 1 && ckb[j] == 0)
            {
                f.push(j);
                ckb[j] = 1;
                kq[j] = vt;
            }
    }
    if (kq[t] != 0)
    {
        DFS(s, 1);
        cout << "\nBFS path: ";
        while (kq[t] != 0)
        {
            cout << t << ' ';
            t = kq[t];
        }
        cout << t << ' ';
    }
    else
        cout << "no path";
    
}


int main()
{
    cin >> n;
    cin >> s >> t;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    BFS(s);

}
