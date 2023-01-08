#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getMinValue(int p[], int m[][1000], int s[][1000], int i, int j)
{
    int minValue = 2147483647;

    for (int k = i; k < j; k++)
    {
        int curValue = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (curValue < minValue)
        {
            minValue = curValue;
            s[i][j] = k;
        }
    }
    return minValue;

}
void getMCM(int p[], int n, int m[][1000], int s[][1000])
{
    int d = 1;
    while (n > 0)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i + d;
            m[i][j] = getMinValue(p, m, s, i, j);
        }
        d++;
        n--;
    }

}
int main()
{
    int p[] = {4, 10, 3, 12, 20, 7};
    int n = sizeof(p)/sizeof(p[0]) - 1;
    int m[1000][1000];
    int s[1000][1000];
    getMCM(p, n, m, s);
    n = sizeof(p)/sizeof(p[0]) - 1;
    cout<<"Array: ";
    for (int i = 0; i <= n; i++)
    {
        cout<<(p[i] + ", ");
    }
    cout<<("\n\nMatrix of m: ");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Matrix of s: "<<endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            cout<<s[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}
