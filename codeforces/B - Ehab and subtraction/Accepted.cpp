/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1088/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
   int qm=0;
  for(int i=1;i<=n;i++)
  {
    if(k==0)break;
    if(aa[i]-qm==0)continue;
    cout<<aa[i]-qm<<" ";k--;
    qm=aa[i];
  }
  while(k--)
    cout<<0<<" ";
  cout<<endl;
  return 0;
}