/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2019 22:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 639 ms                                          memory_used: 6000 KB                              
*  problem: https://codeforces.com/contest/722/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n;map<int,int>mp;
bool isOk(int md)
{
  mp.clear();
  for(int i=1;i<=n;i++)
  {
    int x=aa[i];int f=0;
    while(x)
    {
      if(x<=md&&!mp.count(x))
      {
        mp[x]=1,f=1;break;
      }
      x/=2;
    }
    if(!f)return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
   int lo=1,hi=1e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(isOk(md))hi=md;else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(isOk(md))break;
  for(auto x:mp)
    cout<<x.first<<" ";
  cout<<endl;
   return 0;
}