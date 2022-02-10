/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-29 10:26:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 384                                        memory_used (MB): 8.7                             
*  problem: https://vjudge.net/problem/LightOJ-1164
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,q,arr[100003],seg[400003],lazy[400003],chc,lt,rt,v;
void upd(long long int node,long long int lo,long long int hi,long long int l,long long int r,long long int v)
{
    if(lazy[node])
    {
        seg[node]+=(hi-lo+1)*lazy[node];
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(lo>r||hi<l)return ;
    if(lo>=l&&hi<=r)
    {
        seg[node]+=(hi-lo+1)*v;
        if(lo!=hi)
        {
            lazy[node*2]+=v;
            lazy[node*2+1]+=v;
        }
        return ;
    }
    long long int mid=(lo+hi)/2;
    upd(node*2,lo,mid,l,r,v);
    upd(node*2+1,mid+1,hi,l,r,v);
    seg[node]=seg[node*2]+seg[node*2+1];
}
long long int query(long long int node,long long int lo,long long int hi,long long int l,long long int r)
{
    if(lazy[node])
    {
        seg[node]+=(hi-lo+1)*lazy[node];
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)
    {
        return seg[node];
    }
    long long int mid=(lo+hi)/2;
    long long int p1=query(node*2,lo,mid,l,r);
    long long int p2=query(node*2+1,mid+1,hi,l,r);
    return (p1+p2);
}
int main()
{
    scanf("%lld",&t);
    long long int tc=0;
    while(t--)
    {
        memset(lazy,0,sizeof(lazy));
        memset(seg,0,sizeof(seg));
        scanf("%lld%lld",&n,&q);
        printf("Case %lld:\n",++tc);
        while(q--)
        {
            scanf("%lld",&chc);
            if(chc==0)
            {
                scanf("%lld%lld%lld",&lt,&rt,&v);
                lt++;
                rt++;
                upd(1,1,n,lt,rt,v);
            }
            else
            {
                scanf("%lld%lld",&lt,&rt);
                lt++;
                rt++;
                printf("%lld\n",query(1,1,n,lt,rt));
            }
        }
    }
    return 0;
}