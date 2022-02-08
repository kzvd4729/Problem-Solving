/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 18:08:19                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 512 KB                               
*  problem: https://atcoder.jp/contests/abc143/tasks/abc143_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  char l='A';int cnt=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=l)cnt++;
    l=s[i];
  }
  cout<<cnt<<endl;
  return 0;
}