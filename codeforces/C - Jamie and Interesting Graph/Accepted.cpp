/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/21/2018 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 14900 KB                             
*  problem: https://codeforces.com/contest/916/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,vis[1000006],id;
vector<pair<long,long> >adj[100005];
vector<long>pr;
const long vl=10000000;
void seive(void)
{
    pr.push_back(2);
    for(long i=4; i<=1000000; i+=2)
    {
        vis[i]=1;
    }
    for(long i=3; i<=1000000; i+=2)
    {
        if(vis[i])
            continue;
        pr.push_back(i);
        vis[i]=1;
        for(long j=i*i; j<=1000000; j=j+2*i)
        {
            vis[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     seive();
     cin>>n>>m;
    long sum=0,sp;
    for(long i=1; i<n; i++)
    {
        if(i==n-1)
        {
            id=upper_bound(pr.begin(),pr.end(),sum)-pr.begin();
            adj[i].push_back({n,pr[id]-sum});
            sp=pr[id];
        }
        else
        {
            adj[i].push_back({i+1,1});
            sum++;
        }
    }
    m=m-(n-1);
    long f=0;
    for(long i=1; i<=n; i++)
    {
        for(long j=i+2; j<=n; j++)
        {
            if(m==0)
            {
                f=1;
                break;
            }
            adj[i].push_back({j,vl});
            m--;
        }
        if(f==1)
            break;
    }
    cout<<sp<<" "<<sp<<endl;
    for(long i=1;i<=n;i++)
    {
        for(auto x:adj[i])
        {
            cout<<i<<" "<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}