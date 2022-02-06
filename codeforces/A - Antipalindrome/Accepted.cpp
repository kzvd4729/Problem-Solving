/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2018 21:03                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/981/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int ans;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
   for(int i=0;i<s.size();i++)
  {
    for(int j=i;j<s.size();j++)
    {
      int f=0;
      for(int k=i,kk=j;k<=j,kk>=i;k++,kk--)
      {
        if(s[k]!=s[kk])f=1;
      }
      if(f)ans=max(ans,j-i+1);
    }
  }
  cout<<ans<<endl;
  return 0;
}