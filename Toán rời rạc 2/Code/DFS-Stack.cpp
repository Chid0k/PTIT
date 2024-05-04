#include <bits/stdc++.h>
using namespace std;

int n, a[100][100];
stack <int> check;
int kt[1000] = {0};

void DFS(int i)
{
    cout << i << ' ';
    check.push(i);
    kt[i] = 1;
    while (check.empty() == false)
    {
        i = check.top();
        check.pop();
        for (int j = 1; j <= n; j++)        
            if (kt[j] == 0 && a[i][j] == 1)
            {
                cout << j << ' ';
                kt[j] = 1;
                check.push(i);
                check.push(j);
                break; // xet 1
            }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    DFS(1);
}