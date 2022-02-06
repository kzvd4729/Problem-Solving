/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 23:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1178/problem/A
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
const int N=1e6,mod=1e9+7;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int tt=0;
  for(int i=1;i<=n;i++)cin>>aa[i],tt+=aa[i];
   vector<int>ans={1};int sm=aa[1];
  for(int i=2;i<=n;i++)
  {
    if(aa[i]*2<=aa[1])ans.push_back(i),sm+=aa[i];
  }
  if(sm>tt/2)
  {
    cout<<ans.size()<<"\n";
    for(auto x:ans)cout<<x<<" ";
      cout<<"\n";
  }
  else cout<<0<<endl;
  return 0;
}