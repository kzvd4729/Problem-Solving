/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-11 13:44:28                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-PFDEP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ind[102],n,m,x,k,z,now;
vector<long>adj[102],ans;
priority_queue<long>zero;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--)
    {
        cin>>x>>k;
        ind[x]=k;
        while(k--)
        {
            cin>>z;
            adj[z].push_back(x);
        }
    }
    for(long i=1; i<=n; i++)
    {
        if(ind[i]==0)zero.push(-i);
    }
    while(zero.size())
    {
        now=-zero.top();
        zero.pop();
        ans.push_back(now);
        for(long i=0; i<adj[now].size(); i++)
        {
            long xx=adj[now][i];
            ind[xx]--;
            if(ind[xx]==0)zero.push(-xx);
        }
    }
    for(long i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}