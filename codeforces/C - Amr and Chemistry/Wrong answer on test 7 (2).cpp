/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/29/2018 15:42                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/558/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],n,mx,xx,mn=99999999999;
vector<long>po;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>arr[i];
    mx=max(mx,arr[i]);
  }
  for(long i=mx;i<=1e18;i*=2)po.push_back(i);
  for(long i=mx/2;i>=1;i/=2)po.push_back(i);
   sort(po.begin(),po.end());
  mx=0;
  for(auto x:po)
  {
    long cnt=0;
    for(long i=1;i<=n;i++)
    {
      long f=0;
      if(arr[i]==x)continue;
      else if(arr[i]<x)
      {
        xx=arr[i];
        while(xx<x)
        {
          xx*=2;
          cnt++;
          if(xx==x)
          {
            f=1;
            break;
          }
        }
      }
      else
      {
        xx=arr[i];
        while(xx>x)
        {
          xx/=2;
          cnt++;
          if(xx==x)
          {
            f=1;
            break;
          }
        }
      }
      if(f==0)
      {
        cnt=99999999999;
        break;
      }
    }
    mn=min(mn,cnt);
  }
  cout<<mn<<endl;
  return 0;
}