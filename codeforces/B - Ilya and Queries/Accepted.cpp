/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 00:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 184 ms                                          memory_used: 1100 KB                              
*  problem: https://codeforces.com/contest/313/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  for(int i=1;i<s.size();i++)
  {
    qm[i]=qm[i-1];
    if(s[i-1]==s[i])qm[i]++;
  }
  int q;cin>>q;
  while(q--)
  {
    int lt,rt;cin>>lt>>rt;
    cout<<qm[rt-1]-qm[lt-1]<<"\n";
  }
  return 0;
}