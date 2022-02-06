/****************************************************************************************
*  @author: * kzvd4729                                       created: May/09/2020 20:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1352/problem/D
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
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    int mv=1,a=aa[1],b=0,mx=aa[1],f=1;
    int l=2,r=n,cr=0;
    while(l<=r)
    {
      if(!f)
      {
        cr+=aa[l++];
        if(cr>mx)
        {
          mx=cr;a+=cr;f^=1;mv++;
          cr=0;
        }
      }
      else
      {
        cr+=aa[r--];
        if(cr>mx)
        {
          mx=cr;b+=cr;f^=1;mv++;
          cr=0;
        }
      }
    }
    if(cr)
    {
      mv++;if(!f)a+=cr;else b+=cr;
    }
    cout<<mv<<" "<<a<<" "<<b<<endl;
  }
  return 0;
}