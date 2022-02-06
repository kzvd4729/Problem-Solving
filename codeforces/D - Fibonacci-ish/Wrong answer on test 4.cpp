/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 18:51                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/633/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int aa[N+2];
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];mp[aa[i]]++;
  }
  sort(aa+1,aa+n+1);int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      vector<int>v;int cnt=2,f0=aa[i],f1=aa[j];
      mp[f0]--;mp[f1]--;
      v.push_back(f0);v.push_back(f1);
      while(true)
      {
        if(f0==0&&f1==0)
        {
          cnt+=mp[0];break;
        }
        if(mp[f0+f1])
        {
          int f=f0+f1;mp[f]--;
          f0=f1;f1=f;v.push_back(f);
          cnt++;
        }
        else break;
      }
      for(auto x:v)mp[x]++;
      ans=max(ans,cnt);
    }
  }
  cout<<ans<<endl;
  return 0;
}