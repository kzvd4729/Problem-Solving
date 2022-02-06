/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 17:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/534/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long arr[N+2],mx,mn;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;long k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    mx+=arr[i];
  }
  mn=n;
  for(int i=1;i<=n;i++)
  {
    mx-=arr[i],mn--;
    long lt=max(1LL,k-mx);
    long rt=min(arr[i],k-mn);
    mx+=arr[i],mn++;
    cout<<lt-1+arr[i]-rt<<" ";
  }
  cout<<endl;
  return 0;
}