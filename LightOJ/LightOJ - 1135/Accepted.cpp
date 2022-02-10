/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-01 22:01:25                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 440                                        memory_used (MB): 20.4                            
*  problem: https://vjudge.net/problem/LightOJ-1135
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,lazy[600005],q;
struct segment
{
    long long int zeros;
    long long int ones;
    long long int twos;
}seg[600005];
void mem(void)
{
    for(long long int i=0;i<600004;i++)
    {
        seg[i].zeros=0;
        seg[i].ones=0;
        seg[i].twos=0;
        lazy[i]=0;
    }
}
void built(long long int node,long long int lo,long long int hi)
{
    if(lo==hi)
    {
        seg[node].zeros=1;
        seg[node].ones=0;
        seg[node].twos=0;
        return ;
    }
    long long int mid=(lo+hi)/2;
    built(node*2,lo,mid);
    built(node*2+1,mid+1,hi);
    seg[node].zeros=seg[node*2].zeros+seg[node*2+1].zeros;
    seg[node].ones=seg[node*2].ones+seg[node*2+1].ones;
    seg[node].twos=seg[node*2].twos+seg[node*2+1].twos;

}
void upd(long long int node,long long int lo,long long int hi,long long int l,long long int r)
{
    if(lazy[node]!=0)
    {
        long long int t1,t2,t3;
        long long int tm=lazy[node];
        tm=tm%3;
        t1=seg[node].zeros;
        t2=seg[node].ones;
        t3=seg[node].twos;
        if(tm==1)
        {
            seg[node].zeros=t3;
            seg[node].ones=t1;
            seg[node].twos=t2;
        }
        if(tm==2)
        {
            seg[node].zeros=t2;
            seg[node].ones=t3;
            seg[node].twos=t1;
        }
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
        long long int t1,t2,t3;
        t1=seg[node].zeros;
        t2=seg[node].ones;
        t3=seg[node].twos;
        seg[node].zeros=t3;
        seg[node].ones=t1;
        seg[node].twos=t2;
        if(lo!=hi)
        {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return ;

    }
    long long int mid=(lo+hi)/2;
    upd(node*2,lo,mid,l,r);
    upd(node*2+1,mid+1,hi,l,r);
    seg[node].zeros=seg[node*2].zeros+seg[node*2+1].zeros;
    seg[node].ones=seg[node*2].ones+seg[node*2+1].ones;
    seg[node].twos=seg[node*2].twos+seg[node*2+1].twos;

}
segment query(long long int node,long long int lo,long long int hi,long long int l,long long int r)
{
    if(lazy[node]!=0)
    {
        long long int t1,t2,t3;
        long long int tm=lazy[node];
        tm=tm%3;
        t1=seg[node].zeros;
        t2=seg[node].ones;
        t3=seg[node].twos;
        if(tm==1)
        {
            seg[node].zeros=t3;
            seg[node].ones=t1;
            seg[node].twos=t2;
        }
        if(tm==2)
        {
            seg[node].zeros=t2;
            seg[node].ones=t3;
            seg[node].twos=t1;
        }
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(lo>r||hi<l)
    {
        segment tmp;
        tmp.zeros=0;
        tmp.ones=0;
        tmp.twos=0;
        return tmp;
    }
    if(lo>=l&&hi<=r)return seg[node];
    long long int mid=(lo+hi)/2;
    segment p1=query(node*2,lo,mid,l,r);
    segment p2=query(node*2+1,mid+1,hi,l,r);
    segment p;
    p.zeros=p1.zeros+p2.zeros;
    p.ones=p1.ones+p2.ones;
    p.twos=p1.twos+p2.twos;
    return p;

}
int main()
{
    scanf("%lld",&t);
    long long int tc=0;
    while(t--)
    {
        mem();
        scanf("%lld%lld",&n,&q);
        built(1,0,n-1);
        printf("Case %lld:\n",++tc);
        while(q--)
        {
            long long int ck,iii,jjj;
            scanf("%lld%lld%lld",&ck,&iii,&jjj);
            if(ck==0)
            {
                upd(1,0,n-1,min(iii,jjj),max(iii,jjj));
            }
            else
            {
                segment ans=query(1,0,n-1,min(iii,jjj),max(iii,jjj));
                printf("%lld\n",ans.zeros);
            }
        }
    }
    return 0;
}