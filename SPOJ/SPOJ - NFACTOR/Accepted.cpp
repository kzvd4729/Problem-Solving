/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-03 13:08:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 260                                        memory_used (MB): 124.9                           
*  problem: https://vjudge.net/problem/SPOJ-NFACTOR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1000000;
long vis[1000006],fre[1000006],cnt[1000006][12],a,b,f,t,mx;
void seive(void)
{
    for(long i=2;i<=N;i++)
    {
        if(vis[i])continue;
        for(long j=i;j<=N;j+=i)
        {
            fre[j]++;
            vis[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    seive();

    for(long i=1;i<=N;i++)
    {
        for(long j=0;j<12;j++)cnt[i][j]=cnt[i-1][j];
        cnt[i][fre[i]]++;
    }
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>f;
        cout<<cnt[b][f]-cnt[a-1][f]<<endl;
    }
    return 0;
}