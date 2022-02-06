/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/23/2018 22:59                        
*  solution_verdict: Memory limit exceeded on test 8         language: GNU C++14                               
*  run_time: 998 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/447/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000009;
const long N=300000;
long fb[N+2],n,m,arr[N+2],seg[3*N],ty,l,r,ll,rr,md;
vector<int>lazy[3*N];
void fibonacci(void)
{
    fb[1]=1;
    fb[2]=1;
    for(long i=3;i<=N;i++)fb[i]=(fb[i-1]+fb[i-2])%mod;
    for(long i=2;i<=N;i++)fb[i]=(fb[i]+fb[i-1])%mod;
}
void build(long node,long lo,long hi)
{
    if(lo==hi)
    {
        seg[node]=arr[lo];
        return ;
    }
    long mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
void upd(long node,long lo,long hi,long l,long r)
{
    while(lazy[node].size())
    {
        rr=lazy[node][lazy[node].size()-1];
        lazy[node].pop_back();
        ll=lazy[node][lazy[node].size()-1];
        lazy[node].pop_back();
        seg[node]=(seg[node]+fb[rr]+mod-fb[ll-1])%mod;
        if(lo!=hi)
        {
            md=(ll+rr)/2;
            lazy[node*2].push_back(ll);
            lazy[node*2].push_back(md);
            lazy[node*2+1].push_back(md+1);
            lazy[node*2+1].push_back(rr);
        }
    }
    if(lo>r||hi<l)return ;
    if(lo>=l&&hi<=r)
    {
        ll=lo-l+1;
        rr=ll+hi-lo;
        seg[node]=(seg[node]+fb[rr]+mod-fb[ll-1])%mod;
        if(lo!=hi)
        {
            md=(ll+rr)/2;
            lazy[node*2].push_back(ll);
            lazy[node*2].push_back(md);
            lazy[node*2+1].push_back(md+1);
            lazy[node*2+1].push_back(rr);
        }
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,l,r);
    upd(node*2+1,mid+1,hi,l,r);
    seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
long query(long node,long lo,long hi,long l,long r)
{
    while(lazy[node].size())
    {
        rr=lazy[node][lazy[node].size()-1];
        lazy[node].pop_back();
        ll=lazy[node][lazy[node].size()-1];
        lazy[node].pop_back();
        seg[node]=(seg[node]+fb[rr]+mod-fb[ll-1])%mod;
        if(lo!=hi)
        {
            md=(ll+rr)/2;
            lazy[node*2].push_back(ll);
            lazy[node*2].push_back(md);
            lazy[node*2+1].push_back(md+1);
            lazy[node*2+1].push_back(rr);
        }
    }
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)return seg[node];
    long mid=(lo+hi)/2;
    return (query(node*2,lo,mid,l,r)+query(node*2+1,mid+1,hi,l,r))%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     fibonacci();
    cin>>n>>m;
    for(long i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(m--)
    {
        cin>>ty>>l>>r;
        if(ty==1)upd(1,1,n,l,r);
        else cout<<query(1,1,n,l,r)<<endl;
    }
    return 0;
}