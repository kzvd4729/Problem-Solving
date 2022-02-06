/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/11/2020 21:36                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 17800 KB                             
*  problem: https://codeforces.com/contest/1461/problem/D
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
int a[N+2],n;long qm[N+2];
set<long>st;
void solve(int lo,int hi)
{
  int l=lower_bound(a+1,a+n+1,lo)-a;
  int r=upper_bound(a+1,a+n+1,hi)-a;
  r--;
   st.insert(qm[r]-qm[l-1]);
  if(l==r||lo==hi)return ;
   int md=(lo+hi)/2;
  solve(lo,md);solve(md+1,hi);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
     for(int i=1;i<=n;i++)qm[i]=qm[i-1]+a[i];
    st.clear();
    solve(a[1],a[n]);
    while(m--)
    {
      int s;cin>>s;
      if(st.find(s)!=st.end())cout<<"Yes ";
      else cout<<"No ";
    }
    cout<<endl;
  }
  return 0;
}