/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2019 00:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 30700 KB                             
*  problem: https://codeforces.com/contest/1131/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int rt[N+2],sz[N+2];
vector<int>vv[N+2];
int _find(int x)
{
    if(x==rt[x])return x;
    return rt[x]=_find(rt[x]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        rt[i]=i;sz[i]=1;
        vv[i].push_back(i);
    }
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        int r1=_find(u),r2=_find(v);
        if(r1==r2)continue;
        if(sz[r1]>=sz[r2])
        {
            rt[r2]=r1;sz[r1]+=sz[r2];
            for(auto x:vv[r2])
                vv[r1].push_back(x);
        }
        else
        {
            rt[r1]=r2;sz[r2]+=sz[r1];
            for(auto x:vv[r1])
                vv[r2].push_back(x);
        }
    }
    int r=_find(1);
    for(auto x:vv[r])cout<<x<<" ";
    cout<<endl;
    return 0;
}