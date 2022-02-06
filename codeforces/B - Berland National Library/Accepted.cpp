/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/17/2018 22:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 12700 KB                             
*  problem: https://codeforces.com/contest/567/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],arr[N+2],x,cur,ans,n,bf[N+2];
char c[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>c[i]>>arr[i];
    if(c[i]=='+')vis[arr[i]]=1;
    else
    {
      if(vis[arr[i]])
        vis[arr[i]]=0;
      else cur++;
    }
  }
  ans=cur;
  for(int i=1;i<=n;i++)
  {
    if(c[i]=='+')cur++;
    else cur--;
    ans=max(ans,cur);
  }
  cout<<ans<<endl;
  return 0;
}