/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/23/2018 10:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 22200 KB                             
*  problem: https://codeforces.com/contest/600/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,color[100005],cnt,st[100005],u,v,c,ed[100005],fr[100005],ans[100005],frq[100005],mx;
vector<long>adj[100005],vc;
struct data
{
    long l,r,sg,id;
} qr[100005];
bool cmp(data A,data B)
{
    if(A.sg!=B.sg)
        return A.sg<B.sg;
    else
        return A.r<B.r;
}
void dfs(long node,long par)
{
    st[node]=++cnt;
    vc.push_back(node);
    for(auto x:adj[node])
    {
        if(x==par)
            continue;
        dfs(x,node);
    }
    ed[node]=cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)cin>>color[i];
    for(long i=1; i<n; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vc.push_back(0);
    dfs(1,-1);
    long sq=sqrt(n);
    for(long i=1; i<=n; i++)
    {
        qr[i].l=st[i];
        qr[i].r=ed[i];
        qr[i].id=i;
        qr[i].sg=qr[i].l/sq;
    }
    sort(qr+1,qr+n+1,cmp);
    long pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    for(long i=pl; i<=pr; i++)
    {
        ++fr[color[vc[i]]];
        frq[fr[color[vc[i]]]]+=color[vc[i]];
        mx=max(mx,fr[color[vc[i]]]);
     }
    ans[qr[1].id]=frq[mx];
    for(int k=2; k<=n; k++)
    {
        nl=qr[k].l;
        nr=qr[k].r;
        for(int i=nl; i<pl; i++)
        {
            ++fr[color[vc[i]]];
            frq[fr[color[vc[i]]]]+=color[vc[i]];
            mx=max(mx,fr[color[vc[i]]]);
        }
        for(int i=pl; i<nl; i++)
        {
            frq[fr[color[vc[i]]]]-=color[vc[i]];
            if(mx==fr[color[vc[i]]]&&frq[fr[color[vc[i]]]]==0)mx--;
            fr[color[vc[i]]]--;
        }
        for(int i=pr+1; i<=nr; i++)
        {
            ++fr[color[vc[i]]];
            frq[fr[color[vc[i]]]]+=color[vc[i]];
            mx=max(mx,fr[color[vc[i]]]);
        }
        for(int i=nr+1; i<=pr; i++)
        {
            frq[fr[color[vc[i]]]]-=color[vc[i]];
            if(mx==fr[color[vc[i]]]&&frq[fr[color[vc[i]]]]==0)mx--;
            fr[color[vc[i]]]--;
        }
        ans[qr[k].id]=frq[mx];
        pl=nl;
        pr=nr;
    }
    for(long i=1; i<=n; i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}