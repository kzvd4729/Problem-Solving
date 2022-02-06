/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/14/2018 22:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 35500 KB                             
*  problem: https://codeforces.com/contest/818/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,x,cnt[N+2];
set<pair<int,int> >st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>x;
  for(int i=1;i<=N;i++)
  {
    if(i==x)continue;
    st.insert({0,i});
  }
  for(int i=1;i<=n;i++)
  {
    int tm;cin>>tm;
    if(tm==x)
    {
      cnt[x]++;
      while(true)
      {
        if(st.size()==0)cout<<-1<<endl,exit(0);
        if((*st.begin()).first<cnt[x])st.erase(*st.begin());
        else break;
      }
    }
    else
    {
      if(st.find({cnt[tm],tm})!=st.end())
      {
        st.erase({cnt[tm],tm});
        st.insert({++cnt[tm],tm});
      }
    }
  }
  cout<<(*st.begin()).second<<endl;
  return 0;
}