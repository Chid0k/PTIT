// Sinh k hoán vị từ cấu hình xuất phát
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int a[1000] = {}, n, k;

// Cấu hình ban đầu.
void CH(int n)
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = INT_MIN;
}

// Xuất cấu hình
void EXP(int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

// Kiểm tra với cấu hình cuối cùng
int check(int n)
{
    for (int i = n; i >= 1; i--)
        if (i == a[n - i + 1])
            continue;
        else
            return 0;
    return 1;
}

// Hàm lật ngược
void mirror(int a[], int n, int l, int r)
{
    while (l < r)
    {
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        l++;
        r--;
    }
}

// Hàm sinh hoán vị
void HV(int n, int i, int h)
{
    if (i == 1 || check(n) || h == k)
        return;
    if (a[i - 1] > a[i])
        HV(n, i - 1, h);
    else
    {
        int min = 10, k;
        for ( int j = i ; j <= n; j++ )
            if ( a[j] > a[i - 1] )
                if (a[j] < min)
                {
                    min = a[j];
                    k = j;
                }
        // // Nếu trình bày vào vở thì in 2 dòng sau 
        // cout << "i = " << i - 1 << "; " << "k = " << k << endl;
        // cout << "->: ";
        swap(a[k] , a[i - 1]);
        mirror(a, n, i, n);
        EXP(n);
        cout << endl;
        HV(n , n, h + 1);
    }
}

int main()
{
    cin >> n >> k;
    CH(n);
    cout << endl;
    HV(n, n, 0);
}


// made by Chidok 