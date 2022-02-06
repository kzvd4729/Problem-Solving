/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/16/2019 19:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1174/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int pt=2,cnt=1;
  while(true)
  {
    while(aa[pt])pt++;
    if(pt>n)break;
    for(int i=pt;i<=n;i+=pt)
      if(!aa[i])aa[i]=cnt;
    cnt++;
  }
  for(int i=2;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}