/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 01:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1075/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  vector<int>vr,hr;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;vr.push_back(x);
  }
  vr.push_back(1000000000);
  sort(vr.begin(),vr.end());
  for(int i=1;i<=m;i++)
  {
    int x1,x2,y;cin>>x1>>x2>>y;
    if(x1==1)
    {
      hr.push_back(x2);
    }
  }
  sort(hr.begin(),hr.end());
   if(hr.size()==0)cout<<0<<endl,exit(0);
   int ans=1e9,cnt=0;
  for(auto x:vr)
  {
    int id=lower_bound(hr.begin(),hr.end(),x)-hr.begin();
     ans=min(ans,(int)hr.size()-id+cnt);
    cnt++;
  }
  cout<<ans<<endl;
  return 0;
}