#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, a[100][100], check[100], kq[1000];
vector<pair <int, int>> edge;

void _init_()
{
    memset(check, 0, sizeof(check));
    edge.clear();
}

void DFS_tree(int i)
{
    check[i] = 1;
    for (int j = 1; j <= n; j++)
        if (a[i][j] == 1 && check[j] == 0)
        {
            edge.push_back({i, j});
            DFS_tree(j);
        }
}

void BFS_tree(int i)
{
    queue<int> q;
    q.push(i);
    check[i] = 1;
    while (q.empty() == false)
    {
        int kt = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
            if (a[kt][i] == 1 && check[i] == 0)
            {
                check[i] = 1;
                q.push(i);
                edge.push_back({kt, i});
            }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int start;
    cin >> start;

    _init_();
    DFS_tree(start);
    for (auto x: edge)
        cout << x.first << ' ' << x.second << endl;

    _init_();
    BFS_tree(start);
    for (auto x: edge)
        cout << x.first << ' ' << x.second << endl;

}