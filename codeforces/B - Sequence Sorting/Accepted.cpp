/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2019 15:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 10400 KB                             
*  problem: https://codeforces.com/contest/1240/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int lft[N+2],rgt[N+2],fr[N+2],aa[N+2];
int compress(int n)
{
  map<int,int>mp;int cnt=0;
  for(int i=1;i<=n;i++)mp[aa[i]];
  for(auto &x:mp)x.second=++cnt;
  for(int i=1;i<=n;i++)aa[i]=mp[aa[i]];
  return mp.size();
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    int sz=compress(n);
    for(int i=1;i<=n;i++)
    {
      if(!lft[aa[i]])lft[aa[i]]=i;
      rgt[aa[i]]=i;
    }
    int mx=0;
    for(int i=1;i<=sz; )
    {
      int pt=0,ln=0;
      for( ;i+ln<=sz;ln++)
      {
        if(lft[i+ln]<pt)break;
        pt=rgt[i+ln];
      }
      mx=max(mx,ln);i+=ln;
    }
    cout<<sz-mx<<"\n";
     for(int i=1;i<=sz;i++)fr[i]=0,lft[i]=0;
  }
  return 0;
}