/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-12 01:51:12                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-DQUERY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,last[1000006],sz,lft,rgt,root[1000006],q;
struct segment
{
    long l,r,sum;
}seg[3000000];
void upd(long node,long lo,long hi,long id,long vl,long pnode)
{
    if(lo>id||hi<id)return ;
    if(lo==hi)
    {
        seg[node].sum+=vl;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)
    {
        seg[node].r=seg[pnode].r;
        if(!seg[node].l)seg[node].l=++sz;
        upd(seg[node].l,lo,mid,id,vl,seg[pnode].l);
    }
    else
    {
        seg[node].l=seg[pnode].l;
        if(!seg[node].r)seg[node].r=++sz;
        upd(seg[node].r,mid+1,hi,id,vl,seg[pnode].r);
    }
    seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
void upd2(long node,long lo,long hi,long id,long vl)
{
    if(lo>id||hi<id)return ;
    if(lo==hi)
    {
        seg[node].sum+=vl;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)upd2(seg[node].l,lo,mid,id,vl);
    else upd2(seg[node].r,mid+1,hi,id,vl);
    seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
long query(long node,long lo,long hi,long lt,long rt)
{
    if(lo>=lt&&hi<=rt)return seg[node].sum;
    if(lo>rt||hi<lt)return 0;
    long mid=(lo+hi)/2;
    if(mid>=rt)return query(seg[node].l,lo,mid,lt,rt);
    else if(mid<lt)return query(seg[node].r,mid+1,hi,lt,rt);
    else return query(seg[node].l,lo,mid,lt,rt)+query(seg[node].r,mid+1,hi,lt,rt);
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
        root[i]=++sz;
        upd(root[i],1,n,i,1,root[i-1]);
        upd2(root[i],1,n,last[x],-1);
        last[x]=i;
    }
    ///cout<<seg[0].sum<<endl;

//    for(long i=1;i<=n;i++)
//    {
//        cout<<seg[root[i]].sum<<endl;
//    }
//    while(true)
//    {
//        cout<<node<<endl;
//        if(node==0)break;
//        node=seg[node].r;
//    }


//    for(long i=1;i<=n;i++)
//    {
//        cout<<"starts from here::"<<endl;
//        long node=root[i];
//        cout<<node<<endl;
//        while(seg[node].l)
//        {
//            cout<<seg[node].l<<" ";
//            node=seg[node].l;
//        }
//        cout<<endl;
//        node=root[i];
//        while(seg[node].r)
//        {
//            cout<<seg[node].r<<" ";
//            node=seg[node].r;
//        }
//        cout<<endl;
//    }
    cin>>q;
    while(q--)
    {
        cin>>lft>>rgt;
        ///cout<<seg[root[rgt]].sum<<endl;
        cout<<query(root[rgt],1,n,lft,rgt)<<endl;
    }
    return 0;
}