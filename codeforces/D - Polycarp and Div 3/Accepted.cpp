/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/09/2018 21:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1005/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int last[3];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  int sum=0,ans=0;
  last[1]=-1;
  last[2]=-1;
  for(int i=1;i<=s.size();i++)
  {
    int x=s[i-1]-'0';
    sum=(sum+x)%3;
    if(last[sum]>=last[0])
    {
      ans++;
      sum=0;
    }
    last[sum]=i;
  }
  cout<<ans<<endl;
  return 0;
}