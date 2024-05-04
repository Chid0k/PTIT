#include <bits/stdc++.h>
using namespace std;

int n, a[100][100], check[100] = {0}, d = 0;
queue <int> f;

void Solve(int i)
{
    f.push(i);
    check[i] = 1;
    cout << i << ' ';
    while (f.empty() == false)
    {
        int gt = f.front();
        check[gt] = 1;
        f.pop();
        for (int j = 1; j <= n; j++)
            if (a[gt][j] == 1 && check[j] == 0)
            {
                cout << j << ' ';
                check[j] = 1;
                f.push(j);
            }
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        if (check[i] == 0)
        {
            cout << "Thanh phan lien thong " << d+1 << endl;
            Solve(i);
            d++;
            cout << endl;
        }
    
}