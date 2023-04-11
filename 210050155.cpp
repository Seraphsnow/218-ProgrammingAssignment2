#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define fi first
#define se second

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            cin >> arr[i][j];
        }
    }
    pair<int, int> besta[n][m + 1], bestb[n][m];
    for (int i = 0; i < n; i++)
    {
        besta[i][0] = {0, 0};
        bestb[i][0] = {0, 0};
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int maxb = 0, maxa = 0;
            int diff = INT_MIN;

            for (int k = 0; k < n; k++)
            {
                if (k != j)
                {
                    if (arr[j][k] + besta[k][i - 1].se - besta[k][i - 1].fi > diff)
                    {
                        maxb = arr[j][k] + besta[k][i - 1].se;
                        maxa = besta[k][i - 1].fi;
                        diff = arr[j][k] + besta[k][i - 1].se - besta[k][i - 1].fi;
                    }
                }
            }
            bestb[j][i].fi = maxb;
            bestb[j][i].se = maxa;
        }
        for (int j = 0; j < n; j++)
        {
            int maxb = 0, maxa = 0;
            int diff = INT_MIN;
            for (int k = 0; k < n; k++)
            {
                if (k != j)
                {
                    if (arr[j][k] + bestb[k][i].se - bestb[k][i].fi > diff)
                    {
                        maxa = arr[j][k] + bestb[k][i].se;
                        maxb = bestb[k][i].fi;
                        diff = arr[j][k] + bestb[k][i].se - bestb[k][i].fi;
                    }
                }
            }
            besta[j][i].fi = maxa;
            besta[j][i].se = maxb;
        }
    }

    if (besta[0][m].fi > besta[0][m].se)
    {

        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
}