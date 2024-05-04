#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[100][100], d, ct, check[100] = {0};
struct edge
{
    int u, v, c;
};
vector <edge> Edge, kq;

void min_c()
{
    int min = 9999, s, e;
    for (int i = 1; i <= n; i++)
        if (check[i] == 1)
        {
            for (int j = 1; j <= n; j++)
                if (a[i][j] != 0 && check[j] == 0)
                {
                    if (a[i][j] < min)
                    {
                        min = a[i][j];
                        s = i; 
                        e = j;
                    }
                }
        }
    check[e] = 1;
    kq.push_back({s, e, min});
    d = d + min;
    
}

void Prim(int i)
{
    check[i] = 1; ct = 1, d = 0;
    while (ct < n)
    {
        min_c();
        ct++;
    }
    cout << "dH = " <<d << endl;
    for (auto x: kq)
        cout << x.u << ' ' << x.v << endl;
}


int main()
{
    int start;
    cin >> n >> start;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int h;
            cin >> h;
            a[i][j] = h;
            if (h != 0) // không có đường đi
                Edge.push_back({i, j, h});
        }

    Prim(start);
    
}

// +   Cho 1 đỉnh vào tập đỉnh V.
// +   Tìm đỉnh x có trọng số nhỏ nhất kết nối với tập đỉnh V.
// +   Cho đỉnh x vào tập đỉnh V.
// +   Tree đủ n đỉnh
