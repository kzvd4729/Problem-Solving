/****************************************************************************************
*  @author: kzvd4729                                         created: 05-09-2017 22:12:32                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.24 sec                                        memory_used: 30.9M                                
*  problem: https://www.codechef.com/SEPT17/problems/SEACO
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define M 1000000007
using namespace std;
long t,n,m,seg[400004],lazy[400004],ans[100005],id,seg2[400004],lazy2[400004];
struct data
{
    long ty;
    long lf;
    long rt;
} arr[100005];
void mem(void)
{
    for(long i=0; i<=400000; i++)
    {
        seg[i]=0;
        lazy[i]=0;
        seg2[i]=0;
        lazy2[i]=0;
    }
}
void upd(long node,long lo,long hi,long l,long r,long v)
{
    if(lazy[node])
    {
        seg[node]+=lazy[node];
        seg[node]=seg[node]%M;
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2]=lazy[node*2]%M;
            lazy[node*2+1]+=lazy[node];
            lazy[node*2+1]=lazy[node*2+1]%M;
        }
        lazy[node]=0;
    }
    if(lazy2[node])
    {
        seg2[node]+=lazy2[node];
        seg2[node]=seg2[node]%M;
        if(lo!=hi)
        {
            lazy2[node*2]+=lazy2[node];
            lazy2[node*2]=lazy2[node*2]%M;
            lazy2[node*2+1]+=lazy2[node];
            lazy2[node*2+1]=lazy2[node*2+1]%M;
        }
        lazy2[node]=0;
    }
    if(hi<l||lo>r)return ;
    if(hi<=r&&lo>=l)
    {
        seg[node]+=v;
        seg[node]=seg[node]%M;
        if(lo!=hi)
        {
            lazy[node*2]+=v;
            lazy[node*2]=lazy[node*2]%M;
            lazy[node*2+1]+=v;
            lazy[node*2+1]=lazy[node*2+1]%M;
        }
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,l,r,v);
    upd(node*2+1,mid+1,hi,l,r,v);
    seg[node]=seg[node*2]+seg[node*2+1];
    seg[node]=seg[node]%M;
}
void upd2(long node,long lo,long hi,long l,long r,long v)
{
    if(lazy[node])
    {
        seg[node]+=lazy[node];
        seg[node]=seg[node]%M;
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2]=lazy[node*2]%M;
            lazy[node*2+1]+=lazy[node];
            lazy[node*2+1]=lazy[node*2+1]%M;
        }
        lazy[node]=0;
    }
    if(lazy2[node])
    {
        seg2[node]+=lazy2[node];
        seg2[node]=seg2[node]%M;
        if(lo!=hi)
        {
            lazy2[node*2]+=lazy2[node];
            lazy2[node*2]=lazy2[node*2]%M;
            lazy2[node*2+1]+=lazy2[node];
            lazy2[node*2+1]=lazy2[node*2+1]%M;
        }
        lazy2[node]=0;
    }
    if(hi<l||lo>r)return ;
    if(hi<=r&&lo>=l)
    {
        seg2[node]+=v;
        seg2[node]=seg2[node]%M;
        if(lo!=hi)
        {
            lazy2[node*2]+=v;
            lazy2[node*2]=lazy2[node*2]%M;
            lazy2[node*2+1]+=v;
            lazy2[node*2+1]=lazy2[node*2+1]%M;
        }
        return ;
    }
    long mid=(lo+hi)/2;
    upd2(node*2,lo,mid,l,r,v);
    upd2(node*2+1,mid+1,hi,l,r,v);
    seg2[node]=seg2[node*2]+seg2[node*2+1];
    seg2[node]=seg2[node]%M;
}
long que(long node,long lo,long hi,long l,long r)
{
    if(lazy[node])
    {
        seg[node]+=lazy[node];
        seg[node]=seg[node]%M;
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2]=lazy[node*2]%M;
            lazy[node*2+1]+=lazy[node];
            lazy[node*2+1]=lazy[node*2+1]%M;
        }
        lazy[node]=0;
    }
    if(lazy2[node])
    {
        seg2[node]+=lazy2[node];
        seg2[node]=seg2[node]%M;
        if(lo!=hi)
        {
            lazy2[node*2]+=lazy2[node];
            lazy2[node*2]=lazy2[node*2]%M;
            lazy2[node*2+1]+=lazy2[node];
            lazy2[node*2+1]=lazy2[node*2+1]%M;
        }
        lazy2[node]=0;
    }
    if(hi<l||lo>r)return 0;
    if(hi<=r&&lo>=l)
    {
        return seg[node];
    }
    long mid=(lo+hi)/2;
    long p1=que(node*2,lo,mid,l,r);
    long p2=que(node*2+1,mid+1,hi,l,r);
    return (p1+p2)%M;
}
void lazy2_upd(long node,long lo,long hi)
{
    if(lazy2[node])
    {
        seg2[node]+=lazy2[node];
        seg2[node]=seg2[node]%M;
        if(lo!=hi)
        {
            lazy2[node*2]+=lazy2[node];
            lazy2[node*2]=lazy2[node*2]%M;
            lazy2[node*2+1]+=lazy2[node];
            lazy2[node*2+1]=lazy2[node*2+1]%M;
        }
        lazy2[node]=0;
    }
    if(lo==hi)return ;
    long mid=(lo+hi)/2;
    lazy2_upd(node*2,lo,mid);
    lazy2_upd(node*2+1,mid+1,hi);
}
void seg2_upd(long node,long lo,long hi)
{
    if(lo==hi)
    {
        ans[lo]=seg2[node]%M;
        return ;
    }
    long mid=(lo+hi)/2;
    seg2_upd(node*2,lo,mid);
    seg2_upd(node*2+1,mid+1,hi);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        mem();
        cin>>n>>m;
        for(long i=1; i<=m; i++)
        {
            cin>>arr[i].ty>>arr[i].lf>>arr[i].rt;
        }
        for(long i=m; i>=1; i--)
        {
            long x=que(1,1,n,i,i);
            ///cout<<x<<endl;
            if(arr[i].ty==2)upd(1,1,n,arr[i].lf,arr[i].rt,(x+1)%M);
            else upd2(1,1,n,arr[i].lf,arr[i].rt,(x+1)%M);
        }
        lazy2_upd(1,1,n);
        seg2_upd(1,1,n);
        /*for(long i=0; i<=400000; i++)
        {
            if(lazy[i]!=0)cout<<1<<endl;
            if(lazy2[i]!=0)cout<<2<<endl;
        }*/
        for(long i=1;i<=n;i++)
        {
            cout<<ans[i]%M;
            if(i!=n)cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}
/*
3
5 5
1 1 2
1 4 5
2 1 2
2 1 3
2 3 4
1 2
1 1 1
1 1 1
10 10
1 1 10
2 1 1
2 1 2
2 1 3
2 1 4
2 1 5
2 1 6
2 1 7
2 1 8
2 1 9
*/