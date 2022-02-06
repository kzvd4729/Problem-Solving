/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2019 17:54                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/993/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n,x;
long zeroCase(void)
{
  long ret=0,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>=x)cnt++;
    else ret+=(1LL*cnt*(cnt+1))/2,cnt=0;
  }
  return ret+(1LL*cnt*(cnt+1))/2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>x;
  for(int i=1;i<=n;i++)cin>>aa[i];
   cout<<zeroCase()<<" ";int pr=n;
  int id=-1;vector<int>v;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]<x&&id==-1)id=i;
    else if(aa[i]<x)v.push_back(i-id),id=i;
  }
  v.push_back(n-id+1);
  long sm=0;
  for(auto x:v)sm+=x;cout<<sm<<" ";pr--;
  for(int i=0;i<v.size()-1;i++)
  {
    sm-=v[i];
    cout<<sm<<" ";pr--;
  }
  //cout<<pr<<endl;
  while(pr--)cout<<0<<" ";
  cout<<endl;
  return 0;
}