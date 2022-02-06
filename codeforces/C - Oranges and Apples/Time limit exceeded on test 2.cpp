/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2020 22:14                        
*  solution_verdict: Time limit exceeded on test 2           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 11800 KB                             
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+9;
struct data
{
  int a,b,id;
}aa[N+2];
long ta,tb;int n,f;
vector<int>p;
void dfs(int i,int tk,long sa,long sb)
{
  if(f)return ;
  if(tk==n)
  {
    if(sa>=(ta+1)/2&&sb>=(tb+1)/2)
    {
      cout<<"YES\n";f=1;
      for(auto x:p)cout<<x<<" ";
        cout<<endl;
    }
    return ;
  }
  if(i==2*n)return ;
  p.push_back(aa[i].id);dfs(i+1,tk+1,sa+aa[i].a,sb+aa[i].b);
  if(f)return ;
  p.pop_back();dfs(i+1,tk,sa,sb);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;ta=0,tb=0;
    for(int i=1;i<=2*n-1;i++)
    {
      cin>>aa[i].a>>aa[i].b,aa[i].id=i;
      ta+=aa[i].a,tb+=aa[i].b;
    }
    sort(aa+1,aa+2*n,[&](data a,data b){
      return a.a>b.a;
    });
    f=0;p.clear();dfs(1,0,0,0);
    if(f==0)cout<<"NO\n";assert(f);
  }
  return 0;
}