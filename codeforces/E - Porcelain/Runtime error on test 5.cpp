/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2018 00:42                        
*  solution_verdict: Runtime error on test 5                 language: GNU C++14                               
*  run_time: 390 ms                                          memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/148/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,x,z,dp[102][1002],lft[102],rgt[102],mxx;
vector<long>v[102],mx[102];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        for(long j=1;j<=x;j++)
        {
            cin>>z;
            v[i].push_back(z);
        }
        memset(lft,0,sizeof(lft));
        memset(rgt,0,sizeof(rgt));
        for(long j=1;j<=x;j++)lft[j]=lft[j-1]+v[i][j-1];
        for(long j=x;j>=1;j--)rgt[x-j+1]=rgt[x-j]+v[i][j-1];
//        for(long i=1;i<=x;i++)cout<<lft[i]<<" ";
//        cout<<endl;
        for(long j=1;j<=x;j++)
        {
            mxx=0;
            for(long k=0;k<=j;k++)
            {
                mxx=max(mxx,lft[k]+rgt[j-k]);
                mxx=max(mxx,rgt[k]+lft[j-k]);
            }
            mx[i].push_back(mxx);
        }
//        for(auto x:mx[i])cout<<x<<" ";
//        cout<<endl;
    }
     for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=mx[i].size();j++)
        {
            for(long k=1;k<=m;k++)dp[i][k]=max(dp[i][k],dp[i-1][k]);
            for(long k=1;k<=m;k++)
            {
                if(k-j>=0)dp[i][k]=max(dp[i][k],dp[i-1][k-j]+mx[i][j-1]);
                ///cout<<i<<" "<<k<<" "<<dp[i][k]<<endl;
            }
            //cout<<endl;
        }
//        for(long j=1;j<=m;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
    }
    cout<<dp[n][m]<<endl;
     return 0;
}