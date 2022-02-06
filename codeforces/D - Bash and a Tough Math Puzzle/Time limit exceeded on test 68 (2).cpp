/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/21/2018 13:51                        
*  solution_verdict: Time limit exceeded on test 68          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/914/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,x,q,ck,seg[4*500005],id,l,r,gcd;
void upd(int node,int lo,int hi,int idx,int vl)
{
    if(idx<lo||idx>hi)return ;
    if(lo==hi)
    {
        seg[node]=vl;
        return ;
    }
    int mid=(lo+hi)/2;
    upd(node*2,lo,mid,idx,vl);
    upd(node*2+1,mid+1,hi,idx,vl);
    seg[node]=__gcd(seg[node*2],seg[node*2+1]);
}
int query(int node,int lo,int hi,int l,int r,int gcd)
{
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)
    {
        if(seg[node]%gcd==0)return 0;
        if(lo==hi)return 1;
    }
    int mid=(lo+hi)/2;
    int p1=query(node*2,lo,mid,l,r,gcd);
    int p2=query(node*2+1,mid+1,hi,l,r,gcd);
    return p1+p2;
}
int main()
{
    scanf("%ld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%ld",&x);
        upd(1,1,n,i,x);
    }
    scanf("%ld",&q);
    while(q--)
    {
        scanf("%ld",&ck);
        if(ck==1)
        {
            scanf("%ld%ld%ld",&l,&r,&gcd);
            if(query(1,1,n,l,r,gcd)<2)printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            scanf("%ld%ld",&id,&x);
            upd(1,1,n,id,x);
        }
    }
    return 0;
}