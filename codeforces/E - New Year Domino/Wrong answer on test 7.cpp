/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2018 14:51                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 2300 KB                              
*  problem: https://codeforces.com/contest/500/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e9+9;
int seg[N+2],id,lk[N+2];
long jo[N+2];
pair<int,int>arr[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;
 for(int i=1;i<=n;i++)cin>>arr[i].first>>arr[i].second;
 int mx=arr[1].second;
 for(int i=2;i<=n;i++)
 {
  mx-=(arr[i].first-arr[i-1].first);
  if(mx<0)
  {
   ++id;seg[id]=i-1;
   jo[id]=-mx;jo[id]+=jo[id-1];
  }
  mx=max(mx,arr[i].second);
 }
 seg[++id]=n;jo[id]=0;
 for(int i=1,j=1;i<=n;i++)
 {
  if(i>seg[j])j++;
  lk[i]=j;
 }
 /*for(int i=1;i<=n;i++)
  cout<<lk[i]<<" "<<jo[i]<<" "<<endl;
 cout<<endl;*/
   int q;cin>>q;
 while(q--)
 {
  int u,v;cin>>u>>v;
  u=lk[u],v=lk[v];
  cout<<jo[v-1]-jo[u-1]<<endl;
 } 
 return 0;
}