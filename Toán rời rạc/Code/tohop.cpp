// sinh 'cont' tổ hợp chập k của n
#include <bits/stdc++.h>
using namespace std;

int a[1000], n, k, cont, ed[1000];

// Cấu hình ban đầu.
void CH(int n, int k)
{
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        ed[i] = n - k + i; // cấu hình kêt thúc
    }
}

// Xuất cấu hình
void EXP(int k)
{
    for (int i = 1; i <= k; i++)
        cout << a[i] << ' ';
    cout << endl;
}

// Tổ hợp 
void TH(int n, int k, int i, int loop)
{
    if (i == 0 || loop == cont)
        return;
    if (a[i] >= ed[i]) 
        TH(n, k, i - 1, loop);
    else
    {
        a[i] = a[i] + 1;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[i] + j - i;
        cout << endl;
        EXP(k);
        TH(n, k , n, loop + 1);
    }
}

int main()
{
    cin >> n >> k >> cont;
    CH(n, k);
    TH(n, k ,n, 0);
}

// made by Chidok