/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-24 15:13:59                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6139
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],seg[500005];
void build(long n,long lo,long hi)
{
    if(lo==hi)
    {
        seg[n]=arr[lo];
        return ;
    }
    long mid=(lo+hi)/2;
    build(n*2,lo,mid);
    build(n*2+1,mid+1,hi);
    seg[n]=seg[n*2]*seg[n*2+1];
}
void upd(long n,long lo,long hi,long id,long v)
{
    if(lo==hi)
    {
        seg[n]=v;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)upd(n*2,lo,mid,id,v);
    else upd(n*2+1,mid+1,hi,id,v);
    seg[n]=seg[n*2]*seg[n*2+1];
}
long que(long n,long lo,long hi,long l,long r)
{
    if(r<lo||l>hi)return 1;
    if(lo>=l&&hi<=r)return seg[n];
    long mid=(lo+hi)/2;
    long p1=que(n*2,lo,mid,l,r);
    long p2=que(n*2+1,mid+1,hi,l,r);
    long p=p1*p2;
    return p;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long n,q,l,r;
    char c;
    while(cin>>n>>q)
    {
        for(long i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        build(1,1,n);
        while(q--)
        {
            cin>>c>>l>>r;
            if(c=='C')
            {
                upd(1,1,n,l,r);
            }
            else
            {
                long x=que(1,1,n,l,r);
                if(x==0)cout<<0;
                else if(x<0)cout<<'-';
                else cout<<'+';
            }
        }
        cout<<endl;
    }
    return 0;
}