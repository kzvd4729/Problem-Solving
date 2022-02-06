/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2018 22:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 795 ms                                          memory_used: 24200 KB                             
*  problem: https://codeforces.com/contest/1017/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,m,q,vl[N+2],sm;
int cnt[N+2],sum[N+2];
long ans[(1<<13)][102];
string s[N+2],ss;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>q;
  for(int i=0;i<n;i++)
    cin>>vl[i];
  for(int i=0;i<m;i++)
  {
    cin>>s[i];int msk=0;
    for(int j=0;j<s[i].size();j++)
    {
      if(s[i][j]=='1')msk|=(1<<j);
    }
    cnt[msk]++;
  }
  for(int i=0;i<(1<<n);i++)
  {
    for(int j=0;j<n;j++)
      if(i&(1<<j))sum[i]+=vl[j];
  }
  for(int msk=0;msk<(1<<n);msk++)
  {
    for(int mt=0;mt<(1<<n);mt++)
    {
      int mth=0;
      for(int j=0;j<n;j++)
      {
        bool on=(msk&(1<<j)),tw=(mt&(1<<j));
        if(on==tw)mth|=(1<<j);
      }
      if(sum[mth]<=100)ans[msk][sum[mth]]+=(cnt[mt]*1LL);
    }
  }
  while(q--)
  {
    cin>>ss>>sm;int msk=0;long pr=0;
    for(int j=0;j<ss.size();j++)
    {
      if(ss[j]=='1')msk|=(1<<j);
    }
    for(int i=0;i<=sm;i++)
      pr+=(ans[msk][i]*1LL);
    cout<<pr<<"\n";
  }
  return 0;
}