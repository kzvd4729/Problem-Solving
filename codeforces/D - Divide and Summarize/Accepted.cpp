/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/11/2020 21:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 17800 KB                             
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
  if(lo>hi)return ;
  st.insert(qm[hi]-qm[lo-1]);
  if(a[lo]==a[hi])return ;
  int md=(a[lo]+a[hi])/2;
   int r=upper_bound(a+1,a+n+1,md)-a;
  r--;
   solve(lo,r);solve(r+1,hi);
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
    st.clear();solve(1,n);
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