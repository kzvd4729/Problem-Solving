/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/12/2018 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1076/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,f=-1;cin>>n;
  string s;cin>>s;
  for(int i=0;i<n-1;i++)
  {
    if(s[i]>s[i+1])
    {
      f=i;break;
    }
  }
  if(f==-1)f=n-1;
  for(int i=0;i<n;i++)
  {
    if(i==f)continue;
    cout<<s[i];
  }
  cout<<endl;
  return 0;
}