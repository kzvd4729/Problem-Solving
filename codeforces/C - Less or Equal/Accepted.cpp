/****************************************************************************************
*  @author: * kzvd4729                                       created: May/06/2018 20:17                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 249 ms                                          memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/977/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,x,mn=2;
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    mn=min(mn,x);
    mp[x]++;
  }
  if(k==0)
  {
    if(mn==1)cout<<-1<<endl;
    else cout<<1<<endl;
    return 0;
  }
  map<int,int>::iterator it;
  int cnt=0;
  for(it=mp.begin();it!=mp.end();it++)
  {
    cnt+=(it->second);
    if(cnt==k)
    {
      cout<<it->first<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}