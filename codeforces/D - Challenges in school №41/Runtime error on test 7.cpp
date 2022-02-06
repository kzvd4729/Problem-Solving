/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/09/2020 12:06                        
*  solution_verdict: Runtime error on test 7                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1333/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;string s;cin>>s;s="#"+s;
  int mx=0;vector<vector<int> >ov;
  while(true)
  {
    int f=0;vector<int>v;
    for(int i=1;i<n;i++)
    {
      if(s[i]=='R'&&s[i+1]=='L')
      {
        swap(s[i],s[i+1]);i++;
        v.push_back(i-1);mx++;f=1;
      }
    }
    if(!f)break;ov.push_back(v);
  }
  //cout<<mx<<endl;
  if(k>mx||k<ov.size())cout<<-1<<endl,exit(0);
  int f=0;
  for(auto x:ov)
  {
    if(f)
    {
      for(auto z:x)
        cout<<1<<" "<<z<<'\n',k--;
      continue;
    }
    if(mx-x.size()>=k-1)
    {
      cout<<x.size()<<" ";
      for(auto z:x)cout<<z<<" ";
        cout<<'\n';
      k--;
    }
    else
    {
      f=1;k--;
      cout<<mx-k<<" ";
      for(int i=0;i<mx-k;i++)cout<<x[i]<<" ";
        cout<<'\n';
       for(int i=mx-k;i<x.size();i++)
        cout<<1<<" "<<x[i]<<'\n',k--;
    }
  }
  assert(!k);
  return 0;
}