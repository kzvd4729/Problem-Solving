/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 20:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 16500 KB                             
*  problem: https://codeforces.com/contest/1351/problem/C
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int x=0,y=0,ans=0;
    map<vector<int>,int>mp;
    for(auto c:s)
    {
      int xx=x,yy=y;
      if(c=='S')x++;if(c=='N')x--;
      if(c=='W')y--;if(c=='E')y++;
      if(mp[{xx,yy,x,y}]||mp[{x,y,xx,yy}])ans++;else ans+=5;
      mp[{xx,yy,x,y}]=1;
    }
    cout<<ans<<"\n";
  }
    return 0;
}