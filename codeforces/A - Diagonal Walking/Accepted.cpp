/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2018 16:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/954/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,cnt;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  cin>>s;
  for(int i=0;i<n-1;i++)if((s[i]=='U'&&s[i+1]=='R')||(s[i]=='R'&&s[i+1]=='U'))i++,cnt++;
  cout<<n-cnt<<endl;
  return 0;
}