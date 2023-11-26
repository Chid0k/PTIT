// sinh k chuỗi np kế tiếp 
#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000];

// Cấu hình ban đầu.
void CH(int n)
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

// Xuất cấu hình
void EXP(int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

// Sinh nhị phân
void NP(int n, int i, int cont)
{
    if (i == 0 || cont == k)
        return;
    if (a[i] == 1)
        NP(n, i - 1, cont);
    else
    {
        a[i] = 1;
        for (int j = i + 1; j <= n; j++)
            a[j] = 0;
        cout << endl;
        EXP(n);
        NP(n, n, cont + 1);
    }
}

int main()
{
    cin >> n >> k;
    CH(n);
    cout << "Start: " << endl;
    NP(n, n, 0);
}

// made by Chidok