/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 01:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 154500 KB                            
*  problem: https://codeforces.com/contest/813/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,sz,x,root[100005],q,lt,rt,tmp,k,last;
queue<long>que[100005];
struct segment
{
    long l,r,sum;
} seg[40*100000];
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
    scanf("%lld%lld",&n,&k);
    for(long i=1; i<=n; i++)
    {
        scanf("%lld",&x);
        que[x].push(i);
        if((que[x].size())>k)
        {
             tmp=++sz;
            upd(tmp,1,n,que[x].front(),-1,root[i-1]);
            que[x].pop();
            root[i]=++sz;
            upd(root[i],1,n,i,1,tmp);
        }
        else
        {
            root[i]=++sz;
            upd(root[i],1,n,i,1,root[i-1]);
        }
    }
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld%lld",&lt,&rt);
        lt=(lt+last)%n+1;
        rt=(rt+last)%n+1;
        if(lt>rt)swap(lt,rt);
        last=query(root[rt],1,n,lt,rt);
        printf("%lld\n",last);
    }
    return 0;
}