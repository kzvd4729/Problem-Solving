/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-15 22:46:52                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 328                                        memory_used (MB): 24.6                            
*  problem: https://vjudge.net/problem/LightOJ-1101
****************************************************************************************/
#include<bits/stdc++.h>
#define inf -9999999;
using namespace std;
int n,q,u,v,t,tc,m,uu,vv,ww,arr[100005],par[100005],lev[100005],sp1[100005][20],sp2[100005][20],s,e;
vector<pair<int,int> >adj[100005];
struct data
{
    int u;
    int v;
    int w;
};
vector<data>vec;
bool cmp(data A,data B)
{
    return A.w<B.w;
}
void mem(void)
{
    vec.clear();
    for(int i=0; i<=100000; i++)
    {
        arr[i]=i;
        adj[i].clear();
        par[i]=0;
        lev[i]=0;
        /*for(int j=0; j<=20; j++)
        {
            sp[i][j]=-1;
            sp2[i][j]=inf;
        }*/
    }
}
void input(void)
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&uu);
        scanf("%d",&vv);
        scanf("%d",&ww);
        vec.push_back({uu,vv,ww});
    }

}
int root(int x)
{
    while(arr[arr[x]]!=arr[x])
    {
        arr[x]=arr[arr[x]];
        x=arr[x];
    }
    return arr[x];
}
void MST(void)
{
    int x,y,z,xx,yy;
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0; i<vec.size(); i++)
    {
        x=vec[i].u;
        y=vec[i].v;
        z=vec[i].w;
        xx=root(x);
        yy=root(y);
        if(xx!=yy)
        {
            arr[xx]=yy;
            adj[x].push_back(make_pair(y,z));
            adj[y].push_back(make_pair(x,z));
        }
    }
}
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
            sp2[i][j]=INT_MIN;

        }
    }
    for(int i=1; i<=n; i++)
    {
        if(par[i]!=-1)
        {
            sp1[i][0]=par[i];
            for(int k=0;k<adj[i].size();k++)
            {
                if(adj[i][k].first==par[i])
                {
                    sp2[i][0]=adj[i][k].second;
                }
            }
        }

    }
    for(int j=1; j<=18; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sp1[i][j-1]!=-1)
            {
                sp1[i][j]=sp1[sp1[i][j-1]][j-1];
                sp2[i][j]=max(sp2[i][j-1],sp2[sp1[i][j-1]][j-1]);
            }
        }
    }
}
int lca(int u,int v)
{
    if(lev[u]<lev[v])swap(u,v);
    for(int i=18;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[v])
        {
            u=sp1[u][i];
        }
    }
    if(u==v)return u;
    for(int i=18;i>=0;i--)
    {
        if(sp1[u][i]!=-1&&sp1[u][i]!=sp1[v][i])
        {
            u=sp1[u][i];
            v=sp1[v][i];
        }
    }
    return par[u];
}
int get_max(int lc,int u)
{
    int ans=INT_MIN;
    if(lev[u]<lev[lc])swap(u,lc);
    for(int i=18;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[lc])
        {
            ans=max(ans,sp2[u][i]);
            u=sp1[u][i];
        }
    }
    return ans;
}
void que(void)
{
    scanf("%d",&q);
    int lc;
    printf("Case %d:\n",++tc);
    while(q--)
    {
        scanf("%d",&s);
        scanf("%d",&e);
        lc=lca(s,e);
        printf("%d\n",max(get_max(s,lc),get_max(e,lc)));
    }
}
int main()
{
    ///ofstream cout("ouut.txt");
    ///cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        mem();
        input();
        MST();
        /*for(int i=1;i<=4;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j].first<<" "<<adj[i][j].second<<"      ";
            }
            cout<<endl;
        }*/
        find_level(1,-1,0);
        sparse();
        /*for(int i=0;i<5;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<sp2[i][j]<<" ";
            }
            cout<<endl;
        }*/
        que();

    }
    return 0;
}