/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2019 15:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1300 KB                              
*  problem: https://codeforces.com/contest/632/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e4;
string s[N+2];
bool cmp(string a,string b)
{
  return (a+b)<(b+a);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>s[i];
  sort(s+1,s+n+1,cmp);
  for(int i=1;i<=n;i++)
    cout<<s[i];
  cout<<endl;
  return 0;
}