/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2018 15:50                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/512/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,W=26;
int in[W+2];
string ss[N+2];
void inv(void)
{
  cout<<"Impossible"<<endl;
  exit(0);
}
vector<int>adj[W+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>ss[i];
  for(int i=1;i<n;i++)
  {
    for(int j=0; ;j++)
    {
      if(j==ss[i].size())break;
      if(j==ss[i+1].size())inv();
      if(ss[i][j]==ss[i+1][j])continue;
      adj[(int)(ss[i][j]-'a')].push_back(ss[i+1][j]-'a');
      in[ss[i+1][j]-'a']++;break;
    }
  }
  set<pair<int,int> >st;
  for(int i=0;i<W;i++)
    st.insert({in[i],i});
   vector<int>ans;
  while(st.size())
  {
    pair<int,int>x=*st.begin();st.erase(x);
    if(x.first)inv();ans.push_back(x.second);
    for(auto z:adj[x.second])
    {
      if(st.find({in[z],z})!=st.end())st.erase({in[z],z});
      in[z]--;st.insert({in[z],z});
    }
  }
  for(auto x:ans)cout<<char(x+'a');
  cout<<endl;
  return 0;
}