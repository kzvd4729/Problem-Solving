/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 13:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 17100 KB                             
*  problem: https://codeforces.com/contest/540/problem/C
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
const int N=5e2;
int n,m,r,c,x,y;
string s[N+2];
void ya()
{
  cout<<"YES\n",exit(0);
}
void no()
{
  cout<<"NO\n",exit(0); 
}
bool isV(int i,int j)
{
  if(i>=0&&i<n&&j>=0&&j<m)return true;
  return false;
}
int vs[N+2][N+2],rh;
void dfs(int x,int y)
{
  if(x==r&&y==c)
  {
    rh=1;return ;
  }
  if(vs[x][y]||s[x][y]=='X')return ;vs[x][y]=1;
  if(isV(x+1,y))dfs(x+1,y);
  if(isV(x-1,y))dfs(x-1,y);
  if(isV(x,y+1))dfs(x,y+1);
  if(isV(x,y-1))dfs(x,y-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
  cin>>x>>y>>r>>c;x--,y--,r--,c--;
   int f=0;
  if(x+1==r&&y==c)f=1;
  if(x-1==r&&y==c)f=1;
  if(x==r&&y+1==c)f=1;
  if(x==r&&y-1==c)f=1;
   if(isV(x+1,y))dfs(x+1,y);
  if(isV(x-1,y))dfs(x-1,y);
  if(isV(x,y+1))dfs(x,y+1);
  if(isV(x,y-1))dfs(x,y-1);
   int cnt=0;
  if(isV(r+1,c)&&s[r+1][c]=='.')cnt++;
  if(isV(r-1,c)&&s[r-1][c]=='.')cnt++;
  if(isV(r,c+1)&&s[r][c+1]=='.')cnt++;
  if(isV(r,c-1)&&s[r][c-1]=='.')cnt++;
   if(x==r&&y==c)
  {
    if(cnt)ya();no();
  }
  if(f)
  {
    if(s[r][c]=='X')ya();
    if(cnt)ya();no();
  }
  if(s[r][c]=='X')
  {
    if(rh)ya();no();
  }
  if(rh&&cnt>1)ya();no();
    return 0;
}