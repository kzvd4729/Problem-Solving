/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 18:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1175/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;k++;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    if(n==1)
    {
      cout<<aa[1]<<"\n";continue;
    }
    int lo=0,hi=1e9,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      int pt1=1,mx=1;
      for(int i=2;i<=n;i++)
      {
        if((aa[i]-aa[pt1]+1)/2<=md)
        {
          mx=max(mx,i-pt1+1);
        }
        else
        {
          pt1++;i--;
        }
      }
      if(mx>=k)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      int pt1=1,mx=1,pl=aa[1];
      for(int i=2;i<=n;i++)
      {
        if((aa[i]-aa[pt1]+1)/2<=md)
        {
          if((i-pt1+1)>mx)mx=i-pt1+1,pl=(aa[i]+aa[pt1])/2;
        }
        else
        {
          pt1++;i--;
        }
      }
      if(mx>=k){cout<<pl<<"\n";break;}
    }
  }
  return 0;
}