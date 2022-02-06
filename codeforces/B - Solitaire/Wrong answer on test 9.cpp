/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 17:42                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
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
  int x=a.size();
  if(x==1)cout<<"YES"<<endl,exit(0);
  if(x>1&&(a[x-1][0]==a[x-2][0]||a[x-1][1]==a[x-2][1]))
  {
    vector<string>b=a;
    b[x-2]=v[x-1];
    b.pop_back();
    dfs(b);
  }
  if(x>3&&(a[x-1][0]==a[x-4][0]||a[x-1][1]==a[x-4][1]))
  {
    vector<string>b=a;
    b[x-4]=v[x-1];
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