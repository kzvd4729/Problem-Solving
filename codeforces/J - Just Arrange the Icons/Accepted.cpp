/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2019 14:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 592 ms                                          memory_used: 20200 KB                             
*  problem: https://codeforces.com/contest/1267/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;
int fr[N+2];
int cal(int n,int k)
{
  int sgn=0;
  if(n%k==0)sgn=1;
  if(n%(k-1)==0)sgn=1;
  if(n/k!=n/(k-1))sgn=1;
   if(sgn==0)return -1;
  return (n+k-1)/k;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)fr[i]=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;fr[x]++;
    }
    vector<int>v;
    for(int i=1;i<=n;i++)
      if(fr[i])v.push_back(fr[i]);
    sort(v.begin(),v.end());
     // for(auto x:v)
    //   cout<<x<<" ";
    // cout<<endl;
     int ans=inf;
    for(int k=2;k<=v[0]+1;k++)
    {
      int f=0,sm=0;
      for(auto x:v)
      {
        int ret=cal(x,k);
        if(ret==-1)f=1;else sm+=ret;
      }
      if(!f)ans=min(ans,sm);
    }
    cout<<ans<<"\n";
  }
  return 0;
}