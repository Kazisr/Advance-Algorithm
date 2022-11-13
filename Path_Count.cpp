#include<bits/stdc++.h>
using namespace std;
int path_count(int col, int row)
{
//// cout<<"function worked"<<endl;
//// cout<< col<<" "<<row;
    int table[100][100], i, j;
    for(i = 0; i < col; i++) table[0][i] = 1;
    for(i = 0; i < row; i++) table[i][0] = 1;
    for(i = 1; i < row; i++)
    {
        for(j = 1; j < col; j++)
        {
            table[i][j] = table[i-1][j]+table[i][j-1];
//cout<<table[i][j]<<" ";
        }
    }
    return table[row-1][col-1];

}

// Driver Code
int main()
{
    int col, row;
    cout << "Enter Row - ";
    cin >> row;
    cout << "Enter Column - ";
    cin >> col;
    cout << endl;
    int total_paths = path_count(col, row);
    cout<<"Total path possible to ( "<<row<<","<<col<<" ) is -> "<<
        total_paths<<endl;
    return 0;
}
