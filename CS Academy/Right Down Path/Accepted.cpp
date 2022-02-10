/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20 ms                                           memory_used: 1136 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,mat[303][303],ans,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(long j=1;j<=m;j++)
    {
        cnt=0;
        for(long i=n;i>=1;i--)
        {
            if(mat[i][j]==0)
            {
                cnt=0;
                continue;
            }
            else
            {
                cnt+=mat[i][j];
                mat[i][j]=cnt;
            }
        }
    }
    for(long i=1;i<=n;i++)
    {
        cnt=0;
        for(long j=1;j<=m;j++)
        {
            if(mat[i][j])cnt++;
            else cnt=0;
            if(cnt==1||cnt==0||mat[i][j]==1)continue;
            ans=max(ans,cnt+mat[i][j]-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}