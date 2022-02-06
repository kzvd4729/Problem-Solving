/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/24/2020 21:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1454/problem/D
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;long sq=sqrt(n+1);
     long mx=-1,p=1,nn=n;
    for(long i=2;i<=sq;i++)
    {
      if(n%i)continue;int cnt=0;
      while(n%i==0)n/=i,cnt++;
      if(cnt>mx)mx=cnt,p=i;
    }
    if(mx<1)mx=1,p=n;
    cout<<mx<<endl;
    for(int i=1;i<mx;i++)
    {
      cout<<p<<" ";nn/=p;
    }
    cout<<nn<<endl;
  }
  return 0;
}