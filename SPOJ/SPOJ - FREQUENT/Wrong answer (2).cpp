/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-01 12:15:45                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-FREQUENT
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,arr[100005],q,xxxx,i,l,r;
struct segment
{
    int lf;
    int lv;
    int rf;
    int rv;
    int mf;
}seg[500005];
void build(int node,int lo,int hi)
{
    if(lo==hi)
    {
        seg[node].lf=1;
        seg[node].lv=arr[lo];
        seg[node].rf=1;
        seg[node].rv=arr[lo];
        seg[node].mf=1;
        return ;
    }
    int mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    if(seg[node*2].lv==seg[node*2+1].lv)
    {
        seg[node].lf=seg[node*2].lf+seg[node*2+1].lf;
        seg[node].lv=seg[node*2].lv;
    }
    else
    {
        seg[node].lf=seg[node*2].lf;
        seg[node].lv=seg[node*2].lv;
    }

    if(seg[node*2+1].rv==seg[node*2].rv)
    {
        seg[node].rf=seg[node*2+1].rf+seg[node*2].rf;
        seg[node].rv=seg[node*2+1].rv;
    }
    else
    {
        seg[node].rf=seg[node*2+1].rf;
        seg[node].rv=seg[node*2+1].rv;
    }
    if(seg[node*2].rv==seg[node*2+1].lv)
    {
        seg[node].mf=seg[node*2].rf+seg[node*2+1].lf;
    }
    else seg[node].mf=0;
    seg[node].mf=max(seg[node].mf,max(seg[node].lf,max(seg[node].rf,max(seg[node*2].mf,seg[node*2+1].mf))));

}
segment query(int node,int lo,int hi,int l,int r)
{
    if(lo>r||hi<l)
    {
        segment tmp;
        tmp.lf=0;
        tmp.lv=0;
        tmp.rf=0;
        tmp.rv=0;
        tmp.mf=0;
        return tmp;

    }
    if(lo>=l&&hi<=r)return seg[node];
    int mid=(lo+hi)/2;
    segment p1=query(node*2,lo,mid,l,r);
    segment p2=query(node*2+1,mid+1,hi,l,r);
    segment p;


    if(p1.lv==p2.lv)
    {
        p.lf=p1.lf+p2.lf;
        p.lv=p1.lv;
    }
    else
    {
        p.lf=p1.lf;
        p.lv=p1.lv;
    }

    if(p2.rv==p1.rv)
    {
        p.rf=p2.rf+p1.rf;
        p.rv=p2.rv;
    }
    else
    {
        p.rf=p2.rf;
        p.rv=p2.rv;
    }
    if(p1.lv==p2.rv)
    {
        p.mf=p1.lf+p2.rf;
    }
    else p.mf=0;
    p.mf=max(p.mf,max(p.lf,max(p.rf,max(p1.mf,p2.mf))));
    return p;

}
int main()
{
    cin>>n>>q;
    for(i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(q--)
    {
        cin>>l>>r;
        segment ans=query(1,1,n,l,r);
        cout<<ans.mf<<endl;
    }
    cin>>xxxx;

    return 0;
}