/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2017 15:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1964 ms                                         memory_used: 7400 KB                              
*  problem: https://codeforces.com/contest/339/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int nn,n,q,arr[700005],seg[700005],p,b,i;
void upd(int node,int lo,int hi,int id,int v,int h)
{
    if(lo==hi)
    {
        seg[node]=v;
        return ;
    }
    int mid=(lo+hi)/2;
    if(id<=mid)upd(node*2,lo,mid,id,v,h-1);
    else upd(node*2+1,mid+1,hi,id,v,h-1);
    if(h%2==0)seg[node]=seg[node*2]^seg[node*2+1];
    else seg[node]=seg[node*2]|seg[node*2+1];
 }
int main()
{
    cin>>nn>>q;
    n=1;
    for(i=1;i<=nn;i++)n=n*2;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        upd(1,1,n,i,arr[i],nn);
    }
    while(q--)
    {
        cin>>p>>b;
        upd(1,1,n,p,b,nn);
        cout<<seg[1]<<endl;
    }
     return 0;
}