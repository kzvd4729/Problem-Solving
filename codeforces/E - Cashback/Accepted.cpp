/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2018 19:32                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 7300 KB                              
*  problem: https://codeforces.com/contest/940/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=9999999999999999;
long seg[400005],arr[100005],l,r,n,c,dp[100005],qm[100005];
void build(long node,long lo,long hi)
{
    if(lo==hi)
    {
        seg[node]=arr[lo];
        return ;
    }
    long mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    seg[node]=min(seg[node*2],seg[node*2+1]);
}
long query(long node,long lo,long hi,long l,long r)
{
    long mid=(lo+hi)/2;
    if(lo>r||hi<l)return inf;
    if(lo>=l&&hi<=r)return seg[node];
    return min(query(node*2,lo,mid,l,r),query(node*2+1,mid+1,hi,l,r));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>c;
    for(long i=1;i<=n;i++)cin>>arr[i],qm[i]=qm[i-1]+arr[i];
    build(1,1,n);
     for(int i=1;i<=n;i++)dp[i]=inf;
    dp[0]=0;
    for(long i=1;i<c;i++)dp[i]=qm[i];
    for(long i=c;i<=n;i++)dp[i]=min(dp[i-1]+arr[i],dp[i-c]+qm[i]-qm[i-c]-query(1,1,n,i-c+1,i));
    cout<<dp[n]<<endl;
    return 0;
}