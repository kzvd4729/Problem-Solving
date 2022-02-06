/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 22:24                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 52800 KB                             
*  problem: https://codeforces.com/contest/1176/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,bb[N+2],cc[N+2];long dp[N+2][12],aa[N+2];
long dfs(long id,long m)
{
  if(id>n)return 0;
  if(dp[id][m]!=-1)return dp[id][m];
  vector<long>v;
  for(long i=aa[id-1]+1;i<=aa[id];i++)
    if(bb[i]==1)v.push_back(cc[i]);
  sort(v.begin(),v.end(),greater<long>());
  long now=0;
  if(v.size()>=3)
  {
    if(m>=7)now=max(now,v[0]+v[0]+v[1]+v[2]+dfs(id+1,(m+3)%10));
    else now=max(now,v[0]+v[1]+v[2]+dfs(id+1,(m+3)%10));
  }
  long mx=-1;
  for(long i=aa[id-1]+1;i<=aa[id];i++)
    if(bb[i]==2)mx=max(mx,cc[i]);
  if(mx>=0&&v.size()>=1||v.size()>=2)
  {
    long a=v[0],b=-1;
    if(v.size()>1)b=v[1];
    if(a<mx)swap(a,mx);if(b<mx)swap(b,mx);
    if(m>=8)now=max(now,a+a+b+dfs(id+1,(m+2)%10));
    else now=max(now,a+b+dfs(id+1,(m+2)%10));
  }
  long mx2=-1;
  for(long i=aa[id-1]+1;i<=aa[id];i++)
    if(bb[i]==3)mx2=max(mx2,cc[i]);
  mx2=max(mx2,mx);
  if(v.size()>=1)mx2=max(mx2,v[0]);
  if(mx2!=-1)
  {
    if(m>=9)now=max(now,mx2+mx2+dfs(id+1,(m+1)%10));
    else now=max(now,mx2+dfs(id+1,(m+1)%10));
  }
  return dp[id][m]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];aa[i]+=aa[i-1];
    for(long j=aa[i-1]+1;j<=aa[i];j++)
      cin>>bb[j]>>cc[j];
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}