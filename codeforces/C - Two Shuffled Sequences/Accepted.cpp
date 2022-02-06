/****************************************************************************************
*  @author: kzvd4729                                         created: May/25/2020 10:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1144/problem/C
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
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[x]++;
  }
  for(int i=0;i<=N;i++)if(aa[i]>2)cout<<"NO\n",exit(0);
  int a=0;cout<<"YES\n";
  for(int i=0;i<=N;i++)if(aa[i])a++;
  cout<<a<<endl;
  for(int i=0;i<=N;i++)if(aa[i])cout<<i<<" ",aa[i]--;
  cout<<endl;
   a=0;
  for(int i=0;i<=N;i++)if(aa[i])a++;
  cout<<a<<endl;
  for(int i=N;i>=0;i--)if(aa[i])cout<<i<<" ",aa[i]--;
  cout<<endl;
    return 0;
}