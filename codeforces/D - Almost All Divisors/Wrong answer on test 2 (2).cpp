/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2019 21:29                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 951 ms                                          memory_used: 94600 KB                             
*  problem: https://codeforces.com/contest/1165/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>dv[N+2];
void divisors(void)
{
  for(int i=2;i<=N;i++)
  {
    for(int j=i+i;j<=N;j+=i)
      dv[j].push_back(i);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;divisors();
  while(t--)
  {
    int n;cin>>n;vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());int ans=-1;
    for(int i=2;i<=N;i++)
    {
      if(v.size()!=dv[i].size())continue;
      int f=0;
      for(int j=0;j<n;j++)
      {
        if(v[j]!=dv[i][j])
        {
          f=1;break;
        }
      }
      if(!f)
      {
        ans=i;break;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}