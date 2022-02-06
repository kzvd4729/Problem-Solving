/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2018 22:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/723/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int cnt,mx,ins,n;
bool pr;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  cin>>s;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='(')
    {
      mx=max(mx,cnt);
      cnt=0;
      pr=true;
      continue;
    }
    if(s[i]==')')
    {
      if(cnt)ins++;
      cnt=0;
      pr=false;
      continue;
    }
    if(s[i]=='_')
    {
      if(pr&&cnt)
      {
        ins++;
        cnt=0;
        continue;
      }
      mx=max(mx,cnt);
      cnt=0;
      continue;
    }
    cnt++;
  }
  cout<<max(mx,cnt)<<" "<<ins<<endl;
  return 0;
}