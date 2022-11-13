#include<bits/stdc++.h>
using namespace std;
void subset_sum(int arr[], int coin, int col)
{
    int i, j, sum = 0;
    bool x, y;
    bool table[coin][col + 1];
    table[0][0] = true;
    for (i = 1; i < col+1; i++)
        table[0][i] = false;
    for (i=1; i< coin+1; i++)
    {
        sum += arr[i-1];
        for (j=0; j< col+1; j++)
        {
            x = table[i-1][j];
            if(arr[i-1] > j || sum < j) y = false;
            else
            {
                int temp = j - arr[i-1];
                y = table[i-1][temp];
            }
            if(x||y == true) table[i][j] = true;
            else
            {
                table[i][j] = false;
            }
//cout<<x<<"+"<<y<<" ";
        }
//cout<<endl;
    }
// cout<<endl;
// cout<<endl;
// cout<<endl;
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
            if(table[i][j]== true)cout<<"T ";
            else cout<<"F ";

        }
        cout<<endl;
    }
}

// Driver Code
int main()
{
    int arr[] = {1, 3, 4, 7, 10};
    int coin = sizeof(arr)/sizeof(arr[0]);
    int col = 9;
    subset_sum(arr, coin, col);
    return 0;
}
