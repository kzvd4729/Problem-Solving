/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2019 21:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1207/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,a,b;cin>>n>>a>>b;
    string s;cin>>s;
    long ans=1LL*b*(s.size()+1);
    int id=0;
    while(id<s.size())
    {
      if(s[id]=='1')break;
      id++;
    }
    ans+=1LL*a*(id+1);
    if(id>=s.size())
    {
      ans-=a;cout<<ans<<"\n";continue;
    }
    int zero=0;
    for(int i=id;i<s.size();i++)
    {
      if(s[i]=='1')
      {
        if(zero)
          ans+=min(1LL*a*(zero+2),1LL*b*(zero-1)+1LL*a*zero);
        ans+=a+b;zero=0;
        if(s[i+1]=='0')ans+=b;
      }
      else zero++;
     }
    ans+=1LL*a*(zero+1);
    cout<<ans<<"\n";
  }
  return 0;
}