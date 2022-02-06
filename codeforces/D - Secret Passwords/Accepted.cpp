/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/29/2019 21:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 85200 KB                             
*  problem: https://codeforces.com/contest/1263/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
string s;int vis[N+2],mark[N+2];
vector<int>adj[N+2];
void dfs(int node)
{
  mark[node]=1;
  for(auto x:adj[node])
    if(!mark[x])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>s;sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
        for(int j=0;j<s.size();j++)
    {
      vis[s[j]-'a']=1;
      for(int k=0;k<s.size();k++)
      {
        adj[s[j]-'a'].push_back(s[k]-'a');
        //cout<<s[j]-'a'<<" "<<s[k]-'a'<<endl;
      }
    }
  }
  int cnt=0;
  for(int i=0;i<26;i++)
  {
    if((!vis[i])||(mark[i]))continue;
    //cout<<i<<endl;
    dfs(i);cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}