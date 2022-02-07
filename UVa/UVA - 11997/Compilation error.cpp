/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 20:30:59                      
*  solution_verdict: Compilation error                       language: C                                       
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11997
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e4;
int n,m,mt[200+2][N+2],tm;
void drawCircle()
{
  int x,y,r,c;cin>>x>>y>>r>>c;x++,y++;
  int lt=max(1,y-r),rt=min(m,y+r);
  v[x][lt].push_back({rt,tm,c});
  for(int i=x+1;i<=n;i++)
  {
    while(true)
    {
      if((x-i)*(x-i)+(rt-y)*(rt-y)>r*r)
        rt--;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;
    while(true)
    {
      if((x-i)*(x-i)+(lt-y)*(lt-y)>r*r)
        lt++;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;

    v[i][lt].push_back({rt,tm,c});
  }
  for(int i=x-1;i>=1;i--)
  {
    while(true)
    {
      if((x-i)*(x-i)+(rt-y)*(rt-y)>r*r)
        rt--;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;
    while(true)
    {
      if((x-i)*(x-i)+(lt-y)*(lt-y)>r*r)
        lt++;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;

    v[i][lt].push_back({rt,tm,c});
  }
}
void drawDiamond()
{
  int x,y,r,c;cin>>x>>y>>r>>c;x++,y++;
  int lt=max(1,y-r),rt=min(m,y+r);
  v[x][lt].push_back({rt,tm,c});
  for(int i=x+1;i<=n;i++)
  {
    while(true)
    {
      if(abs(x-i)+abs(rt-y)>r)
        rt--;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;
    while(true)
    {
      if(abs(x-i)+abs(lt-y)>r)
        lt++;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;

    v[i][lt].push_back({rt,tm,c});
  }
  for(int i=x-1;i>=1;i--)
  {
    while(true)
    {
      if(abs(x-i)+abs(rt-y)>r)
        rt--;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;
    while(true)
    {
      if(abs(x-i)+abs(lt-y)>r*r)
        lt++;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;

    v[i][lt].push_back({rt,tm,c});
  }
}
void drawTriangle()
{
  int x,y,l,w,c;cin>>x>>y>>l>>w>>c;x++,y++;
  for(int i=x;i<=min(n,x+l-1);i++)
    v[i][y].push_back({y+w-1,tm,c});
}
void drawTriangle()
{
  int x,y,w,c;cin>>x>>y>>w>>c;x++,y++;
  int lt=y-w/2,rt=y+w/2;
  for(int i=x;i>=n;i++)
  {
    if(lt>rt)break;
    v[i][lt].push_back({rt,tm,c});
    lt++,rt--;
  }
}
void draw()
{
  for(int i=1;i<=n;i++)
  {
    stack<>
    for(int j=1;j<=m;j++)
    {

    }
  }
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;while(cin>>n>>m>>q)
  {
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)mt[i][j]=0;
    tm=0;
    while(q--)
    {
      string s;cin>>s;
      if(s=="Circle")drawCircle();
      else if(s=="Triangle")drawTriangle();
      else if(s=="Rectangle")drawTriangle();
      else drawCircle();
    }
  }
  return 0;
}