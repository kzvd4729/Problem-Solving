/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-25 20:29:44                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1183
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,q,tc,sum,dn,lt,rt,ty,seg[300000],lazy[300000],gcd,vl;
void upd(long node,long lo,long hi,long lt,long rt,long vl)
{
    if(lazy[node]!=-1)
    {
        seg[node]=(hi-lo+1)*lazy[node];
        if(lo!=hi)
        {
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(lo>rt||hi<lt)return ;
    if(lo>=lt&&hi<=rt)
    {
        seg[node]=(hi-lo+1)*vl;
        if(lo!=hi)
        {
            lazy[node*2]=vl;
            lazy[node*2+1]=vl;
        }
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,lt,rt,vl);
    upd(node*2+1,mid+1,hi,lt,rt,vl);
    seg[node]=seg[node*2]+seg[node*2+1];
}
long query(long node,long lo,long hi,long lt,long rt)
{
    if(lazy[node]!=-1)
    {
        seg[node]=(hi-lo+1)*lazy[node];
        if(lo!=hi)
        {
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(lo>rt||hi<lt)return 0;
    if(lo>=lt&&hi<=rt)return seg[node];
    long mid=(lo+hi)/2;
    long p1=query(node*2,lo,mid,lt,rt);
    long p2=query(node*2+1,mid+1,hi,lt,rt);
    ///seg[node]=seg[node*2]+seg[node*2+1];
    return p1+p2;
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        for(long i=0; i<400000; i++)seg[i]=0,lazy[i]=-1;
        scanf("%lld%lld",&n,&q);
        printf("Case %lld:\n",++tc);
        while(q--)
        {
            scanf("%lld%lld%lld",&ty,&lt,&rt);
            if(ty==1)
            {
                scanf("%lld",&vl);
                upd(1,0,n-1,lt,rt,vl);
            }
            else
            {
                sum=query(1,0,n-1,lt,rt);
                dn=(rt-lt+1);
                gcd=__gcd(sum,dn);
                sum/=gcd;
                dn/=gcd;
                ///dn=1;
                if(dn==1)printf("%lld\n",sum);
                else printf("%lld/%lld\n",sum,dn);
            }
        }
    }
    return 0;
}