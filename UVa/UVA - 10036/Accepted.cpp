/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-10 20:32:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 250                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10036
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,k,arr[10005],dp[10005][109],i;
long long int fx(long long int s,long long int v)
{
    if(s==n)
    {
        if(v%k==0)return 1;
        else return 0;
    }
    if(dp[s][(abs(v))%k]!=-1)return dp[s][(abs(v))%k];
    dp[s][(abs(v))%k]=fx(s+1,(v+arr[s])%k)|fx(s+1,(v-arr[s])%k);
    return dp[s][(abs(v))%k];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        if(fx(1,arr[0])==1)cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;

    }
    return 0;
}