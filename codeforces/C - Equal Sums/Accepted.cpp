/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/01/2018 21:02                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 156 ms                                          memory_used: 12100 KB                             
*  problem: https://codeforces.com/contest/988/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int k,n,x,arr[N+2];
map<int,pair<int,int> >mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>k;
  for(int kk=1;kk<=k;kk++)
  {
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
      sum+=arr[i];
    }
    for(int i=1;i<=n;i++)
    {
      int tmp=sum-arr[i];
      if(mp.find(tmp)!=mp.end())
      {
        pair<int,int>p=mp[tmp];
        if(p.first!=kk)
        {
          cout<<"YES"<<endl;
          cout<<p.first<<" "<<p.second<<endl;
          cout<<kk<<" "<<i<<endl;
          return 0;
        }
      }
      mp[tmp]={kk,i};
    }
  }
  cout<<"NO"<<endl;
  return 0;
}