/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2020 20:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 265 ms                                          memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1358/problem/C
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
#define long long long
using namespace std;
const int N=1e6;
long sm(long x)
{
  return x*(x+1)/2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long a,b,c,d;cin>>a>>b>>c>>d;
    long mn=min(c-a,d-b),mx=max(c-a,d-b);//cout<<mn<<" "<<mx<<endl;
    cout<<sm(mn-1)*2+mn*(mx-mn+1)+1<<endl;
  }
  return 0;
}