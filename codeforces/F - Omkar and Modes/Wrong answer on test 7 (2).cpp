/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2020 00:44                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1372/problem/F
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
int n,ans[N+2];
int ask(int i)
{
  cout<<"? "<<i<<" "<<i<<endl;
  int x,f;cin>>x>>f;
  return x;
}
void print()
{
  cout<<"!";
  for(int i=1;i<=n;i++)cout<<" "<<ans[i];
  cout<<endl;
}
void solve(int lo,int hi,int l,int r)
{
  if(lo>hi)return;
  if(l==r)
  {
    for(int i=lo;i<=hi;i++)ans[i]=l;
    return;
  }
  int md=(lo+hi)/2;
  int x=ask(md);ans[md]=x;
  solve(lo,md-1,l,x);solve(md+1,hi,x,r);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;solve(1,n,ask(1),ask(n));
  print();
   return 0;
}