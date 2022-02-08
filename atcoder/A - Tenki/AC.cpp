/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-01 18:10:59                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc139/tasks/abc139_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
  int cnt=0;
  for(int i=0;i<a.size();i++)
    if(a[i]==b[i])cnt++;
  cout<<cnt<<endl;
  return 0;
}