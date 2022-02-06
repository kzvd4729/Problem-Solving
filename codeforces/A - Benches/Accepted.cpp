/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2018 22:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1042/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int arr[N+2],mx,sum;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;int mm=m;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    mx=max(mx,arr[i]);
  }
  for(int i=1;i<=n;i++)
    sum+=mx-arr[i];
  m-=sum;if(m<0)m=0;
  cout<<mx+((m+n-1)/n)<<" "<<mx+mm<<endl;
   return 0;
}