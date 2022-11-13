#include<bits/stdc++.h>
using namespace std;
int goldMineJMP(int goldMine[100][100], int row, int col)
{
//// cout<<"function worked"<<endl;
////
//// cout<< col<<" "<<row;
    int DPtable[100][100], i, j;
    for(i = 0; i < row; i++) DPtable[i][0] = goldMine[i][0];
    for(j = 1; j < col; j++)
    {
        for(i = 0; i < row; i++)
        {

            if (i==0) DPtable[i][j]=goldMine[i][j]+max(DPtable[i][j-
                                        1],DPtable[i+1][j-1]);

            else
            {

                DPtable[i][j]=goldMine[i][j]+max((max(DPtable[i][j-
                                                      1],DPtable[i+1][j-1])),DPtable[i-1][j-1]);

            }
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
    int maxValue = 0;
    for (i = 0; i < row; i++)
    {
        maxValue = max(DPtable[i][col-1],maxValue);
    }
    cout<<"Maximum amount of gold-> "<<maxValue<<endl;
    cout<<"MaxGold found at ->"<<endl;
    for(i = 0; i < row; i++)
    {
        if(DPtable[i][col-1]==maxValue) cout<<"Row -> "<<i+1<<" Col ->"<<col<<endl;
    }
    return maxValue;
}
int main()

{
    int goldMine[100][100];
    int DPtable[100][100];
    int col, row, i, j;
    cout << "Enter Row - ";
    cin >> row;
    cout << "Enter Column - ";
    cin >> col;
    cout << "Enter all Gold Mine data ->\n";
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            cin >> goldMine[i][j] ;
        }
    }
    int max_cost = goldMineJMP(goldMine, row, col);
    return 0;
}
//1 3 1 5
//2 2 4 1
//5 0 2 3
//0 6 1 2
