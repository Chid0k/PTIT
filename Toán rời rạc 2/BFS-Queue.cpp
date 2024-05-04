#include <iostream>
#include <queue>
using namespace std;

int n, a[100][100], check[1000] = {0};
queue <int> f;

void BFS(int i)
{
    f.push(i);
    check[i] = 1;
    while (f.empty() == false)
    {
        int vt =  f.front();
        cout << vt << ' ';
        f.pop();
        for (int j = 1; j <= n; j++)
            if (a[vt][j] == 1 && check[j] == 0)
            {
                f.push(j);
                check[j] = 1;
            }
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    BFS(5);
}