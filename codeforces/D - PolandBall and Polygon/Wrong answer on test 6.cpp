/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2020 11:52                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 452 ms                                          memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/755/problem/D
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
int bit[N+N+2];
void upd(int x)
{
  for( ;x<=N+N;x+=x&-x)bit[x]++;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;long ans=1;
   int p=1;
  while(true)
  {
    if(vs[p])break;vs[p]=1;
    int g=get(p+k-1)-get(p);
    ans+=g+1;upd(p);upd(p+n);
    p=p+k;if(p>n)p-=n;upd(p);upd(p+n);
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}