/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-12 19:54:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 420                                        memory_used (MB): 80.9                            
*  problem: https://vjudge.net/problem/SPOJ-DQUERY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,sz,x,root[30004],last[1000006],q,lt,rt,tmp;
struct segment
{
    long l,r,sum;
} seg[3000000];
void upd(long node,long lo,long hi,long id,long vl,long pnode)
{
    if(lo==hi)
    {
        seg[node].sum+=seg[pnode].sum+vl;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)
    {
        if(!seg[node].l)seg[node].l=++sz;
        upd(seg[node].l,lo,mid,id,vl,seg[pnode].l);
        seg[node].r=seg[pnode].r;
    }
    else
    {
        if(!seg[node].r)seg[node].r=++sz;
        upd(seg[node].r,mid+1,hi,id,vl,seg[pnode].r);
        seg[node].l=seg[pnode].l;
    }
    seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
long query(long node,long lo,long hi,long lt,long rt)
{
    if(lo>=lt&&hi<=rt)return seg[node].sum;
    if(lo>rt||hi<lt)return 0;
    long mid=(lo+hi)/2;
    return query(seg[node].l,lo,mid,lt,rt)+query(seg[node].r,mid+1,hi,lt,rt);
}
int main()
{
    scanf("%lld",&n);
    for(long i=1; i<=n; i++)
    {
        scanf("%lld",&x);
        if(last[x])
        {
            tmp=++sz;
            upd(tmp,1,n,last[x],-1,root[i-1]);
            root[i]=++sz;
            upd(root[i],1,n,i,1,tmp);
            last[x]=i;
        }
        else
        {
            root[i]=++sz;
            upd(root[i],1,n,i,1,root[i-1]);
            last[x]=i;
        }
    }
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld%lld",&lt,&rt);
        printf("%lld\n",query(root[rt],1,n,lt,rt));
    }
    return 0;
}