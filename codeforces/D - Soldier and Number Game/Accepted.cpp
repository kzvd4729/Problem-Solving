/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/21/2020 12:55                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 951 ms                                          memory_used: 39200 KB                             
*  problem: https://codeforces.com/contest/546/problem/D
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
const int N=5e6;
int vs[N+2],qm[N+2];
void seive()
{
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;
    int p=1;
    while(1LL*p*i<=N)
    {
      p*=i;
      for(int j=p;j<=N;j+=p)vs[j]++;
    }
  }
  //for(int i=1;i<=10;i++)cout<<vs[i]<<" ";cout<<endl;
  for(int i=1;i<=N;i++)
    qm[i]=qm[i-1]+vs[i];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    cout<<qm[a]-qm[b]<<"\n";
  }
  return 0;
}