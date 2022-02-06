/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/18/2019 01:02                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/575/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int aa[N+2],bb[N+2];
long dp[2][N+N+3];
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p;cin>>n>>p;
  for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
   vector<int>v;v.push_back(p);
  for(int i=1;i<=n;i++)v.push_back(aa[i]),v.push_back(bb[i]);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   int m=v.size();
  for(int i=0;i<m;i++)
  {
    dp[0][i]=1e15;
    if(v[i]==p)dp[0][i]=0;
  }
  P(v);
  bool pr=0,nw=1;
  for(int i=1;i<=n;i++)
  {
    long mn=1e15;
    for(int j=0;j<m;j++)
    {
      int ad;
      if(v[j]>=aa[i]&&v[j]<=bb[i])ad=0;
      else ad=min(abs(v[j]-aa[i]),abs(v[j]-bb[i]));
       mn=min(mn+1,dp[pr][j]);
      dp[nw][j]=mn+ad;
    }
    mn=1e15;
    for(int j=m-1;j>=0;j--)
    {
      int ad;
      if(v[j]>=aa[i]&&v[j]<=bb[i])ad=0;
      else ad=min(abs(v[j]-aa[i]),abs(v[j]-bb[i]));
       mn=min(mn+1,dp[pr][j]);
      dp[nw][j]=min(dp[nw][j],mn+ad);
    }
    for(int j=0;j<m;j++)
      cout<<dp[nw][j]<<" ";
    cout<<endl;
    swap(pr,nw);
  }
  long ans=1e15;
  for(int j=0;j<m;j++)
    ans=min(ans,dp[pr][j]);
  cout<<ans<<endl;
  return 0;
}