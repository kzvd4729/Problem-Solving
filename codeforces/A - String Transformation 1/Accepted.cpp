/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2020 20:52                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1383/problem/A
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
void solve()
{
  int n;cin>>n;string a,b;cin>>a>>b;
  for(int i=0;i<n;i++)if(b[i]<a[i]){cout<<-1<<endl;return;}
   int cnt=0;
  while(true)
  {
    char mn='z';int f=0;
    for(int i=0;i<n;i++)
    {
      if(a[i]==b[i])continue;
      mn=min(mn,a[i]);f=1;
    }
    if(f==0)break;
    char nx='z';
    for(int i=0;i<n;i++)
    {
      if(a[i]==b[i])continue;
      if(a[i]==mn)nx=min(nx,b[i]);
    }
    cnt++;
    for(int i=0;i<n;i++)
    {
      if(a[i]==b[i])continue;
      if(a[i]==mn)a[i]=nx;
    }
  }
  cout<<cnt<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}