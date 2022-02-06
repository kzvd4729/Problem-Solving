/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2020 12:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 21700 KB                             
*  problem: https://codeforces.com/contest/1349/problem/C
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
const int N=1e3;
int b[N+2][N+2],n,m;
string s[N+2];vector<pair<int,int> >bf,tmp;
bool isV(int i,int j)
{
  return i>=1&&i<=n&&j>=1&&j<=m;
}
int ret(int i,int j,long m)
{
  int in=s[i][j]-'0';
  if(b[i][j]==-1||m<b[i][j])return in;
  return in^((m-b[i][j])%2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>m>>q;
  for(int i=1;i<=n;i++)
    cin>>s[i],s[i]="#"+s[i];
  memset(b,-1,sizeof(b));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      int f=0;
      if(isV(i+1,j)&&s[i][j]==s[i+1][j])f=1;
      if(isV(i-1,j)&&s[i][j]==s[i-1][j])f=1;
      if(isV(i,j+1)&&s[i][j]==s[i][j+1])f=1;
      if(isV(i,j-1)&&s[i][j]==s[i][j-1])f=1;
      if(!f)continue;bf.push_back({i,j});
      b[i][j]=0;//cout<<i<<" --> "<<j<<endl;
    }
  }
  for(int i=1; ;i++)
  {
    if(bf.size()==0)break;
    for(auto z:bf)
    {
      int x=z.first,y=z.second;
      if(isV(x+1,y)&&b[x+1][y]==-1&&s[x+1][y]-'0'==ret(x,y,i))
        b[x+1][y]=i,tmp.push_back({x+1,y});
      if(isV(x-1,y)&&b[x-1][y]==-1&&s[x-1][y]-'0'==ret(x,y,i))
        b[x-1][y]=i,tmp.push_back({x-1,y}); 
      if(isV(x,y+1)&&b[x][y+1]==-1&&s[x][y+1]-'0'==ret(x,y,i))
        b[x][y+1]=i,tmp.push_back({x,y+1});
      if(isV(x,y-1)&&b[x][y-1]==-1&&s[x][y-1]-'0'==ret(x,y,i))
        b[x][y-1]=i,tmp.push_back({x,y-1});
    }
    bf=tmp;tmp.clear();
  }
  while(q--)
  {
    long x,y,m;cin>>x>>y>>m;
    cout<<ret(x,y,m)<<"\n";
  }
  return 0;
}