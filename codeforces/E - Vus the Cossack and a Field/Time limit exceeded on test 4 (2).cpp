/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2020 15:04                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1186/problem/E
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
#include<stack>
#include<deque>
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e3;
int a[N+2][N+2],n,m;
long solve(int x,int y)
{
  if(x==0||y==0)return 0;
  if(x<=n&&y<=m)return a[x][y];
  long ret=0,xx=n,yy=m;
  if(x<=n)
  {
    ret=a[x][m];
    while(true)
    {
      if(yy*2<=y)
      {
        ret+=(x*yy-ret);
        yy*=2;
      }
      else break;
    }
    return ret+x*(y-yy)-solve(x,y-yy);
  }
  if(y<=m)
  {
    ret=a[n][y];
    while(true)
    {
      if(xx*2<=x)
      {
        ret+=(xx*y-ret);
        xx*=2;
      }
      else break;
    }
    return ret+(x-xx)*y-solve(x-xx,y);
  }
  else
  {
    int tmp=x;x=n;
    ret=a[x][m];
    while(true)
    {
      if(yy*2<=y)
      {
        ret+=(x*yy-ret);
        yy*=2;
      }
      else break;
    }
    ret+=x*(y-yy)-solve(x,y-yy);
     x=tmp;
    while(true)
    {
      if(xx*2<=x)
      {
        ret+=(xx*y-ret);
        xx*=2;
      }
      else break;
    }
    //cout<<x-xx<<" "<<y<<endl;
    return ret+(x-xx)*y-solve(x-xx,y);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>m>>q;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)a[i][j]=s[j-1]-'0';
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)a[i][j]+=a[i][j-1];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)a[i][j]+=a[i-1][j];
  }
  while(q--)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;
    cout<<solve(c,d)-solve(a-1,d)-solve(c,b-1)+solve(a-1,b-1)<<endl;
  }
   //cout<<solve(3,3)<<endl;
    return 0;
}