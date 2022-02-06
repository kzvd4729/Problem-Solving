/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 19:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1176/problem/B
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
    int n;cin>>n;int ans=0,a=0,b=0;
    for(int i=0;i<n;i++)
    {
      int x;cin>>x;
      if(x%3==0)ans++;
      else if(x%3==1)a++;
      else b++;
    }
    int m=min(a,b);ans+=m;a-=m,b-=m;
    cout<<ans+a/3+b/3<<"\n";
  }
  return 0;
}