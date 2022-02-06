/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2017 19:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/629/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char mat[102][102];
int n,i,j,k,ans;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>mat[i][j];
        }
    }
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(mat[i][j]=='C')
            {
                for(k=j+1;k<=n;k++)
                {
                    if(mat[i][k]=='C')ans++;
                }
                for(k=i+1;k<=n;k++)
                {
                    if(mat[k][j]=='C')ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
      return 0;
}