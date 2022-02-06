/****************************************************************************************
*  @author: * kzvd4729                                       created: May/16/2020 17:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1355/problem/C
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
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c,d;cin>>a>>b>>c>>d;
   for(int i=a;i<=b;i++)
    aa[i+b]++,aa[i+c+1]--;
  for(int i=1;i<=N;i++)aa[i]+=aa[i-1];
   for(int i=N-1;i>=0;i--)aa[i]+=aa[i+1];
  long ans=0;
  for(int i=c;i<=d;i++)ans+=aa[i+1];
  cout<<ans<<"\n";
   return 0;
}