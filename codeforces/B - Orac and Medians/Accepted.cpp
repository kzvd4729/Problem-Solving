/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2020 11:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/1349/problem/B
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
#include<unordered_map>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;int f=0;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];if(aa[i]==k)f=1;
    }
    if(!f){cout<<"no\n";continue;}
    if(n==1){cout<<"yes\n";continue;}
    f=0;
    for(int i=1;i<n;i++)if(aa[i]>=k&&aa[i+1]>=k)f=1;
    for(int i=1;i<n-1;i++)if(aa[i]>=k&&aa[i+2]>=k)f=1;
    if(f)cout<<"yes\n";else cout<<"no\n";
  }
  return 0;
}