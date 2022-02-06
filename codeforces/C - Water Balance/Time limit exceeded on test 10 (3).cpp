/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 14:44                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 12100 KB                             
*  problem: https://codeforces.com/contest/1299/problem/C
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
const int N=1e6;
double a[N+2];int sz[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    //a[i]=1+rand()%100000;
    sz[i]=1;
  }
   for(int i=n;i>=1;i--)
  {
    for(int j=i+sz[i];j<=n;j+=sz[j])
    {
      if(a[j]>=a[i])break;
      a[i]=(a[i]*sz[i]+a[j]*sz[j])/((sz[i]+sz[j])*1.0);
      sz[i]+=sz[j];
    }
  }
  //cout<<a[n]<<endl;
  cout<<setprecision(9)<<fixed;
  for(int i=1;i<=n;i+=sz[i])
  {
    for(int j=1;j<=sz[i];j++)
    {
      cout<<a[i]<<"\n";
    }
  }
  return 0;
}