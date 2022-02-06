/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2018 14:58                        
*  solution_verdict: Runtime error on test 4                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/915/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long seg[400005],lazy[400005],n,l,r,q,ty;
void upd(long node,long lo,long hi,long l,long r,long ty)
{
    if(lazy[node]==1)
    {
        seg[node]=0;
        if(lo!=hi)
        {
            lazy[node*2]=1;
            lazy[node*2+1]=1;
        }
    }
    if(lazy[node]==2)
    {
        seg[node]=hi-lo+1;
        if(lo!=hi)
        {
            lazy[node*2]=2;
            lazy[node*2+1]=2;
        }
    }
    lazy[node]=0;
    if(lo>r||hi<l)return ;
    if(lo>=l&&hi<=r)
    {
        if(ty==1)
        {
            seg[node]=0;
            if(lo!=hi)
            {
                lazy[node*2]=1;
                lazy[node*2+1]=1;
            }
        }
        else
        {
            seg[node]=hi-lo+1;
            if(lo!=hi)
            {
                lazy[node*2]=2;
                lazy[node*2+1]=2;
            }
        }
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,l,r,ty);
    upd(node*2+1,mid+1,hi,l,r,ty);
    seg[node]=seg[node*2]+seg[node*2+1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=0; i<=400000; i++)lazy[i]=2;
     cin>>q;
    while(q--)
    {
        cin>>l>>r>>ty;
        upd(1,1,n,l,r,ty);
        cout<<seg[1]<<endl;
    }
    return 0;
}