/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 17:45                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/208/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
vector<string>v;
map<vector<string>,int>mp;
void dfs(vector<string>a)
{
  if(mp[a])return ;
  mp[a]=1;
  int x=a.size();
  if(x==1)cout<<"YES"<<endl,exit(0);
  if(x>1&&(a[x-1][0]==a[x-2][0]||a[x-1][1]==a[x-2][1]))
  {
    vector<string>b=a;
    b[x-2]=b[x-1];
    b.pop_back();
    dfs(b);
  }
  if(x>3&&(a[x-1][0]==a[x-4][0]||a[x-1][1]==a[x-4][1]))
  {
    vector<string>b=a;
    b[x-4]=b[x-1];
    b.pop_back();
    dfs(b);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  v.resize(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  dfs(v);
  cout<<"NO"<<endl;
  return 0;
}