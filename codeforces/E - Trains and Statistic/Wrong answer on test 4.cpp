/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2020 12:02                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/675/problem/E
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
#define long long long
using namespace std;
const int N=1e6;
long bit[N+2];
void upd(int x,long vl)
{
  for( ;x<=N;x+=x&-x)bit[x]=min(bit[x],vl);
}
long get(int x)
{
  long ret=1e18;
  for( ;x>0;x-=x&-x)ret=min(ret,bit[x]);
  return ret;
}
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)cin>>aa[i];
   memset(bit,14,sizeof(bit));
  upd(n,0);long ans=0;
  for(int i=n-1;i>=1;i--)
  {
    long now=n-i+get(aa[i]);
    upd(i,now);ans+=now;
  }
  cout<<ans<<endl;
  return 0;
}