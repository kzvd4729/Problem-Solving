/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 16:39                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/49/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
int m;
string s,s1,s2;
map<string,vector<char> >mp;
map<pair<string,string>,int>dp;
int dfs(string a,string b)
{
//  cout<<a<<" "<<b<<endl;
//  getchar();
  if(dp[{a,b}])return dp[{a,b}];
  int here=inf;
  for(int i=0;i<a.size()-1;i++)
  {
    string tmp=a.substr(i,2);
    for(auto x:mp[tmp])
    here=min(here,dfs(a.substr(0,i)+x+a.substr(i+2,a.size()-i-2),b));
  }
  for(int i=0;i<b.size()-1;i++)
  {
    string tmp=b.substr(i,2);
    for(auto x:mp[tmp])
    here=min(here,dfs(a,b.substr(0,i)+x+b.substr(i+2,b.size()-i-3)));
  }
  if(a==b)
  {
    //cout<<a<<" "<<b<<endl;
    here=min(here,(int)a.size());
  }
  return dp[{a,b}]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s1>>s2;
  cin>>m;
  while(m--)
  {
    cin>>s;
    mp[s.substr(3,2)].push_back(s[0]);
  }
  int tmp=dfs(s1,s2);
  if(tmp==inf)tmp=-1;
  cout<<tmp<<endl;
  return 0;
}