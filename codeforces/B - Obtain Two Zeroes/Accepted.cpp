/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/27/2019 20:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1260/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;if(a>b)swap(a,b);
     if(b>2*a)cout<<"NO\n";
    else
    {
      a+=a;if((a-b)%3==0)cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
    return 0;
}