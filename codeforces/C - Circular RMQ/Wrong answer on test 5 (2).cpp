/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2017 18:57                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 6200 KB                              
*  problem: https://codeforces.com/contest/52/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int arr[100002],seg[500003],lazy[500003],lr[30],id,q,n;
string s;
void convert(string x)
{
    id=0;
    int last=0;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]==' '||i==x.size()-1)
        {
            int j=i;
            if(j!=x.size()-1)j--;
            int z=0;
            int neg=0;
            for(int k=last; k<=j; k++)
            {
                if(x[k]=='-')
                {
                    neg=1;
                    continue;
                }
                z=z*10+(int)(x[k]-'0');
            }
            lr[++id]=z;
            if(neg==1)lr[id]=lr[id]*(-1);
            last=j+2;
        }
    }
}
void build(int node,int lo,int hi)
{
    if(lo==hi)
    {
        seg[node]=arr[lo];
        return ;
    }
    int mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int l,int r,int v)
{
    if(lazy[node]!=0)
    {
        seg[node]+=v;
        if(lo!=hi)
        {
            lazy[node*2]+=v;
            lazy[node*2+1]+=v;
        }
        lazy[node]=0;
    }
    if(lo>r||hi<l)return;
    if(lo>=l&&hi<=r)
    {
        seg[node]+=v;
        if(lo!=hi)
        {
            lazy[node*2]+=v;
            lazy[node*2+1]+=v;
        }
        return ;
    }
    int mid=(lo+hi)/2;
    upd(node*2,lo,mid,l,r,v);
    upd(node*2+1,mid+1,hi,l,r,v);
    seg[node]=min(seg[node*2],seg[node*2+1]);
}
int query(int node,int lo,int hi,int l,int r)
{
    if(lazy[node]!=0)
    {
        seg[node]+=lazy[node];
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(lo>r||hi<l)return 99999999;
    if(lo>=l&&hi<=r)return seg[node];
    int mid=(lo+hi)/2;
    int p1=query(node*2,lo,mid,l,r);
    int p2=query(node*2+1,mid+1,hi,l,r);
    return min(p1,p2);
 }
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];
    build(1,0,n-1);
    cin>>q;
    getchar();
    while(q--)
    {
        getline(cin,s);
        convert(s);
        if(id==3)
        {
            if(lr[2]>=lr[1])
            {
                upd(1,0,n-1,lr[1],lr[2],lr[3]);
            }
            else
            {
                upd(1,0,n-1,lr[1],n-1,lr[3]);
                upd(1,0,n-1,0,lr[2],lr[3]);
            }
        }
        else
        {
            if(lr[2]>=lr[1])
            {
                cout<<query(1,0,n-1,lr[1],lr[2])<<endl;
            }
            else
            {
                cout<<min(query(1,0,n-1,lr[1],n-1),query(1,0,n-1,0,lr[2]))<<endl;
            }
        }
    }
    return 0;
}