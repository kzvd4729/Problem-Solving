/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-11 21:02:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 860                                        memory_used (MB): 35.4                            
*  problem: https://vjudge.net/problem/LightOJ-1162
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,q,u,v,w,lev[100005],par[100005],sp1[100005][18],sp2[100005][18],sp3[100005][18];
vector<pair<int,int> >adj[100005];
void find_level(int n,int p,int h)
{
    par[n]=p;
    lev[n]=h;
    for(int i=0; i<adj[n].size(); i++)
    {
        if(adj[n][i].first!=p)
        {
            find_level(adj[n][i].first,n,h+1);
        }
    }
}
void sparse(void)
{
    for(int i=0; i<100005; i++)
    {
        for(int j=0; j<18; j++)
        {
            sp1[i][j]=-1;
            sp2[i][j]=INT_MAX;
            sp3[i][j]=INT_MIN;

        }
    }
    for(int i=1; i<=n; i++)
    {
        if(par[i]!=-1)
        {
            sp1[i][0]=par[i];
            ///cout<<sp1[i][0]<<endl;
            for(int k=0;k<adj[i].size();k++)
            {
                if(adj[i][k].first==par[i])
                {
                    sp2[i][0]=adj[i][k].second;
                    sp3[i][0]=adj[i][k].second;
                    ///cout<<i<<" "<<par[i]<<" "<<sp2[i][0]<<endl;
                }
            }

        }

    }
    for(int j=1; j<=17; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sp1[i][j-1]!=-1)
            {
                sp1[i][j]=sp1[sp1[i][j-1]][j-1];
                sp2[i][j]=min(sp2[i][j-1],sp2[sp1[i][j-1]][j-1]);
                sp3[i][j]=max(sp3[i][j-1],sp3[sp1[i][j-1]][j-1]);
            }
        }
    }
}
int lca(int u,int v)
{
    if(lev[u]<lev[v])swap(u,v);
    for(int i=17;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[v])
        {
            u=sp1[u][i];
        }
    }
    if(u==v)return u;
    for(int i=17;i>=0;i--)
    {
        if(sp1[u][i]!=-1&&sp1[u][i]!=sp1[v][i])
        {
            u=sp1[u][i];
            v=sp1[v][i];
        }
    }
    return par[u];
}
int get_min(int lc,int u)
{
    int ans=INT_MAX;
    if(lev[u]<lev[lc])swap(u,lc);
    for(int i=17;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[lc])
        {
            ans=min(ans,sp2[u][i]);
            u=sp1[u][i];
        }
    }
    return ans;
}
int get_max(int lc,int u)
{
    int ans=INT_MIN;
    if(lev[u]<lev[lc])swap(u,lc);
    for(int i=17;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[lc])
        {
            ans=max(ans,sp3[u][i]);
            u=sp1[u][i];
        }
    }
    return ans;
}
int main()
{
    ///ofstream cout("ot.txt");
    int tc=0;
    ///cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        ///cin>>n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(int i=1; i<n; i++)
        {
            ///cin>>u>>v>>w;
            scanf("%d",&u);
            scanf("%d",&v);
            scanf("%d",&w);
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        find_level(1,-1,0);
        sparse();



        /*for(int i=1;i<=6;i++)
        {
            for(int j=0;j<6;j++)
            {
                cout<<sp2[i][j]<<" ";
            }
            cout<<endl;
        }*/

        ///cin>>q;
        scanf("%d",&q);
        ///cout<<"Case "<<++tc<<":"<<endl;
        printf("Case %d:\n",++tc);
        while(q--)
        {
            ///cin>>u>>v;
            scanf("%d",&u);
            scanf("%d",&v);
            int lc=lca(u,v);
            printf("%d %d\n",min(get_min(lc,u),get_min(lc,v)),max(get_max(lc,u),get_max(lc,v)));
            ///cout<<min(get_min(lc,u),get_min(lc,v))<<" "<<max(get_max(lc,u),get_max(lc,v))<<endl;
        }
    }
    return 0;
}