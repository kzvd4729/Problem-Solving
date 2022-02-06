/****************************************************************************************
*  @author: kzvd4729#                                        created: Feb/05/2020 15:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 11900 KB                             
*  problem: https://codeforces.com/gym/101873/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
map<string,int>mp;
vector<int>adj[N+2];
bool isRechable(int a,int b)
{
  if(!a||!b)return false;
  if(a==b)return true;
  int ret=0;
  for(auto x:adj[a])
    ret|=isRechable(x,b);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    string a,b,c;cin>>a>>c>>c>>c>>b;
    if(!mp[a])mp[a]=++cnt;
    if(!mp[b])mp[b]=++cnt;
    adj[mp[a]].push_back(mp[b]);
  }
  for(int i=1;i<=m;i++)
  {
    string a,b,c;cin>>a>>c>>c>>c>>b;
    if(isRechable(mp[a],mp[b]))
      cout<<"Fact\n";
    else if(isRechable(mp[b],mp[a]))
      cout<<"Alternative Fact\n";
    else cout<<"Pants on Fire\n";
  }
  return 0;
}