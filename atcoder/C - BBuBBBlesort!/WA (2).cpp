/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-02 13:11:34                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 23 ms                                           memory_used: 4988 KB                              
*  problem: https://atcoder.jp/contests/agc003/tasks/agc003_c
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
const int N=1e6,mod=1e9+7;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int ans=0;priority_queue<int>a,b;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    if(i%2)a.push(-aa[i]);else b.push(-aa[i]);
  }
  for(int i=2;i<=n;i++)
  {
    if(a.size()==0||b.size()==0)break;
    if(i%2)
    {
      int y=-b.top(),x=-a.top();a.pop();b.pop();
      if(x<y)ans++,a.push(-y);
      else i++;
    }
    else
    {
      int y=-b.top(),x=-a.top();a.pop();b.pop();
      if(y<x)ans++,b.push(-x);
      else i++;
    }
  }
  cout<<ans<<endl;
  return 0;
}