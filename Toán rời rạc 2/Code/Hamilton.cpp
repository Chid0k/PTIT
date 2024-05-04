

#include <iostream>
#include <stack>

using namespace std;

int n, a[100][100], kq[100], check[100] = {0}, start;

void solve(int k)
{
    for (int i = 1; i <= n; i++)
        if (a[kq[k - 1]][i] == 1) // nếu có cạnh nối từ đỉnh trước đến đỉnh i
        {
            kq[k] = i; // thêm đỉnh đó vào kq tiếp theo.
            if ((k == (n + 1)) && (kq[k] == start))
            {
                for (int i = 1; i <= n + 1; i++)
                    cout << kq[i] << ' ';
                cout << endl;
            }
            else if (check[i] == 0)
            {
                check[i] = 1;
                kq[k] = i;
                solve(k + 1);   // đệ quy hàm sinh
                check[i] = 0;
            }
        }
}

int main()
{
    cin >> n >> start;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    a[0][1] = 1;
    solve(1);
}

// Đường đi qua tất cả các đỉnh của đồ thị mỗi đỉnh đúng một lần được gọi là đường đi Hamilton

// [+] Ý tưởng:
// Đệ quy quay lui tìm tất cả các chu trình Hamilton có thể.
// Mảng KQ lưu chu trình Hamilton - len(KQ) = n.
