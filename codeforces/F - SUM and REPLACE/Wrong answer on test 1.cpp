/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2018 23:08                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 123200 KB                            
*  problem: https://codeforces.com/contest/920/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,nod[1000006],seg[10][2000006],ty,l,r,lazy[2000006][3],arr[4000006],m;
void number_of_divisor(void)
{
    n=1000000;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            nod[j]++;
        }
    }
}
void build(int id,int node,int lo,int hi)
{
    if(lo==hi)
    {
        seg[id][node]=arr[lo];
        return ;
    }
    int mid=(lo+hi)/2;
    build(id,node*2,lo,mid);
    build(id,node*2+1,mid+1,hi);
    seg[id][node]=seg[id][node*2]+seg[id][node*2+1];
}
void upd_query(int node,int lo,int hi,int l,int r)
{
    if(lo>r||hi<l)return ;
    if(lo>=l&&hi<=r)
    {
        lazy[node][0]=max(10,lazy[node][0]+1);
        lazy[node][1]=max(10,lazy[node][1]+1);
        return ;
    }
    int mid=(lo+hi)/2;
    upd_query(node*2,lo,mid,l,r);
    upd_query(node*2+1,mid+1,hi,l,r);
}
int ret_query(int node,int lo,int hi,int l,int r)
{
    if(lo>r||hi<l)return 0;
    if(lazy[node][1])
    {
        lazy[node*2][0]+=lazy[node][1];
        lazy[node*2][1]+=lazy[node][1];
        lazy[node*2+1][0]+=lazy[node][1];
        lazy[node*2+1][1]+=lazy[node][1];
        if(lazy[node*2][0]>10)lazy[node*2][0]=10;
        if(lazy[node*2][1]>10)lazy[node*2][1]=10;
        if(lazy[node*2+1][0]>10)lazy[node*2+1][0]=10;
        if(lazy[node*2+1][1]>10)lazy[node*2+1][1]=10;
        lazy[node][1]=0;
    }
    if(lo>=l&&hi<=r)return seg[lazy[node][0]][node];
    int mid=(lo+hi)/2;
    int p1=ret_query(node*2,lo,mid,l,r);
    int p2=ret_query(node*2+1,mid+1,hi,l,r);
    return p1+p2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    number_of_divisor();
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0;i<=10;i++)
    {
        build(i,1,1,n);
        for(int j=1;j<=n;j++)arr[j]=nod[arr[j]];
    }
    while(m--)
    {
        cin>>ty>>l>>r;
        if(ty==1)upd_query(1,1,n,l,r);
        else cout<<ret_query(1,1,n,l,r)<<endl;
    }
    return 0;
}