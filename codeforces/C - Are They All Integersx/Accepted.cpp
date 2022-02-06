/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2020 18:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/102460/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
    int f=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=n;k++)
      {
        if(i==j||j==k||i==k)continue;
        if(abs(aa[i]-aa[j])%aa[k])f=1;
      }
    }
  }
  if(f)cout<<"no"<<endl;else cout<<"yes"<<endl;
    return 0;
}