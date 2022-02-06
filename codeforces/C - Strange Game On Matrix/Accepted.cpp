/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/12/2017 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/873/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,mat[102][102],cnt,ans,anz,sz,now,mxs,mxz;
long _count(long row,long col)
{
    long sum=0;
    for(long i=row;i<=min(n,row+k-1);i++)
    {
        sum+=mat[i][col];
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m>>k;
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(long j=1;j<=m;j++)
    {
        cnt=0,now=0,mxz=0,mxs=0;
        for(long i=1;i<=n;i++)
        {
            if(mat[i][j]==0)continue;
            now=_count(i,j);
            if(now>mxs)
            {
                mxs=now;
                mxz=cnt;
            }
            cnt+=mat[i][j];
        }
        ans+=mxs;
        anz+=mxz;
    }
    cout<<ans<<" "<<anz<<endl;
     return 0;
}