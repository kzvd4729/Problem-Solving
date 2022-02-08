/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-29 19:36:55                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 176 ms                                          memory_used: 9028 KB                              
*  problem: https://atcoder.jp/contests/arc103/tasks/arc103_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int nd=2;
string s;vector<int>v;
vector<pair<int,int> >ed;
void inv(void)
{
  cout<<-1<<endl,exit(0);
}
void dfs(int node,int sz,int pt)
{
  if(sz==1)return ;sz--;
  while(sz)
  {
    while(pt>=0&&v[pt]<=sz)
    {
      ++nd;ed.push_back({node,nd});
      dfs(nd,v[pt],pt-1);sz-=v[pt];
    }
    pt--;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s;
  if(s.back()=='1'||s[0]=='0')inv();
  for(int i=0;i<s.size()-1;i++)
  {
    if(s[i]=='0')continue;
    if(s[s.size()-i-2]!='1')inv();
    v.push_back(i+1);
  }
  ed.push_back({1,2});
  dfs(2,v.back(),v.size()-2);
  for(auto x:ed)
  {
    cout<<x.first<<" "<<x.second<<endl;
  }
  return 0;
}