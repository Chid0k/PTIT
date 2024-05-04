#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[100][100], start;
stack <int> f;
vector <int> kq;



void solve()
{
    f.push(start);
    while(f.empty() == false)
    {
        int s = f.top(), kt = 1;
        for (int i = 1; i <= n; i++)
            if (a[s][i] == 1)
            {
                f.push(i);
                a[s][i] = 0;
                a[i][s] = 0;
                kt = 0;
                break;
            }
        if (kt == 1)    // Quay lại đỉnh ban đầu => stack. <=> hết các cạnh đỉnh 1.
        {
            f.pop();
            kq.push_back(s);
        }
    }
    reverse(kq.begin(), kq.end());
    for (auto x: kq)
        cout << x << ' ';

}



int main()
{
    cin >> n >> start;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    solve();

}

//  Chu trình đơn trong đồ thị G đi qua mỗi cạnh của nó một lần được gọi là chu trình Euler. Đường đi đơn trong G đi qua mỗi cạnh của nó một lần được gọi là đường đi Euler. Đồ thị được gọi là đồ thị Euler nếu nó có chu trình Euler, và gọi là đồ thị nửa Euler nếu nó có đường đi Euler.

// [+] Ý tưởng
// Xét cạnh s-i:
// - Bỏ cạnh s-i, cho đỉnh i vào stack xét tiếp đỉnh i.
// Đi cạnh nào xóa cạnh đấy nếu đủ 

