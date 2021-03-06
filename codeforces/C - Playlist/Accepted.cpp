/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2019 21:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 10900 KB                             
*  problem: https://codeforces.com/contest/1140/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct data
{
  int t,b;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.b>B.b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i].t>>aa[i].b;
  }
  sort(aa+1,aa+n+1,cmp);
  priority_queue<int>pq;
  long ln=0,ans=0;
  for(int i=1;i<=n;i++)
  {
    ln+=(aa[i].t*1LL);pq.push(-aa[i].t);
    if(pq.size()>k)
    {
      ln+=(pq.top()*1LL);pq.pop();
    }
    ans=max(ans,(aa[i].b*1LL)*ln);
  }
  cout<<ans<<endl;
  return 0;
}