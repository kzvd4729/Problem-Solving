/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2018 15:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/625/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,mat[505][505],cnt,ans;
int main()
{
    cin>>n>>k;
     for(long i=1;i<=n;i++)
    {
        for(long j=1;j<k;j++)
        {
            mat[i][j]=++cnt;
        }
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=k;j<=n;j++)
        {
            mat[i][j]=++cnt;
            if(j==k)ans+=mat[i][j];
        }
    }
    cout<<ans<<endl;
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}