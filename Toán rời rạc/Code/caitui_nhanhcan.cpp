#include <stdio.h>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

int Xopt[100] = {0} , danhdau[100] = {0};

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

void truyvet(int n)
{
    for (int i = 0; i < n ; i ++)
        cout << Xopt[i] << ' ' ;
}
int maxx = INT_MIN;

int solve(int k, int g[], int f[], int n, int i, int b, int S, int vt) 
{
    if (vt == 1)
        danhdau[i - 1] = 1;
    else 
        danhdau[i - 1] = 0;
    // Trường hợp cơ bản: khi đến cuối danh sách đối tượng hoặc đã đạt đến trọng lượng tối đa
    if (i == n || b == k) 
    {
        if (S > maxx && b <= k)
        {
            maxx = S;
            for (int i = 0; i < n ; i++)
                Xopt[i] = danhdau[i];
        }
        return S;
    }

    // Nếu trọng lượng của đối tượng hiện tại vượt quá trọng lượng còn lại trong túi
    if (g[i] + b > k) 
    {
        return solve(k, g, f, n, i + 1, b, S, 0);
    }

    // Trường hợp nhánh cận
    int pick = solve(k, g, f, n, i + 1, b + g[i], S + f[i], 1);
    int unpick = solve(k, g, f, n, i + 1, b, S, 0);
    return max(pick, unpick);
}

int main() 
{
    int g[1000]; // khối lượng max
    int f[1000]; // giá trị max
    int n, k;
    cin >> n >> k;
    for (int i =0 ; i < n; i++)
        cin >> g[i];
    for (int i =0 ; i < n; i++)
        cin >> f[i];

    int Fopt = solve(k, g, f, n, 0, 0, 0, 0);

    printf("%d\n", Fopt);
    truyvet(n);
    return 0;
}

// made by Chidok