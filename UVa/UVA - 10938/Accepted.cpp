/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-12 00:20:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10938
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,u,v,q,lc,lev[5005],par[5005],sp[5005][20];
vector<int>adj[5005];
void find_level(int n,int p,int h)
{
    par[n]=p;
    lev[n]=h;
    for(auto x:adj[n])
    {
        if(x!=p)
        {
            find_level(x,n,h+1);
        }
    }
}
void sparse(void)
{
    memset(sp,-1,sizeof(sp));
    for(int i=1; i<=n; i++)
    {
        sp[i][0]=par[i];
    }
    for(int j=1; j<=13; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sp[i][j-1]!=-1)sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v)
{
    if(lev[u]<lev[v])swap(u,v);
    for(int i=13; i>=0; i--)
    {
        if(lev[u]-(1<<i)>=lev[v])
        {
            u=sp[u][i];
        }
    }
    if(u==v)return u;
    for(int i=13; i>=0; i--)
    {
        if(sp[u][i]!=-1&&sp[u][i]!=sp[v][i])
        {
            u=sp[u][i];
            v=sp[v][i];
        }
    }
    return par[u];
}
int ans(int n,int d)
{
    for(int i=13; i>=0; i--)
    {
        if((1<<i)<=d)
        {
            n=sp[n][i];
            d=d-(1<<i);
        }
    }
    return n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ///ofstream cout("out.txt");
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(int i=1; i<n; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        find_level(1,-1,0);
        sparse();
        cin>>q;
        while(q--)
        {
            cin>>u>>v;
            lc=lca(u,v);

            ///cout<<endl<<lev[u]<<" "<<lev[v]<<endl<<endl;

            ///cout<<endl<<lc<<endl<<endl;
            int d1=abs(lev[u]-lev[lc]);
            int d2=abs(lev[v]-lev[lc]);
            int d=d1+d2;
            if(d%2==0)
            {
                if(d1==d2)cout<<"The fleas meet at "<<lc<<"."<<endl;
                else if(d1>d2)
                {
                    cout<<"The fleas meet at "<<ans(u,d/2)<<"."<<endl;
                }
                else cout<<"The fleas meet at "<<ans(v,d/2)<<"."<<endl;
            }
            else
            {
                if(d1>d2)
                {
                    int a1=ans(u,d/2);
                    int a2=par[ans(u,d/2)];
                    cout<<"The fleas jump forever between "<<min(a1,a2)<<" and "<<max(a1,a2)<<"."<<endl;
                }
                else
                {
                    int b1=ans(v,d/2);
                    int b2=par[ans(v,d/2)];
                    cout<<"The fleas jump forever between "<<min(b1,b2)<<" and "<<max(b1,b2)<<"."<<endl;
                }
            }
        }
    }
    return 0;
}