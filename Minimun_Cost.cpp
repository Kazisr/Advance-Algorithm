#include<bits/stdc++.h>
using namespace std;
int minCostPath(int gridCost[100][100], int row, int col)
{
//// cout<<"function worked"<<endl;
////
//// cout<< col<<" "<<row;
    int DPtable[100][100], i, j;
    DPtable[0][0] = gridCost[0][0];
    for(i = 1; i < col; i++) DPtable[0][i] = gridCost[0][i]+DPtable[0][i-1];
    for(i = 1; i < row; i++) DPtable[i][0] = gridCost[i][0]+DPtable[i-1][0];
    for(i = 1; i < row; i++)
    {
        for(j = 1; j < col; j++)
        {

            DPtable[i][j]=gridCost[i][j]+min(DPtable[i-1][j],DPtable[i][j-
                                             1]);

        }
    }
    cout<<endl<<endl;
    for( i = 0; i < row; i++)
    {
        for( j = 0; j < col; j++)
        {
            cout<<DPtable[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return DPtable[row-1][col-1];
}
int main()
{
    int gridCost[100][100];
    int DPtable[100][100];
    int col, row, i, j;
    cout << "Enter Row - ";
    cin >> row;
    cout << "Enter Column - ";
    cin >> col;
    cout << "Enter all grid data ->\n";
    for(i = 0; i < row; i++)
    {

        for(j = 0; j < col; j++)
        {
            cin >> gridCost[i][j] ;
        }
    }
    int min_cost = minCostPath(gridCost, row, col);
    cout<<"Minimum cost -> "<<min_cost;
    return 0;
}
//
//3 5 7 10
//6 4 3 9
//6 5 4 5
