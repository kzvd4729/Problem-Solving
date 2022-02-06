/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2017 23:26                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/844/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long n,m,one,zero,ans,mat[100][100];
int NCR(int n, int r)
{
    if (r > n/2)return NCR(n, n-r);
    long out = 1;
    for(int k = 1; k <= r; ++k)
    {
        out *= n-k+1;
        out /= k;
    }
    return out;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long i=1; i<=n; i++)
    {
        for(long j=1; j<=m; j++)
        {
            cin>>mat[i][j];
        }
    }
    ans=0;
    for(long i=1; i<=n; i++)
    {
        one=0;
        zero=0;
        for(long j=1; j<=m; j++)
        {
            if(mat[i][j]==1)one++;
            else zero++;
         }
        for(long k=2; k<=one; k++)
        {
            ans+=NCR(one,k);
        }
        for(long k=2; k<=zero; k++)
        {
            ans+=NCR(zero,k);
        }
    }
    //cout<<ans<<endl;
    ///ans=0;
    for(long i=1; i<=m; i++)
    {
        one=0;
        zero=0;
        for(long j=1; j<=n; j++)
        {
            if(mat[j][i]==1)one++;
            else zero++;
         }
        for(long k=2; k<=one; k++)
        {
            ans+=NCR(one,k);
        }
        for(long k=2; k<=zero; k++)
        {
            ans+=NCR(zero,k);
        }
    }
    ///cout<<ans<<endl;
    cout<<ans+(n*m)<<endl;
      return 0;
}