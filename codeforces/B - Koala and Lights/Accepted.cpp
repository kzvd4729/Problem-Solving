/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 19:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1209/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ans,aa[N+2],vis[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  for(int i=1;i<=n;i++)
  {
    int st=s[i-1]-'0';
    int a,b;cin>>a>>b;
    int pr=-1;
    for(int j=b;j<=100000;j+=a)
    {
      while(true)
      {
        if(pr==j-1)break;
        fr[++pr]+=st;
      }
      st^=1;
    }
  }
  int ans=0;
  for(int i=0;i<=N;i++)
    ans=max(ans,fr[i]);
  cout<<ans<<endl;
  return 0;
}