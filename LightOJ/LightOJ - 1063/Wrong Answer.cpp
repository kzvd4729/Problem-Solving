/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-28 15:27:01                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1063
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int MAXX=100007;
int t,tc,tim,n,m,u,v,vis[MAXX],disc[MAXX],parent[MAXX],ans,low[MAXX];
bool AP[MAXX];
vector<int>adj[MAXX];
void ini()
{
    int i;
    for(i =0; i<MAXX; i++)
    {
        vis[i]=AP[i]=false; // Initializing AP and vis array as false
        parent[i]=-1;         // Initializing parent of each vertex to -1
        adj[i].clear();        // clearing the adjacency list.
        low[i]=0;
    }
    tim=0;                    // initializing tim to 0
}

void dfs(int u)
{
    vis[u]=true;
    int  i;
    low[u]=disc[u]=(++tim);
    int child=0;
    for(i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(vis[v]==false)
        {
            child++;
            parent[v]=u;
            dfs(v);

            low[u]=min(low[u],low[v]);
            if( (parent[u]!=-1&&low[v]>=disc[u] ) )
                AP[u]=true;
            if( (parent[u]==-1&&child>1))
                AP[u]=true;
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],disc[v]);
        }
    }
}
int main()
{
    ///ofstream cout("out.txt");
    scanf("%ld",&t);
    while(t--)
    {
        ini();
        scanf("%ld%ld",&n,&m);
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%ld%ld",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tim=0,ans=0;
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
        for(int i=1;i<=n;i++)if(AP[i])ans++;
        ///printf("Case %ld: %ld\n",++tc,ans);
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}