/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-10 18:09:00                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc150/tasks/abc150_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,cnt=0;cin>>n;string s;cin>>s;
  for(int i=2;i<n;i++)
    if(s[i-2]=='A'&&s[i-1]=='B'&&s[i]=='C')cnt++;
  cout<<cnt<<endl;
    return 0;
}