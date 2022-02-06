/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/03/2020 19:29                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/900/problem/C
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],ok[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
    int mx=0,mn=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>mx)ok[i]=1;
    else if(aa[i]>mn)cnt[mx]++;
     if(aa[i]>mx)mn=mx,mx=aa[i];
    else if(aa[i]>mn)mn=aa[i];
  }
  int ad=-1e9,ans;
  for(int i=1;i<=n;i++)
  {
    if(cnt[i]-ok[i]>ad)ans=i;
    else if(cnt[i]-ok[i]==ad)ans=min(ans,i);
  }
  cout<<ans<<endl;
  return 0;
}