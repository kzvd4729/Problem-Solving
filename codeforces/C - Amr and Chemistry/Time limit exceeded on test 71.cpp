/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 17:00                        
*  solution_verdict: Time limit exceeded on test 71          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/558/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int fr[N+2],ans[N+2],aa[N+2];
unordered_map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=n;i++)
  {
    mp.clear();
    int x=aa[i];int cnt=0;
    while(x)
    {
      mp[x]=cnt;
      int y=x;int cntt=cnt;
      while(y<=N/2)
      {
        y*=2;cntt++;
        if(mp[y])
          mp[y]=min(mp[y],cntt);
        else mp[y]=cntt;
      }
      x/=2;cnt++;
    }
    mp[aa[i]]=0;
    for(auto x:mp)
    {
      fr[x.first]++,ans[x.first]+=x.second;
    }
  }
  int pr=1e9;
  for(int i=1;i<=N;i++)
    if(fr[i]==n)pr=min(pr,ans[i]);
  cout<<pr<<endl;
  return 0;
}