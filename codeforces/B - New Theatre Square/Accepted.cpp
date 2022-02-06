/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1359/problem/B
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
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,x,y;cin>>n>>m>>x>>y;long ans=0;
    for(int i=0;i<n;i++)
    {
      string s;cin>>s;int cnt=0;
      for(int j=0;j<m;j++)
      {
        if(s[j]=='.')cnt++;
        else ans+=min(cnt*x,(cnt/2)*y+x*(cnt%2)),cnt=0;
      }
      ans+=min(cnt*x,(cnt/2)*y+x*(cnt%2));
    }
    cout<<ans<<endl;
  }
  return 0;
}