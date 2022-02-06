/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2018 18:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/998/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x,y,cnt,z;
long ans;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>x>>y;
  cin>>s;
  s.push_back('1');
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='0')z=1;
    if(s[i]=='1')
    {
      if(z)
      {
        cnt++;
        z=0;
      }
    }
  }
  ans=1e17;
  for(int i=1;i<=cnt;i++)
    ans=min(ans,y*1LL*i+(cnt-i)*1LL*x);
  if(ans==1e17)ans=0;
  cout<<ans<<endl;
   return 0;
}