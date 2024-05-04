#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// khai bao
int n, a[100][100], d, ct;
int back_v[1000]; // Đinhr tiếp theo.
struct edge
{
    int u, v, c;
};
vector <edge> Edge, kq;

bool cmp(edge a_1, edge a_2)
{
    if (a_1.c == a_2.c)
        return a_1.u < a_2.u;
    return a_1.c < a_2.c;
}

void _init_()
{
    d = 0;
    ct = 0;
    for (int i = 1; i <= n; i++)
        back_v[i] = i;
}

int check(int u) // check u to v liên thông
{
    if (back_v[u] == u) return u;
    else
    {
        return check(back_v[u]);
    }
    
}

// u-v chưa liên thông -> thêm vào cây khung
void Kruskal()
{
    sort(Edge.begin(), Edge.end(), cmp);
    _init_();  
    for (auto x: Edge)
    {
        int u = check(x.u);
        int v = check(x.v);
        if (u != v)         // check u to v liên thông
        {
            d = d + x.c;
            cout << x.u << ' '<< x.v << endl;
            back_v[u] = v;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int h;
            cin >> h;
            if (h != 0) // không có đường đi
                Edge.push_back({i, j, h});
        }
    Kruskal();
    cout << d << endl;
}

// Sắp xếp các cạnh theo trọng số nhỏ nhất.
// Từng cặp cạnh (u, v)
// +    Nếu u-v liên thông          =>> không thêm vào cặp cạnh vào cây
// +    Nếu n-v không liên thông    =>> thêm cặp cạnh vào cây
// +    tree đủ n đỉnh
// 
// Kiểm tra u-v liên thông:
// +   Khởi tạo đỉnh trước của u là chính u
// +   Nếu chọn cạnh u-v thì đỉnh trước của u là v
// +   kiểm tra trước u nếu khác đỉnh trước của v thì u-v chưa liên thông