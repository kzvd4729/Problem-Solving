/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2019 21:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1251/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sz[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int f=0,zero=0,one=0;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;sz[i]=s.size();
      for(auto x:s)
      {
        if(x=='0')zero++;
        else one++;
      }
      if(sz[i]%2)f=1;
    }
    if(!f&&zero%2)cout<<n-1<<"\n";
    else cout<<n<<"\n";
  }
  return 0;
}