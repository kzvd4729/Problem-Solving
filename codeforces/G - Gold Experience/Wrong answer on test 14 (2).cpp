/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2020 21:02                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 82500 KB                             
*  problem: https://codeforces.com/contest/1148/problem/G
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
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e7;
int pr[N+2];
void seive(int n)
{
  for(int i=4;i<=n;i+=2)pr[i]=2;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(pr[i]||i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)pr[j]=i;
  }
}
int cnt[N+2];
vector<int>factorize(int n)
{
  vector<int>v;
  while(true)
  {
    if(pr[n]==0)
    {
      v.push_back(n);break;
    }
    v.push_back(pr[n]);
    n/=pr[n];
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  //for(auto x:v)cout<<x<<" ";cout<<endl;
  for(auto x:v)cnt[x]++;
  return v;
}
int a[100000+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive(N);int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];factorize(a[i]);
  }
  for(int i=2;i<=N;i++)
  {
    if(cnt[i]<k)continue;
    for(int j=1;j<=n;j++)
    {
      if(k==0)break;
      if(a[j]%i==0)cout<<j<<" ",k--;
    }
    cout<<endl;break;
  }
  if(k==0)return 0;
  for(int i=1;i<=k;i++)cout<<i<<" ";cout<<endl;
  return 0;
}