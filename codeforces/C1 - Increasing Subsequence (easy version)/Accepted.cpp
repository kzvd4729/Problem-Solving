/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/26/2019 21:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 12200 KB                             
*  problem: https://codeforces.com/contest/1157/problem/C1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int lt[N+2],rt[N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)lt[i]=rt[i]=1;
  for(int i=n-1;i>=1;i--)
    if(aa[i+1]>aa[i])lt[i]=lt[i+1]+1;
  for(int i=2;i<=n;i++)
    if(aa[i-1]>aa[i])rt[i]=rt[i-1]+1;
   int a=1,b=n,l=-1;string ans;
  while(true)
  {
    if(a>b)break;
    if(aa[a]<aa[b])
    {
      if(aa[a]>l)
      {
        l=aa[a];a++;
        ans.push_back('L');
      }
      else if(aa[b]>l)
      {
        l=aa[b];b--;
        ans.push_back('R');
      }
      else break;
    }
    else if(aa[a]>aa[b])
    {
      if(aa[b]>l)
      {
        l=aa[b];b--;
        ans.push_back('R');
      }
      else if(aa[a]>l)
      {
        l=aa[a];a++;
        ans.push_back('L');
      }
      else break;
    }
    else
    {
      if(aa[a]<=l)break;
      int ll=min(lt[a],b-a+1);
      int rr=min(rt[b],b-a+1);
      if(ll>rr)
      {
        while(ll--)ans.push_back('L');
      }
      else
      {
        while(rr--)ans.push_back('R');
      }
      break;
    }
  }
  cout<<ans.size()<<endl;
  cout<<ans<<endl;
  return 0;
}