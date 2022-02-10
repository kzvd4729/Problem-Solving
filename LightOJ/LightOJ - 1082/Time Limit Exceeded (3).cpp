/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-29 00:54:18                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1082
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,arr[100005],seg[500005],q,i,x,y;
void build(int node,int start,int end)
{
    if(start==end)
    {
        seg[node]=arr[start];
    }
    else
    {
        int mid=(start+end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        seg[node]=min(seg[node*2],seg[node*2+1]);
    }
}
int query(int node,int start,int end,int l,int r)
{
    if(l>end||r<start)return 9999999;
    if(start>=l&&end<=r)return seg[node];

    int mid=(start+end)/2;
    int p1=query(node*2,start,mid,l,r);
    int p2=query(node*2+1,mid+1,end,l,r);
    return min(p1,p2);
}
int main()
{
    cin>>t;
    int tc=0;
    while(t--)
    {
        cin>>n>>q;
        for(i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        build(1,1,n);
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<endl;
        }
    }
    return 0;
}