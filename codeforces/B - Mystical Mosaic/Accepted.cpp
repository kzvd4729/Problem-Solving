/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 19:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/957/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,vis[52];
char mat[52][52];
vector<int>v;
string s;
map<string,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=s[j-1];
    }
  }
  for(int i=1;i<=n;i++)
  {
    v.clear();
    for(int j=1;j<=m;j++)if(mat[i][j]=='#')v.push_back(j);
    int f=0;
    string tmp;
    for(auto x:v)
    {
      if(vis[x])f=1;
      vis[x]=1;
      tmp.push_back((char)(x+'0'));
    }
    ///cout<<tmp<<endl;
    if(mp[tmp])continue;
    mp[tmp]=1;
    if(f==1)cout<<"No"<<endl,exit(0);
  }
  cout<<"Yes"<<endl;
  return 0;
}