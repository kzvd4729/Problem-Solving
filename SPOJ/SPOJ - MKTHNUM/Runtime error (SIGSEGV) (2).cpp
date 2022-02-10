/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-13 19:15:41                      
*  solution_verdict: Runtime error (SIGSEGV)                 language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-MKTHNUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e9;
long n,m,sz,root[100005],lt,rt,k,arr[100005],ans;
struct segment
{
    long l,r,sum;
}seg[10000000];
void upd(long node,long lo,long hi,long vl,long pnode)
{
    if(lo==hi)
    {
        seg[node].sum+=seg[pnode].sum+1;
        return ;
    }
    long mid=(lo+hi)/2;
    if(vl<=mid)
    {
        if(!seg[node].l)seg[node].l=++sz;
        upd(seg[node].l,lo,mid,vl,seg[pnode].l);
        seg[node].r=seg[pnode].r;
    }
    else
    {
        if(!seg[node].r)seg[node].r=++sz;
        upd(seg[node].r,mid+1,hi,vl,seg[pnode].r);
        seg[node].l=seg[pnode].l;
    }
    seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
void query(long node,long lo,long hi,long kk,long pnode)
{
    if(lo==hi)
    {
        ans=lo;
        return ;
    }
    long mid=(lo+hi)/2;
    long x=seg[seg[node].l].sum-seg[seg[pnode].l].sum;
    ///cout<<seg[seg[node].l].sum<<" "<<seg[seg[pnode].l].sum<<endl;
    if(x>=kk)query(seg[node].l,lo,mid,kk,seg[pnode].l);
    else
    {
        kk-=x;
        query(seg[node].r,mid+1,hi,kk,seg[pnode].r);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
        root[arr[i]]=++sz;
        upd(root[arr[i]],1,N,arr[i],root[arr[i-1]]);
    }
//    for(long i=1;i<=n;i++)
//    {
//        cout<<seg[root[arr[i]]].sum<<endl;
//    }
    while(m--)
    {
        cin>>lt>>rt>>k;
        query(root[arr[rt]],1,N,k,root[arr[lt-1]]);
        cout<<ans<<endl;
    }
    return 0;
}