/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 18:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1105/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  string s;cin>>s;int ans=0;
   for(char c='a';c<='z';c++)
  {
    int cnt=0,fr=0;
    for(auto x:s)
    {
      if(x==c)cnt++;
      else cnt=0;
       if(cnt==k)
      {
        cnt=0;fr++;
      }
    }
    ans=max(ans,fr);
  }
  cout<<ans<<endl;
  return 0;
}