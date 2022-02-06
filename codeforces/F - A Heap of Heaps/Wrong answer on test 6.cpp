/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 12:02                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/538/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int k=1;k<n;k++)
  {
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      int a=k*(i-1)+2,b=k*i+1;
      if(a>n&&b>n)break;
      if(a<=n&&aa[a]<aa[i])cnt++;
      if(b<=n&&aa[b]<aa[i]&&b!=a)cnt++;
    }
    cout<<cnt<<" ";
  }
  cout<<endl;
  return 0;
}