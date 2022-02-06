/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 19:42                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15400 KB                             
*  problem: https://codeforces.com/contest/1283/problem/F
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
int a[N+2],fk[N+2],ac[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)cin>>a[i];
   set<int>st,an;
  for(int i=1;i<=n;i++)st.insert(i);
   cout<<a[2]<<endl;st.erase(a[2]);
  int b=*st.rbegin();st.erase(b);
  fk[b]=a[2];an.insert(b);ac[a[2]]=1;
   for(int i=3;i<=n;i++)
  {
    int nd=a[i];
    if(fk[nd])
    {
      cout<<nd<<" "<<fk[nd]<<endl;an.erase(nd);ac[nd]=1;
      fk[nd]=0;int b=*st.rbegin();st.erase(b);
      fk[b]=nd;an.insert(b);
    }
    else if(!ac[nd])
    {
      st.erase(nd);
      int b=*an.rbegin();ac[nd]=1;
      cout<<nd<<" "<<fk[b]<<endl;
      fk[b]=nd;
    }
    else
    {
      int b=*st.rbegin();st.erase(b);
      fk[b]=nd;an.insert(b);
    }
  }
  for(int i=1;i<=n;i++)if(fk[i])cout<<i<<" "<<fk[i]<<endl;
  return 0;
}