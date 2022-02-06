/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2020 17:40                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/817/problem/B
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
  sort(aa+1,aa+n+1);
    if(aa[1]==aa[2]==aa[3])
  {
    int cnt=0;
    for(int i=1;i<=n;i++)
      if(aa[i]==aa[1])cnt++;
    long ans=1;
    ans*=cnt;ans*=(cnt-1);ans*=(cnt-2);
    cout<<ans/6<<endl;
  }
  else
  {
    int cnt=0;
    for(int i=1;i<=n;i++)
      if(aa[i]==aa[3])cnt++;
    cout<<cnt<<endl;
  }
    return 0;
}