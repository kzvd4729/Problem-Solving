/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 20:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/379/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
   while(aa[1]--)cout<<"RLP";
  for(int i=2;i<=n;i++)
  {
    while(aa[i]--)
      cout<<"RPL";
    cout<<"R";
  }
  cout<<endl;
   return 0;
}