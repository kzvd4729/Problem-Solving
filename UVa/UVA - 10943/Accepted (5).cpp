/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-23 17:02:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 260                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10943
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int dp[500][500];
long long int n,k,ans;
long long int func(long long int p,long long int v)
{
    long long int i,x;
    if(p==k)
    {
        if(v==n)return 1;
        else return 0;
    }
    if(dp[p][v]!=-1)return dp[p][v];
    x=0;
    for(i=0;i<=n;i++)
    {
        if((v+i)<=n)
        {
            x=(x+func(p+1,v+i))%1000000;
        }
    }
    p=p%1000000;

    return dp[p][v]=x;


}
int main()
{
    while(cin>>n>>k)
    {
        if(n==0&&k==0)break;
        memset(dp,-1,sizeof(dp));
        ans=func(0,0);

        cout<<ans<<endl;

    }


    return 0;
}