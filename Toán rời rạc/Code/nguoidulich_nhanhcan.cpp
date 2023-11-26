#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int c[100][100], n, Fopt = INT_MAX, Xopt[100] = {0}, vt[100] = {0}, tv[100] = {0};
int Cmin = INT_MAX;

// import dữ liệu
void IMP()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] < Cmin)
                Cmin = c[i][j];
        }
}

// Xuất dữ liệu
void EXP()
{
    for (int i = 1; i <= n; i++)
        cout << Xopt[i] << " -> ";
    cout << 1;
    cout << endl;
}

// nhánh cận
void NC(int i, int k, int s)
{
    if (k == n + 1) // xong bậc thứ n
    {
        if (Fopt > s + c[i][1])
        {
            Fopt = s + c[i][1];
            for (int i =1; i <= n + 1; i++)  
                Xopt[i] = tv[i];
        }
    }

    vt[i] = 1;
    for (int j = 1; j <= n; j++)
        if (vt[j] == 0 && i != j)
        {
            vt[j] = 1;
            tv[k] = j;
            // s + c[i][j] là gtri S bậc k
            int g = s + c[i][j] + (n - k + 1) * Cmin; // xét cận dưới cấp k
            if (g <= Fopt) // nhánh cận
            {
                NC(j, k + 1, s + c[i][j]);
                tv[k] = j;
            }
            vt[j] = 0;
        }
    vt[i] = 0;
}

int main()
{
    cin >> n;
    tv[1] = 1; // mảng truy vết vị trí.
    IMP();
    NC(1, 2, 0);
    EXP();
    cout << Fopt << ' ' ;
}


// made by Chidok