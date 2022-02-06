/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2018 22:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2261 ms                                         memory_used: 296900 KB                            
*  problem: https://codeforces.com/contest/588/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,q,u,v,parent[100005],level[100005],x,k;
vector<long>adj[100005],pp[100005];
vector<long>ans;
struct data
{
    long pr;
    vector<long>pe;
}sp[100005][20];
void find_level(long node,long par,long hg)
{
    parent[node]=par;
    level[node]=hg;
    for(auto x:adj[node])
    {
        if(x==par)continue;
        find_level(x,node,hg+1);
    }
}
void make_sparse(void)
{
    for(long i=1;i<=n;i++)
    {
        sp[i][0].pr=parent[i];
        sp[i][0].pe=pp[i];
    }
    for(long j=1;j<=17;j++)
    {
        for(long i=1;i<=n;i++)
        {
            sp[i][j].pe=sp[i][j-1].pe;
            long tmp=sp[i][j-1].pr;
            if(tmp==-1)sp[i][j].pr=-1;
            else
            {
                sp[i][j].pr=sp[tmp][j-1].pr;
                for(auto x:sp[tmp][j-1].pe)sp[i][j].pe.push_back(x);
                sort(sp[i][j].pe.begin(),sp[i][j].pe.end());
                while(sp[i][j].pe.size()>10)sp[i][j].pe.pop_back();
            }
        }
    }
}
void find_lca(long u,long v)
{
    ans.clear();
    if(level[u]<level[v])swap(u,v);
    for(long i=17;i>=0;i--)
    {
        if(sp[u][i].pr==-1)continue;
        if(level[sp[u][i].pr]>=level[v])
        {
            for(auto x:sp[u][i].pe)ans.push_back(x);
            sort(ans.begin(),ans.end());
            while(ans.size()>10)ans.pop_back();
            u=sp[u][i].pr;
        }
    }
    if(u==v)
    {
        for(auto x:pp[u])ans.push_back(x);
        sort(ans.begin(),ans.end());
        while(ans.size()>10)ans.pop_back();
        return ;
    }
    for(long i=17;i>=0;i--)
    {
        if(sp[u][i].pr==sp[v][i].pr)continue;
        for(auto x:sp[u][i].pe)ans.push_back(x);
        for(auto x:sp[v][i].pe)ans.push_back(x);
        sort(ans.begin(),ans.end());
        while(ans.size()>10)ans.pop_back();
        u=sp[u][i].pr;
        v=sp[v][i].pr;
    }
    for(auto x:pp[u])ans.push_back(x);
    for(auto x:pp[v])ans.push_back(x);
    for(auto x:pp[parent[u]])ans.push_back(x);
    sort(ans.begin(),ans.end());
    while(ans.size()>10)ans.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>m>>q;
     for(long i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(long i=1;i<=m;i++)
    {
        cin>>x;
        pp[x].push_back(i);
    }
//    for(long i=1;i<=n;i++)
//    {
//        for(auto x:pp[i])cout<<x<<" ";
//        cout<<endl;
//    }
    for(long i=1;i<=n;i++)
    {
        sort(pp[i].begin(),pp[i].end());
        while(pp[i].size()>10)pp[i].pop_back();
    }
    find_level(1,-1,0);
    make_sparse();
 //    for(auto x:sp[5][2].pe)cout<<x<<" ";
//    cout<<endl;
 //    for(long i=1;i<=n;i++)
//    {
//        for(long j=0;j<=5;j++)
//        {
//            cout<<sp[i][j].pe.size()<<" ";
//        }
//        cout<<endl;
//    }
//
//    for(x:sp[3][1].pe)cout<<x<<" ";
//    cout<<endl;
 //    find_lca(2,3);
//    for(auto x:ans)cout<<x<<endl;
     while(q--)
    {
        cin>>u>>v>>k;
        find_lca(u,v);
        cout<<min(k,(long)ans.size())<<" ";
        for(long i=0;i<min((long)ans.size(),k);i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}