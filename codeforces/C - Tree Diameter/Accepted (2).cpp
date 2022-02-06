/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/21/2019 16:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1146/problem/C
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
    cout<<1<<" "<<n-1<<" "<<1<<" ";
    for(int i=2;i<=n;i++)
      cout<<i<<" ";
    cout<<endl;
    int ds;cin>>ds;
     int lo=2,hi=n;
     while(lo<hi)
    {
      int md=(lo+hi)/2;
      cout<<1<<" "<<md-lo+1<<" "<<1<<" ";
      for(int i=lo;i<=md;i++)
        cout<<i<<" ";
      cout<<endl;
      int x;cin>>x;
      if(x==ds)hi=md;
      else lo=md+1;
    }
    cout<<1<<" "<<n-1<<" "<<lo<<" ";
    for(int i=1;i<=n;i++)
    {
      if(i==lo)continue;
      cout<<i<<" ";
    }
    cout<<endl;
    int x;cin>>x;
    cout<<-1<<" "<<x<<endl;
  }
  return 0;
}