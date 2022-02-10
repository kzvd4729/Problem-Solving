/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-12 12:09:14                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-MKTHNUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1000000000;
long n,x,sz,q,root[100005],ans,lt,rt,k;
struct segment
{
    long l,r,sum;
}seg[10000000];
void upd(long node,long lo,long hi,long id,long pnode)
{
    if(lo==hi)
    {
        seg[node].sum++;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)
    {
        if(!seg[node].l)seg[node].l=++sz;
        upd(seg[node].l,lo,mid,id,seg[pnode].l);
        seg[node].r=seg[pnode].r;
    }
    else
    {
        if(!seg[node].r)seg[node].r=++sz;
        upd(seg[node].r,mid+1,hi,id,seg[pnode].r);
        seg[node].l=seg[pnode].l;
    }
    seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
void query(long node,long lo,long hi,long kk)
{
    ///cout<<lo<<" "<<hi<<endl;
    ///cout<<seg[node].sum<<endl;
    if(lo>hi)
    {
        ans=lo;
        return ;
    }
    long mid=(lo+hi)/2;
    if(seg[seg[node].l].sum>=kk)query(seg[node].l,lo,mid,kk);
    else query(seg[node].r,mid+1,hi,kk);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        root[i]=++sz;
        upd(root[i],1,N,x,root[i-1]);
    }
    while(q--)
    {
        cin>>lt>>rt>>k;
        query(root[rt],1,N,k);
        cout<<ans<<endl;
    }
    return 0;
}