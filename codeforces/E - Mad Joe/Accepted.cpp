/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/06/2020 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 873 ms                                          memory_used: 37600 KB                             
*  problem: https://codeforces.com/contest/250/problem/E
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e4+10;
int cnt[100+2][N+2];
string s[100+2];set<int>on[100+2],of[100+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s[i];s[i]="#"+s[i]+"#";
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='.')of[i].insert(j);
      else on[i].insert(j);
    }
    on[i].insert(0);on[i].insert(m+1);
    of[i].insert(-1);of[i].insert(m+2);
  }
  long ans=0;int a=1,b=1,d=1;
  while(true)
  {
    if(clock()>CLOCKS_PER_SEC*0.8)cout<<"Never\n",exit(0);
    //cout<<a<<" "<<b<<endl;
    if(a==n)break;
    if(d)
    {
      int cr=*on[a].lower_bound(b);
      int nx=*of[a+1].lower_bound(b);
      if(nx<cr)
      {
        ans+=nx-b+1;a++;b=nx;
      }
      else
      {
        ans+=cr-b;b=cr-1;d^=1;
        if(s[a][cr]=='+')
        {
          on[a].erase(cr);s[a][cr]='.';
          of[a].insert(cr);
        }
      }
    }
    else
    {
      auto it1=on[a].upper_bound(b);
      auto it2=of[a+1].upper_bound(b);
      it1--,it2--;
       int cr=*it1,nx=*it2;
      if(nx>cr)
      {
        ans+=b-nx+1;a++;b=nx;
      }
      else
      {
        ans+=b-cr;b=cr+1;d^=1;
        if(s[a][cr]=='+')
        {
          on[a].erase(cr);s[a][cr]='.';
          of[a].insert(cr);
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}