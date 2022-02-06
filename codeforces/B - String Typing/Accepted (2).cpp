/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2018 17:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/954/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,ans,cnt;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
  ans=1;
  for(int i=0;i<n;i++)
  {
    ///s.push_back('@');
    cnt=0;
    int f=0;
    for(int j=0;j<i;j++)
    {
      if(s[j]==s[i+j])cnt++;
      else
      {
        f=1;
        break;
      }
    }
    if(!f)ans=max(ans,cnt);
  }
  cout<<n-ans+1<<endl;
  return 0;
}