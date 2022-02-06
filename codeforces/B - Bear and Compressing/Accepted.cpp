/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/17/2018 01:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/653/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int ans,n,m;
map<string,string>mp;
void dfs(string s)
{
  if(s.size()==n)
  {
    string tmp=s;
    while(tmp.size()>1)
    {
      if(mp.find(tmp.substr(0,2))==mp.end())return ;
      tmp=mp[tmp.substr(0,2)]+tmp;
      tmp.erase(tmp.begin()+1,tmp.begin()+3);
    }
    if(tmp=="a")ans++;
    return ;
  }
  for(int i=0;i<6;i++)
  {
    string tmp=s;
    tmp.push_back(char(i+'a'));
    dfs(tmp);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    string s1,s2;cin>>s1>>s2;
    mp[s1]=s2;
  }
  dfs("");
  cout<<ans<<endl;
  return 0;
}