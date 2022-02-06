/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 21:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1154/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,b,a;cin>>n>>b>>a;
  for(int i=1;i<=n;i++)
    cin>>s[i];
  int mxa=a,ans=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i])
    {
      if(a==mxa)
      {
        a--;ans++;
      }
      else
      {
        if(b)b--,a++,ans++;
        else if(a)a--,ans++;
        else break;
      }
    }
    else
    {
      if(a)a--,ans++;
      else if(b)b--,ans++;
      else break;
    }
  }
  cout<<ans<<endl;
  return 0;
}