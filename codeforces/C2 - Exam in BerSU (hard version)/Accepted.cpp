/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2019 02:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1185/problem/C2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int sum=0;
  for(int i=1;i<=n;i++)
  {
    sum+=aa[i];int cnt=0,df,nd,sm=sum;
    for(int x=100;x>=1;x--)
    {
      df=max(sum-m,0);
      nd=(df+x-1)/x;
      nd=min(nd,fr[x]);
      cnt+=nd;sum-=nd*x;
    }
    sum=sm;fr[aa[i]]++;
    cout<<cnt<<" ";
  }
  cout<<endl;
  return 0;
}