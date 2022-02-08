/****************************************************************************************
*  @author: kzvd4729                                         created: 06-09-2017 19:52:34                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.24 sec                                        memory_used: 50.7M                                
*  problem: https://www.codechef.com/SEPT17/problems/FILLMTR
****************************************************************************************/
#include<bits/stdc++.h>
#define N 1000005
using namespace std;
vector<pair<int,int> >adj[N];
int vis[N],hei[N],f,t,n,q,u,v,w;
void mem(void)
{
    for(int i=1;i<=n;i++)
    {
        hei[i]=0;
        vis[i]=0;
        adj[i].clear();
    }
}
void dfs(int root,int h)
{
    hei[root]=h;
    vis[root]=1;
    for(int i=0;i<adj[root].size();i++)
    {
        int x=adj[root][i].first;
        int c=adj[root][i].second;
        if(vis[x]==1)
        {
            if(abs(hei[root]-hei[x])%2!=c)f=1;
        }
        else dfs(x,h+c);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        mem();
        while(q--)
        {
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        f=0;
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==0||vis[i]==1)continue;
            dfs(i,0);
        }
        if(f==1)printf("no\n");
        else printf("yes\n");
    }
    return 0;
}