/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 18:11                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 100 KB                               
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
    cin>>aa[i];
    mp[aa[i]]=1;
  }
  sort(aa+1,aa+n+1);int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      int f0=aa[i],f1=aa[j];
      int cnt=2;
      while(true)
      {
        if(mp[f0+f1])
        {
          cnt++;
          int f=f1+f0;
          f0=f1;f1=f;
        }
        else break;
      }
      ans=max(ans,cnt);
    }
  }
  cout<<ans<<endl;
  return 0;
}