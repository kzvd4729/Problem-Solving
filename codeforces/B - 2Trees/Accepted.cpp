/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/19/2017 02:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 13300 KB                             
*  problem: https://codeforces.com/gym/101257/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>adj[300005],c1[3],c2[3];
long n,u,v;
void color(int n,int p,int h)
{
    if(adj[n].size()==1)
    {
        c1[h%2].push_back(n);
    }
    for(int i=0;i<adj[n].size();i++)
    {
        if(adj[n][i]==p)continue;
        color(adj[n][i],n,h+1);
    }
}
void _color(int n,int p,int h)
{
    if(adj[n].size()==1)
    {
        c2[h%2].push_back(n);
    }
    for(int i=0;i<adj[n].size();i++)
    {
        if(adj[n][i]==p)continue;
        _color(adj[n][i],n,h+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color(1,-1,0);
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
    }
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    _color(1,-1,0);
     if(c1[0].size()==c2[0].size())
    {
        cout<<2<<endl;
        for(int i=0;i<c1[0].size();i++)
        {
            cout<<c1[0][i]<<" "<<c2[0][i]<<endl;
        }
        for(int i=0;i<c1[1].size();i++)
        {
            cout<<c1[1][i]<<" "<<c2[1][i]<<endl;
        }
    }
    else if(c1[0].size()==c2[1].size())
    {
        cout<<2<<endl;
        for(int i=0;i<c1[0].size();i++)
        {
            cout<<c1[0][i]<<" "<<c2[1][i]<<endl;
        }
        for(int i=0;i<c1[1].size();i++)
        {
            cout<<c1[1][i]<<" "<<c2[0][i]<<endl;
        }
    }
    else
    {
        cout<<3<<endl;
        vector<long>v1,v2;
        for(int i=0;i<c1[0].size();i++)
        {
            v1.push_back(c1[0][i]);
        }
        for(int i=0;i<c1[1].size();i++)
        {
            v1.push_back(c1[1][i]);
        }
        for(int i=0;i<c2[0].size();i++)
        {
            v2.push_back(c2[0][i]);
        }
        for(int i=0;i<c2[1].size();i++)
        {
            v2.push_back(c2[1][i]);
        }
        for(int i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<" "<<v2[i]<<endl;
        }
    }
     return 0;
}