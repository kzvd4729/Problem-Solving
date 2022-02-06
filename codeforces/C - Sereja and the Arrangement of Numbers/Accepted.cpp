/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/03/2019 16:26                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 109 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/367/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int mx[N+2],aa[N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=10000;i++)
  {
    if(i&1)mx[i]=(i*(i-1))/2+1;
    else mx[i]=(i*(i-1))/2+i/2;
  }
  int n,k;cin>>n>>k;
  for(int i=1;i<=k;i++)
  {
    int x;
    cin>>x>>aa[i];
  }
  sort(aa+1,aa+k+1,greater<int>());
  for(int i=1;i<=10000;i++)
    qm[i]=qm[i-1]+aa[i];
  int id=0;
  for(int i=1;i<=10000;i++)
    if(mx[i]<=n)id=i;
  cout<<qm[id]<<endl;
   return 0;
}