/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2018 17:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2500 KB                              
*  problem: https://codeforces.com/contest/939/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,vis1[30],vis2[30];
string s,x;
vector<pair<char,char> >v;
vector<long>adj[3000];
void dfs1(long node)
{
    vis1[node]=1;
    for(auto x:adj[node])
    {
        if(vis1[x])continue;
        dfs1(x);
    }
}
void dfs2(long node)
{
    vis2[node]=1;
    for(auto x:adj[node])
    {
        if(vis2[x])continue;
        dfs2(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    cin>>s>>x;
     for(long i=0;i<n;i++)
    {
        if(s[i]==x[i])continue;
        memset(vis1,0,sizeof(vis1));
        dfs1(s[i]-'a');
        memset(vis2,0,sizeof(vis2));
        dfs2(x[i]-'a');
        long f=0;
        for(long i=0;i<27;i++)
        {
            if(vis1[i]&&vis2[i])
            {
                f=1;
                break;
            }
        }
        if(f)continue;
        v.push_back({s[i],x[i]});
        adj[s[i]-'a'].push_back(x[i]-'a');
        adj[x[i]-'a'].push_back(s[i]-'a');
    }
    cout<<v.size()<<endl;
    for(long i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}