/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2018 17:02                        
*  solution_verdict: Runtime error on test 4                 language: GNU C++17                               
*  run_time: 233 ms                                          memory_used: 25300 KB                             
*  problem: https://codeforces.com/contest/915/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,q,l,r,ty,sz=1;
struct segment
{
    long sum,lft,rgt,lazy;
} seg[750000];
void upd(long node,long lo,long hi,long l,long r,long ty)
{
    if(!seg[node].lft)seg[node].lft=++sz;
    if(!seg[node].rgt)seg[node].rgt=++sz;
    long mid=(lo+hi)/2;
    if(seg[node].lazy==1)
    {
        seg[node].sum=hi-lo+1;
        if(lo!=hi)
        {
            seg[seg[node].lft].sum=mid-lo+1;
            seg[seg[node].lft].lazy=1;
            seg[seg[node].rgt].sum=hi-mid;
            seg[seg[node].rgt].lazy=1;
        }
    }
    if(seg[node].lazy==2)
    {
        seg[node].sum=0;
        if(lo!=hi)
        {
            seg[seg[node].lft].sum=0;
            seg[seg[node].lft].lazy=2;
            seg[seg[node].rgt].sum=0;
            seg[seg[node].rgt].lazy=2;
        }
    }
    seg[node].lazy=0;
     if(lo>r||hi<l)return ;
     if(lo>=l&&hi<=r)
    {
        if(ty==1)
        {
            seg[node].sum=hi-lo+1;
            if(lo!=hi)
            {
                seg[seg[node].lft].sum=mid-lo+1;
                seg[seg[node].lft].lazy=1;
                seg[seg[node].rgt].sum=hi-mid;
                seg[seg[node].rgt].lazy=1;
            }
        }
        if(ty==2)
        {
            seg[node].sum=0;
            if(lo!=hi)
            {
                seg[seg[node].lft].sum=0;
                seg[seg[node].lft].lazy=2;
                seg[seg[node].rgt].sum=0;
                seg[seg[node].rgt].lazy=2;
            }
        }
        return ;
    }
    upd(seg[node].lft,lo,mid,l,r,ty);
    upd(seg[node].rgt,mid+1,hi,l,r,ty);
    seg[node].sum=seg[seg[node].lft].sum+seg[seg[node].rgt].sum;
 }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>q;
    while(q--)
    {
        cin>>l>>r>>ty;
        upd(1,1,n,l,r,ty);
        cout<<n-seg[1].sum<<endl;
    }
    return 0;
}