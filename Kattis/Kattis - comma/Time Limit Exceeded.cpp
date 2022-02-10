/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-24 20:38:30                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-comma
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],n,pre[N+2],con[N+2];
string kk[N+2],tt[N+2];
map<string,int>mp;vector<int>adj[N+2];
void dfs(int i)
{
  if(vis[i])return ;vis[i]=1;
  for(auto x:adj[con[i]])
  {
    if(kk[x].back()=='.'||x==n)continue;
    dfs(x);
  }
  if(pre[i+1])return ;
  for(auto x:adj[con[i+1]])
  {
    if(kk[x-1].back()=='.')continue;
    dfs(x-1);
  }
  pre[i+1]=1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;getline(cin,s);

  n=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]!=' ')
    {
      string k;
      while(s[i]!=' '&&i<s.size())
        k.push_back(s[i++]);
      kk[++n]=k;
    }
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    string tmp=kk[i];
    if(tmp.back()=='.'||tmp.back()==',')
      tmp.pop_back();
    tt[i]=tmp;
    if(!mp[tmp])mp[tmp]=++cnt;
    con[i]=mp[tmp];adj[con[i]].push_back(i);
  }
  for(int i=1;i<=n;i++)
  {
    if(kk[i].back()==',')
      dfs(i);
  }
  cnt=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]!=' ')
    {
      cnt++;cout<<kk[cnt];
      if(vis[cnt]&&kk[cnt].back()!=',')cout<<",";
      i+=kk[cnt].size()-1;
    }
    else cout<<s[i];
  }
  cout<<endl;
  return 0;
}