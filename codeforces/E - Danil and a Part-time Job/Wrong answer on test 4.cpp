/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/07/2017 13:09                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 30500 KB                             
*  problem: https://codeforces.com/contest/877/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
long n,x,st[200005],ed[200005],arr[200005],lazy[1000000],q,timer;
vector<long>adj[200005];
struct segment
{
    long on;
    long of;
} seg[1000000];
void build(long node,long lo,long hi)
{
    if(lo==hi)
    {
        if(arr[lo]==1)seg[node]= {1,0};
        else seg[node]= {0,1};
        return ;
    }
    long mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    seg[node].on=seg[node*2].on+seg[node*2+1].on;
    seg[node].of=seg[node*2].of+seg[node*2+1].of;
}
void upd(long node,long lo,long hi,long lft,long rgt)
{
    if(lo>rgt||hi<lft)return ;
    if(lo>=lft&&hi<=rgt)
    {
        swap(seg[node].on,seg[node].of);
        if(lo!=hi)
        {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,lft,rgt);
    upd(node*2+1,mid+1,hi,lft,rgt);
    seg[node].on=seg[node*2].on+seg[node*2+1].on;
    seg[node].of=seg[node*2].of+seg[node*2+1].of;
 }
segment query(long node,long lo,long hi,long lft,long rgt)
{
    if(lazy[node]%2==1)
    {
        swap(seg[node].on,seg[node].of);
        if(lo!=hi)
        {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        lazy[node]=0;
    }
    if(lo>rgt||hi<lft)return {0,0};
    if(lo>=lft&&hi<=rgt)
    {
        return seg[node];
    }
    long mid=(lo+hi)/2;
    segment p1=query(node*2,lo,mid,lft,rgt);
    segment p2=query(node*2+1,mid+1,hi,lft,rgt);
    return {p1.on+p2.on,p1.of+p2.of};
}
void dfs(long now,long par)
{
    st[now]=++timer;
    for(long i=0; i<adj[now].size(); i++)
    {
        x=adj[now][i];
        if(x==par)continue;
        dfs(x,now);
    }
    ed[now]=timer;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=2; i<=n; i++)
    {
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1,-1);
     for(long i=1; i<=n; i++)cin>>arr[i];
     build(1,1,n);
     cin>>q;
    while(q--)
    {
        cin>>s>>x;
        if(s=="pow")upd(1,1,n,st[x],ed[x]);
        else
        {
            segment xx=query(1,1,n,st[x],ed[x]);
            cout<<xx.on<<endl;
        }
    }
    return 0;
}