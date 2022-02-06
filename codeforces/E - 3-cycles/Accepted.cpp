/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 23:39                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/41/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int R=1e9;
const int N=1e2;
int n,mat[N+2][N+2];
vector<pair<int,int> >ed;
bool ok(int x,int y)
{
  for(int i=1;i<=n;i++)
    if(mat[i][x]&&mat[i][y])return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j+i<=n;j++)
    {
      int x=j,y=j+i;
      if(x==y||mat[x][y])continue;
      if(ok(x,y))
      {
        ed.push_back({x,y});
        mat[x][y]=1;
        mat[y][x]=1;
      }
    }
  }
  cout<<ed.size()<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}