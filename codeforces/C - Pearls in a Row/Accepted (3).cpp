/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/15/2018 15:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 11000 KB                             
*  problem: https://codeforces.com/contest/620/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int n,arr[N+2];
unordered_set<int>st;
vector<pair<int,int> >ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   st.max_load_factor(0.25);
  st.reserve(1024);
   cin>>n;int lt=1;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(st.find(x)!=st.end())
    {
      st.clear();
      ans.push_back({lt,i});
      lt=i+1;
    }
    else st.insert(x);
  }
  if(st.size()&&ans.size()==0)cout<<-1<<endl,exit(0);
  cout<<ans.size()<<endl;
  ans.back().second+=st.size();
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}