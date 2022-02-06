/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2019 12:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/652/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  int p1=1,p2=n;
  while(p1<=p2)
  {
    if(p1<=p2)
    {
      cout<<aa[p1]<<" ";
      p1++;
    }
    if(p1<=p2)
    {
      cout<<aa[p2]<<" ";
      p2--;
    }
  }
  cout<<endl;
  return 0;
}