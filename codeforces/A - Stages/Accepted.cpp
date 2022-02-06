/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2018 15:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1011/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  cin>>s;
  sort(s.begin(),s.end());
   int ans=0;
  int pr=0;
  for(auto x:s)
  {
    if(k==0)break;
    if((int)x-pr>1)
    {
      pr=(int)x;
      ans+=pr;
      ans-=(int)'a'-1;
      k--;
    }
  }
  if(k)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}