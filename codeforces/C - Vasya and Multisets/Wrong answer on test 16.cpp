/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2018 22:46                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1051/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
char ans[N+2];
vector<int>pos[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;pos[x].push_back(i);
  }
  int s1=0,s2=0;
  for(int i=1;i<=N;i++)
  {
    if(pos[i].size()==1)
    {
      if(s1<s2)
      {
        ans[pos[i][0]]='A';
        s1++;
      }
      else
      {
        ans[pos[i][0]]='B';
        s2++;
      }
    }
  }
  for(int i=1;i<=N;i++)
  {
    if(pos[i].size()==2)
    {
      ans[pos[i][0]]='A';
      ans[pos[i][1]]='B';
    }
  }
  for(int i=1;i<=N;i++)
  {
    if(pos[i].size()==3)
    {
      if(s1<s2)
      {
        ans[pos[i][0]]='A';
        ans[pos[i][1]]='B';
        ans[pos[i][2]]='B';
        s1++;
      }
      else
      {
        ans[pos[i][0]]='B';
        ans[pos[i][1]]='A';
        ans[pos[i][2]]='A';
        s2++;
      }
    }
  }
  for(int i=1;i<=N;i++)
  {
    if(pos[i].size()>3)
    {
      if(s1==s2)
      {
        for(auto x:pos[i])
          ans[x]='A';
      }
      else if(s1<s2)
      {
        ans[pos[i][0]]='A';
        for(int j=1;j<pos[i].size();j++)
          ans[pos[i][j]]='B';
        s1++;
      }
      else
      {
        ans[pos[i][0]]='B';
        for(int j=1;j<pos[i].size();j++)
          ans[pos[i][j]]='A';
        s2++;
      }
    }
  }
  if(s1!=s2)cout<<"NO"<<endl,exit(0);
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
  {
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}