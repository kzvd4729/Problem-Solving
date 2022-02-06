/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2020 14:06                        
*  solution_verdict: Wrong answer on test 17                 language: GNU C++14                               
*  run_time: 1466 ms                                         memory_used: 19700 KB                             
*  problem: https://codeforces.com/contest/568/problem/A
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
#include<set>
#include<queue>
#include<unordered_map>
#define long long long
using namespace std;
const int N=5e6;
bool isP(int x)
{
  vector<int>v;
  while(x)
  {
    v.push_back(x%10);
    x/=10;
  }
  if(v.size()==0)v.push_back(0);
  int n=v.size();
  for(int i=0;i<n;i++)if(v[i]!=v[n-1-i])return false;
  return true;
}
int vs[N+2];
void seive()
{
  vs[1]=1;
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;
    for(int j=i+i;j<=N;j+=i)vs[j]=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();
  int pr=0,pl=0,ans=-1;int p,q;cin>>p>>q;
  for(int i=1;i<=N;i++)
  {
    if(isP(i))pl++;
    if(!vs[i])pr++;
    if(pr*q<=pl*p)ans=i;
  }
  //cout<<pl*42<<" "<<pr<<endl;
  cout<<ans<<endl;
  return 0;
}