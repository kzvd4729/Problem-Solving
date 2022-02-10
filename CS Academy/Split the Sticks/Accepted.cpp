/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 312 ms                                          memory_used: 6508 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x,y;
set<int>st;
vector<pair<int,int> >ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    x=-x;
    if(st.find(x)!=st.end())
      st.erase(x);
    else st.insert(x);
  }
  while(st.size())
  {
    if(st.size()==1)
    {
      x=*st.begin();
      st.erase(x);
      x=-x;
      if(x%2)cout<<-1<<endl,exit(0);
      ans.push_back({x,x/2});
      break;
    }
    x=*st.begin();
    st.erase(x);
    x=-x;
    y=*st.begin();
    st.erase(y);
    y=-y;
    x-=y;
    ans.push_back({x+y,y});
    x=-x;
    if(st.find(x)!=st.end())
      st.erase(x);
    else st.insert(x);
  }
  if(ans.size()>n)cout<<-1<<endl,exit(0);
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}