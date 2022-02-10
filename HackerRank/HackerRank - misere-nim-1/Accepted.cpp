/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-08 15:01:57                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 185                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-misere-nim-1
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
const int N=1e5;
int a[N+2];
int misereNim(int n)//0 if first player wins
{
  int m=0,f=0,x=0;
  for(int i=1;i<=n;i++)
  {
    m+=(bool)a[i];f|=(a[i]>1);
    x^=a[i];
  }
  if(f==0)return m%2;
  else return !((bool)(x));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(misereNim(n))cout<<"Second\n";
    else cout<<"First\n";
  }
  return 0;
}