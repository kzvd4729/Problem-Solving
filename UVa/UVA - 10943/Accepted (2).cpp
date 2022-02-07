/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-24 21:12:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10943
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int dp[109][109];
long long int n,k,q;
long long int f(long long int vl,long long int rm)
{
    long long int x,i;
    if(rm==0)
    {
        if(vl==0)return 1;
        else return 0;
    }
    if(dp[vl][rm]!=-1)return dp[vl][rm];
    x=0;
    for(i=0;i<=n;i++)
    {
        if((vl-i)>=0)
        {
            x=(x+f(vl-i,rm-1))%1000000;
        }
    }
    x=x%1000000;

    dp[vl][rm]=x;

    return x;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>n>>k)
    {
        if(n==0&&k==0)break;
        q=f(n,k);
        cout<<q<<endl;

    }

    return 0;
}