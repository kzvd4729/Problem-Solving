/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2018 16:21                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 239000 KB                            
*  problem: https://codeforces.com/contest/934/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],last[100005],root[100005],sz,tmp,x;
struct segment
{
    long l,r,sum;
} seg[10000000];
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
     for(long i=n; i>=1; i--)
    {
        x=arr[i];
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
    for(long i=1;i<=n;i++)
    {
            }
    return 0;
}