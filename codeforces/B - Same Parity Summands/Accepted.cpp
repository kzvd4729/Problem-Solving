/****************************************************************************************
*  @author: * kzvd4729                                       created: May/09/2020 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1352/problem/B
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
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
     int f=n-(k-1);
    if(f>0&&f%2)
    {
      cout<<"YES\n";
      for(int i=1;i<=k-1;i++)cout<<1<<" ";
        cout<<f<<"\n";
      continue;
    }
    f=n-(k-1)*2;
    if(f>0&&(f%2==0))
    {
      cout<<"YES\n";
      for(int i=1;i<=k-1;i++)cout<<2<<" ";
        cout<<f<<"\n";
      continue;
    }
    cout<<"NO\n";
  }
  return 0;
}