/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-31 10:23:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 140                                        memory_used (MB): 20.5                            
*  problem: https://vjudge.net/problem/SPOJ-KGSS
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,i,arr[100004],id,v,q,l,r;
char c;
struct tree
{
    int first;
    int sec;
} seg[500005];
void build(int node,int lo,int hi)
{
    if(lo==hi)
    {
        seg[node].first=arr[lo];
        seg[node].sec=-99999999;
        return ;
    }

    int mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);

    if(seg[node*2].first>seg[node*2+1].first)
    {
        seg[node].first=seg[node*2].first;
        seg[node].sec=max(seg[node*2+1].first,max(seg[node*2].sec,seg[node*2+1].sec));
    }
    else
    {
        seg[node].first=seg[node*2+1].first;
        seg[node].sec=max(seg[node*2].first,max(seg[node*2].sec,seg[node*2+1].sec));
    }

}
void upd(int node,int lo,int hi,int id,int v)
{
    if(lo==hi)
    {
        arr[lo]=v;
        seg[node].first=v;
        seg[node].sec=-99999999;
        return ;
    }
    int mid=(lo+hi)/2;
    if(id<=mid)
    {
        upd(node*2,lo,mid,id,v);
    }
    else upd(node*2+1,mid+1,hi,id,v);
    if(seg[node*2].first>seg[node*2+1].first)
    {
        seg[node].first=seg[node*2].first;
        seg[node].sec=max(seg[node*2+1].first,max(seg[node*2].sec,seg[node*2+1].sec));
    }
    else
    {
        seg[node].first=seg[node*2+1].first;
        seg[node].sec=max(seg[node*2].first,max(seg[node*2].sec,seg[node*2+1].sec));
    }

}
tree query(int node,int lo,int hi,int l,int r)
{
    if(lo>r||hi<l)
    {
        tree tmp;
        tmp.first=0;
        tmp.sec=0;
        return tmp;
    }
    if(lo>=l&&hi<=r)
    {
        return seg[node];
    }
    int mid=(lo+hi)/2;
    tree p1=query(node*2,lo,mid,l,r);
    tree p2=query(node*2+1,mid+1,hi,l,r);
    tree p;
    if(p1.first>p2.first)
    {
        p.first=p1.first;
        p.sec=max(p2.first,max(p1.sec,p2.sec));
    }
    if(p2.first>p1.first)
    {
        p.first=p2.first;
        p.sec=max(p1.first,max(p1.sec,p2.sec));
    }
    return p;
}
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)cin>>arr[i];
    build(1,1,n);
    cin>>q;
    while(q--)
    {
        cin>>c;
        if(c=='U')
        {
            cin>>id>>v;
            upd(1,1,n,id,v);
        }
        else
        {
            cin>>l>>r;
            tree ans=query(1,1,n,l,r);
            cout<<ans.first+ans.sec<<endl;
        }
    }

    return 0;
}