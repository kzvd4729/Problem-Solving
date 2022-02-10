/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-30 19:56:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 400                                        memory_used (MB): 25.6                            
*  problem: https://vjudge.net/problem/SPOJ-GSS1
****************************************************************************************/
#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
long long int n,arr[50005],q,i,l,r;
struct segment
{
    long long int left;
    long long int right;
    long long int msum;
    long long int tot;
}seg[50004*6];
void build(long long int node,long long int lo,long long int hi)
{
    if(lo==hi)
    {
        seg[node].left=arr[lo];
        seg[node].right=arr[lo];
        seg[node].msum=arr[lo];
        seg[node].tot=arr[lo];
        return ;
    }
    long long int mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    seg[node].left=max(seg[node*2].left,seg[node*2].tot+seg[node*2+1].left);
    seg[node].right=max(seg[node*2+1].right,seg[node*2+1].tot+seg[node*2].right);
    seg[node].msum=max(seg[node].left,max(seg[node].right,max(seg[node*2].msum,max(seg[node*2+1].msum,seg[node*2].right+seg[node*2+1].left))));
    seg[node].tot=seg[node*2].tot+seg[node*2+1].tot;
}
segment query(long long int node,long long int lo,long long int hi,long long int l,long long int r)
{
    if(lo>r||hi<l)
    {
        segment ret;
        ret.left=-inf;
        ret.right=-inf;
        ret.msum=-inf;
        ret.tot=-inf;
        return ret;
    }
    if(lo>=l&&hi<=r)
    {
        return seg[node];
    }
    long long int mid=(lo+hi)/2;
    segment p1=query(node*2,lo,mid,l,r);
    segment p2=query(node*2+1,mid+1,hi,l,r);
    segment tmp;
    tmp.left=max(p1.left,p1.tot+p2.left);
    tmp.right=max(p2.right,p2.tot+p1.right);
    tmp.msum=max(tmp.left,max(tmp.right,max(p1.msum,max(p2.msum,p1.right+p2.left))));
    tmp.tot=p1.tot+p2.tot;
    return tmp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        segment ans=query(1,1,n,l,r);
        cout<<ans.msum<<endl;
    }
    return 0;
}