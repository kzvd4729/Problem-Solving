/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/23/2019 18:27                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 184300 KB                            
*  problem: https://codeforces.com/contest/117/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
vector<int>in[N+2],out[N+2];
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)
    cin>>s[i];
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]=='1')
      {
        out[i].push_back(j);
        in[j].push_back(i);
      }
    }
  }
  vector<int>v;
  for(int i=0;i<n;i++)v.push_back(i);
  random_shuffle(v.begin(),v.end());
  for(int i=0;i<n;i++)
  {
    for(auto x:in[v[i]])
    {
      for(auto z:out[v[i]])
      {
        if(s[z][x]=='1')
          cout<<v[i]+1<<" "<<z+1<<" "<<x+1<<endl,exit(0);
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}