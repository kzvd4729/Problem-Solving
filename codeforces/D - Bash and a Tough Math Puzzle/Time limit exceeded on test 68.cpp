/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/21/2018 13:43                        
*  solution_verdict: Time limit exceeded on test 68          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 17500 KB                             
*  problem: https://codeforces.com/contest/914/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,q,ck,seg[4*500005],id,l,r,gcd;
void upd(long node,long lo,long hi,long idx,long vl)
{
    if(idx<lo||idx>hi)return ;
    if(lo==hi)
    {
        seg[node]=vl;
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,idx,vl);
    upd(node*2+1,mid+1,hi,idx,vl);
    seg[node]=__gcd(seg[node*2],seg[node*2+1]);
}
long query(long node,long lo,long hi,long l,long r,long gcd)
{
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)
    {
        if(seg[node]%gcd==0)return 0;
        if(lo==hi)return 1;
    }
    long mid=(lo+hi)/2;
    long p1=query(node*2,lo,mid,l,r,gcd);
    long p2=query(node*2+1,mid+1,hi,l,r,gcd);
    return p1+p2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        upd(1,1,n,i,x);
    }
    cin>>q;
    while(q--)
    {
        cin>>ck;
        if(ck==1)
        {
            cin>>l>>r>>gcd;
            if(query(1,1,n,l,r,gcd)<2)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            cin>>id>>x;
            upd(1,1,n,id,x);
        }
    }
    return 0;
}