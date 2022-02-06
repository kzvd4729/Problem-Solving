/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2018 17:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 10400 KB                             
*  problem: https://codeforces.com/contest/1041/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=2e9;
int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,d;cin>>n>>m>>d;
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    st.insert({x,i});
  }
  st.insert({inf,inf});
  int day=1,tm=0;
  while(true)
  {
    if(st.size()==1)break;
    pair<int,int>p=*st.upper_bound({tm+1,-1});
    if(p.first==inf)day++,tm=0;
    else
    {
      st.erase(p);tm=p.first+d;
      ans[p.second]=day;
    }
  }
  cout<<day<<endl;
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}