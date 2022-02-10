/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-12 17:35:29                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 260                                        memory_used (MB): 251.9                           
*  problem: https://vjudge.net/problem/SPOJ-PSEGTREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],root[100005],sz,q,a,b,c,d;
struct segment
{
    long l,r,sum;
}seg[10000000];
void build(long node,long lo,long hi)
{
    if(lo==hi)
    {
        seg[node].sum+=arr[lo];
        return ;
    }
    long mid=(lo+hi)/2;
    if(!seg[node].l)seg[node].l=++sz;
    build(seg[node].l,lo,mid);
    if(!seg[node].r)seg[node].r=++sz;
    build(seg[node].r,mid+1,hi);
    seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
void upd(long node,long lo,long hi,long pnode,long id,long vl)
{
    if(lo==hi)
    {
        seg[node].sum+=vl+seg[pnode].sum;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)
    {
        if(!seg[node].l)seg[node].l=++sz;
        upd(seg[node].l,lo,mid,seg[pnode].l,id,vl);
        seg[node].r=seg[pnode].r;
    }
    else
    {
        if(!seg[node].r)seg[node].r=++sz;
        upd(seg[node].r,mid+1,hi,seg[pnode].r,id,vl);
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    root[0]=++sz;
    build(root[0],1,n);

    cin>>q;
    long ind=0;
    while(q--)
    {
        cin>>a>>b>>c>>d;
        if(a==1)
        {
            root[++ind]=++sz;
            upd(sz,1,n,root[b],c,d);
        }
        else
        {
            cout<<query(root[b],1,n,c,d)<<endl;
        }
    }
    return 0;
}