/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2017 20:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/861/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,u,v,lft,rit,xxx,vis[202];
vector<long>adj[202],vv;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    xxx=-1;
    for(long i=1;i<=m;i++)
    {
        cin>>u>>v;
        if(u==n)xxx=v;
        adj[v].push_back(u);
    }
    if(xxx!=-1)
    {
        cout<<xxx<<endl;
        return 0;
    }
    long ans,cnt=0,z;
    for(long i=1;i<=200;i++)
    {
        lft=1;
        long f=0;
        for(long j=1;j<=200;j++)
        {
            rit=lft+i-1;
            for(long k=0;k<adj[j].size();k++)
            {
                if(adj[j][k]<lft||adj[j][k]>rit)f=1;
            }
            lft=rit+1;
        }
        if(f==0)
        {
            vv.push_back(i);
        }
    }
     for(long i=0;i<vv.size();i++)
    {
        long x=vv[i];
        if(n%x==0)z=n/x;
        else z=(n/x)+1;
        vis[z]=1;
    }
    for(long i=1;i<=200;i++)
    {
        if(vis[i]==1)
        {
            ans=i;
            cnt++;
        }
    }
    if(cnt!=1)cout<<-1<<endl;
    else cout<<ans<<endl;
     /*if(cnt!=1)cout<<-1<<endl;
    else
    {
        if(n%ans==0)cout<<n/ans<<endl;
        else cout<<(n/ans)+1<<endl;
    }*/
    return 0;
}