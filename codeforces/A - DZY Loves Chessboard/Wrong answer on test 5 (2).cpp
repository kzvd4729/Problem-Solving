/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/15/2017 02:03                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/445/problem/A
****************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,j;
    char mat[109][109];
    while(cin>>n>>m)
    {
        for(i=0;i<=103;i++)
        {
            for(j=0;j<=103;j++)
            {
                mat[i][j]='0';
            }
        }
         for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>mat[i][j];
            }
        }
         for(i=0;i<=103;i++)
        {
            for(j=0;j<=103;j++)
            {
                if(mat[i][j]!='.')mat[i][j]='-';
            }
        }
         for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(mat[i][j]=='.')
                {
                    if(mat[i][j-1]!='B'&&mat[i-1][j]!='B')
                    {
                        mat[i][j]='B';
                    }
                    else mat[i][j]='W';
                }
            }
        }
         for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
     }
    return 0;
}