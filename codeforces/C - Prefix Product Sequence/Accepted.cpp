/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/10/2020 17:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/487/problem/C
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
const int N=500;
bool isPrime(int x)
{
  for(int i=2;i<x;i++)if(x%i==0)return false;
  return true;
}
int big(int b,int p,int mod)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  if(n==1)cout<<"YES"<<endl<<1<<endl,exit(0);
  if(n==4)cout<<"YES"<<endl<<1<<" "<<3<<" "<<2<<" "<<4<<endl,exit(0);
   if(isPrime(n)==0)cout<<"NO"<<endl,exit(0);
   cout<<"YES"<<endl;cout<<1<<" ";
  for(int i=2;i<n;i++)
  {
    cout<<(1LL*big(i-1,n-2,n)*i)%n<<" ";
  }
  cout<<n<<endl;
    return 0;
}