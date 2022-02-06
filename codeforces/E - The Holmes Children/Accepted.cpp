/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2020 18:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 12800 KB                             
*  problem: https://codeforces.com/contest/776/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define long long long
using namespace std;
const int N=1e6;
int vs[N+2];vector<int>p;
void seive()
{
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;p.push_back(i);
    for(int j=i+i;j<=N;j+=i)vs[j]=1;
  }
}
long phi(long n)
{
  long ret=n;
  for(auto x:p)
  {
    if(n%x)continue;ret/=x;ret*=(x-1);
    while(n%x==0)n/=x;if(n==1)break;
  }
  if(n>1){ret/=n;ret*=(n-1);}
  return ret;
}
long ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();long n,k;cin>>n>>k;
  ans[1]=phi(n);
  if(k==1)cout<<ans[1]%1000000007<<endl,exit(0);
  for(int i=2;i<=k;i++)
  {
    if(i%2==0)ans[i]=ans[i-1];
    else ans[i]=phi(ans[i-1]);
     if(ans[i]==1)cout<<1<<endl,exit(0);
  }
  cout<<ans[k]%1000000007<<endl;
  return 0;
}