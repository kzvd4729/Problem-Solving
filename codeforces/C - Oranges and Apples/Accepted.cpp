/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2020 23:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 420 ms                                          memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/23/problem/C
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
#include<random>
#include<utility>
#include<chrono>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,mod=1e9+9;
int aa[N+2],bb[N+2];
long ta,tb;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;ta=0,tb=0;
    for(int i=1;i<=2*n-1;i++)
    {
      cin>>aa[i]>>bb[i];ta+=aa[i],tb+=bb[i];
    }
    vector<int>v;
    for(int i=1;i<=2*n-1;i++)v.push_back(i);
    int f=1;cout<<"YES\n";
    while(f)
    {
      shuffle(v.begin(),v.end(),rng);
      long sa=0,sb=0;
      for(int i=0;i<n-1;i++)
        sa+=aa[v[i]],sb+=bb[v[i]];
      if(sa<=ta/2&&sb<=tb/2)
      {
        f=0;
        for(int i=n-1;i<v.size();i++)
          cout<<v[i]<<" ";
        cout<<endl;break;
      }
      for(int i=n-1;i<v.size();i++)
      {
        sa+=aa[v[i]],sb+=bb[v[i]];
        if(sa>=(ta+1)/2&&sb>=(tb+1)/2)
        {
          f=0;cout<<v[i]<<" ";
          for(int i=0;i<n-1;i++)
            cout<<v[i]<<" ";
          cout<<endl;break;
        }
        if(f==0)break;sa-=aa[v[i]],sb-=bb[v[i]];
      }
    }
  }
  return 0;
}