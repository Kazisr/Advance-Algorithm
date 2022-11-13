#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void computeLPSArray(char* pat, int M, int* lps)
{
    int i = 0, j = 1;
    lps[0] = 0;
    while(i<M && j<M)
    {
        if(pat[i]==pat[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i==0)
            {
                lps[j]=0;
                j++;
            }
            else
            {
                i = lps[i-1];
            }
        }
    }
}
void KMPSearch(char* pat, char* txt, int M, int N)
{
    int lps[M];
    computeLPSArray(pat, M, lps);
    cout<<"LPS table of "<<pat<<" is: ";
    for (size_t i = 0; i < M; i++)
    {
        std::cout << lps[i] << ' ';
    }
    cout<<endl;
    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            cout<<"Found pattern at index "<<i-j<<endl;
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j < 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    char txt[100], pat[50];
    cout<<"Enter the text: ";
    cin.getline(txt,100);
    cout<<"Enter the pattern: ";
    cin.getline(pat,50);
    int M = strlen(pat);
    int N = strlen(txt);
    cout<<"Length of the text: "<<N<<endl;
    cout<<"Length of the pat: "<<M<<endl;
    cout<<endl;
    KMPSearch(pat, txt, M, N);
    return 0;
}
//AAAABA ABA ABABABABAAABA ABA
