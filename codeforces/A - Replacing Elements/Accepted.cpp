/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2021 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1473/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
     if(a[n]<=d||a[1]+a[2]<=d)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
    return 0;
}