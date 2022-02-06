/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2018 15:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 31200 KB                             
*  problem: https://codeforces.com/contest/359/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[300005],l,r,mx,vis[300005];
vector<int>v[1000006];
struct segment
{
    int gc,mn;
}seg[1200000];
void build(int node,int lo,int hi)
{
    if(lo==hi)
    {
        seg[node].gc=arr[lo];
        seg[node].mn=arr[lo];
        return ;
    }
    int mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    seg[node].gc=__gcd(seg[node*2].gc,seg[node*2+1].gc);
    seg[node].mn=min(seg[node*2].mn,seg[node*2+1].mn);
 }
segment query(int node,int lo,int hi,int l,int r)
{
    if(lo>r||hi<l)return {0,9999999};
    if(lo>=l&&hi<=r)return seg[node];
    int mid=(lo+hi)/2;
    segment p1=query(node*2,lo,mid,l,r);
    segment p2=query(node*2+1,mid+1,hi,l,r);
    return {__gcd(p1.gc,p2.gc),min(p1.mn,p2.mn)};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        v[arr[i]].push_back(i);
    }
    for(int i=1;i<=1000000;i++)
    {
        int gcd;
        for(auto z:v[i])
        {
            if(vis[z])continue;
            vis[z]=1;
            l=z;
            r=z;
            gcd=i;
            for(int j=z+1;j<=n;j++)
            {
                if(arr[j]==i)vis[j]=1;
                gcd=__gcd(gcd,arr[j]);
                if(gcd<i)break;
                r=j;
            }
            gcd=i;
            for(int j=z-1;j>=1;j--)
            {
                if(arr[j]==i)vis[j]=1;
                gcd=__gcd(gcd,arr[j]);
                if(gcd<i)break;
                l=j;
            }
            mx=max(mx,r-l);
        }
    }
    build(1,1,n);
    int cnt=0;
    vector<int>print;
    for(int i=1;i<=n;i++)
    {
        if((i+mx)>n)continue;
        segment ans=query(1,1,n,i,i+mx);
        if(ans.gc==ans.mn)
        {
            cnt++;
            print.push_back(i);
        }
    }
    cout<<cnt<<" "<<mx<<endl;
    for(auto x:print)cout<<x<<" ";
    cout<<endl;
    return 0;
}