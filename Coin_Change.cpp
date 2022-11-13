#include<bits/stdc++.h>
using namespace std;
void coin_change(int arr[], int coin, int col)
{
    int i, j, x, y;
    int table[coin][col + 1];
    table[0][0] = 1;
    for (i = 1; i < col+1; i++)
        table[0][i] = 0;
    for (i=1; i< coin+1; i++)
    {
        for (j=0; j< col+1; j++)
        {
            x = table[i-1][j];
            if(arr[i-1] > j) y = 0;
            else
            {
                int temp = j - arr[i-1];
                y = table[i][temp];
            }
            table[i][j] = x + y;
            cout<<x<<"+"<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

///print
    cout<<" ";
    for (i=0; i< col+1; i++) cout<<" "<<i;
    cout<<endl;
    for (i=0; i< coin+1; i++)
    {
        if (i==0) cout<<"0 ";
        else cout<<arr[i-1]<<" ";
        for (j=0; j< col+1; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 5};
    int coin = sizeof(arr)/sizeof(arr[0]);
    int col = 7;

    int i, j;
    coin_change(arr, coin, col);
    return 0;
}
