/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/28/2019 20:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 3200 KB                              
*  problem: https://codeforces.com/contest/1107/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  string s;cin>>s;
  char p='5';priority_queue<int>pq;
  long ans=0;
  for(int i=0;i<n;i++)
  {
    if(p==s[i])
      pq.push(aa[i+1]);
    else
    {
      int lop=k;
      while(lop--)
      {
        if(pq.size()==0)break;
        ans+=(pq.top())*1LL;
        pq.pop();
      }
      while(pq.size())pq.pop();
      p=s[i];
      pq.push(aa[i+1]);
    }
  }
  int lop=k;
  while(lop--)
  {
    if(pq.size()==0)break;
    ans+=(pq.top())*1LL;
    pq.pop();
  }
  cout<<ans<<endl;
  return 0;
}