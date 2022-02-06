/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2018 18:14                        
*  solution_verdict: Compilation error                       language: GNU C++                                 
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/375/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,q,color[100005],cnt,st[100005],u,v,c,ed[100005],vj,kj,fr[100005],ans[100005],frq[100005];
vector<long>adj[100005],vc;
struct data
{
    long l,r,sg,id,kk;
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
     cin>>n>>q;
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
    for(long i=1; i<=q; i++)
    {
        cin>>vj>>kj;
        qr[i].l=st[vj];
        qr[i].r=ed[vj];
        qr[i].id=i;
        qr[i].sg=qr[i].l/sq;
        qr[i].kk=kj;
    }
    sort(qr+1,qr+q+1,cmp);
     long pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    for(long i=pl; i<=pr; i++)
    {
        kj=qr[1].kk;
        frq[++fr[color[vc[i]]]]++;
    }
    ans[qr[1].id]=frq[kj];
    for(int k=2; k<=q; k++)
    {
        nl=qr[k].l;
        nr=qr[k].r;
        kj=qr[k].kk;
        for(int i=nl; i<pl; i++)frq[++fr[color[vc[i]]]]++;
        for(int i=pl; i<nl; i++)frq[fr[color[vc[i]]]--]--;
        for(int i=pr+1; i<=nr; i++)frq[++fr[color[vc[i]]]]++;
        for(int i=nr+1; i<=pr; i++)frq[fr[color[vc[i]]]--]--;
        ans[qr[k].id]=frq[kj];
        pl=nl;
        pr=nr;
    }
    for(long i=1;i<=q;i++)cout<<ans[i]<<endl;
    return 0;
}