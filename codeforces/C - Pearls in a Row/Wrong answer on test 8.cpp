/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/15/2018 14:58                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/620/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int n,arr[N+2];
set<int>st;
vector<pair<int,int> >ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
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
  if(st.size())cout<<-1<<endl,exit(0);
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}