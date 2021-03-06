/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2019 00:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1166/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
string s="aeiou";
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>k;int f=0;int row=-1,col=-1;
  for(int i=1;i<=k;i++)
  {
    if(k%i)continue;
    int j=k/i;
    if(i>=5&&j>=5)row=i,col=j;
  }
  if(row==-1)cout<<-1<<endl,exit(0);
   int r=0;string ans;
  for(int i=0;i<row;i++)
  {
    int c=r;
    for(int j=0;j<col;j++)
    {
      ans.push_back(s[c]);
      c=(c+1)%5;
    }
    r=(r+1)%5;
  }
  cout<<ans<<endl;
  return 0;
}