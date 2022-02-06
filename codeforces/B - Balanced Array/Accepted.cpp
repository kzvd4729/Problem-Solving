/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1343/problem/B
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
    int n;cin>>n;
    if(n%4){cout<<"NO\n";continue;}
    cout<<"YES\n";
    int in=2;
    for(int i=1;i<=n/2;i++)
    {
      cout<<in<<" ";in+=2;
    }
    in=1;
    for(int i=1;i<=n/4;i++)
    {
      cout<<in<<" ";in+=2;
    }
    in+=2;
    for(int i=1;i<=n/4;i++)
    {
      cout<<in<<" ";in+=2;
    }
    cout<<endl;
  }
  return 0;
}