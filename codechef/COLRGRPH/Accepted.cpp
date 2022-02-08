/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2021 21:21:40                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/COOK131A/problems/COLRGRPH
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e2,inf=1e9,mod=1e9+7;
const int w=0,b=1;
int mt[N+2][N+2],color[N+2];
vector<int>v[N+2];
int ask(int i)
{
  cout<<"? "<<i<<endl;
  char c;cin>>c;
  if(c=='W')return w;
  else return b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    color[i]=ask(i);
    for(int j=1;j<i;j++)
    {
      int now=ask(j);
      if(now!=color[j])
      {
        color[j]^=1;
        v[j].push_back(i);v[i].push_back(j);
        mt[i][j]=1;mt[j][i]=1;
      }
      for(auto x:v[j])color[x]^=1;
    }
  }
  cout<<"!"<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)cout<<mt[i][j];
      cout<<endl;
  }
  return 0;
}