/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2020 02:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/634/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int d,n,m;cin>>d>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+m+1);
    deque<pair<int,int> >dq;
  dq.push_back({0,0});
   // for(int i=1;i<=m;i++)
  //   cout<<pp[i].first<<" ** "<<pp[i].second<<endl;
   long ans=0;int cv=0;
  pp[m+1]={d,0};
  for(int i=1;i<=m+1;i++)
  {
    while(dq.size())
    {
      if(dq.front().first+n<pp[i].first)
      {
        ans+=1LL*(dq.front().first+n-cv)*dq.front().second;
        cv=dq.front().first+n;dq.pop_front();
      }
      else break;
    }
    if(dq.size()==0)cout<<-1<<endl,exit(0);
    ans+=1LL*(pp[i].first-cv)*dq.front().second;
    cv=pp[i].first;
     while(dq.size())
    {
      if(dq.back().second>=pp[i].second)dq.pop_back();
      else break;
    }
    dq.push_back(pp[i]);
  }
  cout<<ans<<endl;
  return 0;
}