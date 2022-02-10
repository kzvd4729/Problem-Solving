/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 23:31:12                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-5698
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e4;
int n,m,mt[200+2][N+2],par[200+2][N+2],cnt[10+2];
int get(int id,int x)
{
  if(par[id][x]==x)return x;
  return par[id][x]=get(id,par[id][x]);
}
void upd(int id,int lt,int rt,int c)
{
  if(id>n||id<1)return ;
  lt=max(lt,1),rt=min(rt,m);
  while(lt<=rt)
  {
    int p=get(id,lt);if(p>rt)return ;
    mt[id][p]=c;par[id][p]=p+1;lt=p+1;
  }
}
void print()
{
//  for(int i=1;i<=n;i++)
//  {
//    for(int j=1;j<=m;j++)
//      cout<<mt[i][j]<<" ";
//    cout<<endl;
//  }
//  cout<<endl;
  memset(cnt,0,sizeof(cnt));
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cnt[mt[i][j]]++;
  for(int i=1;i<10;i++)
  {
    if(i>1)cout<<" ";
    cout<<cnt[i];
  }
  cout<<endl;
}
string s[N+2];vector<vector<int> >qr;
void drawRectangle(int id)
{
  int x=qr[id][0],y=qr[id][1],l=qr[id][2],w=qr[id][3],c=qr[id][4];x++,y++;
  for(int i=x;i<=min(n,x+l-1);i++)
    upd(i,y,y+w-1,c);
}
void drawTriangle(int id)
{
  int x=qr[id][0],y=qr[id][1],w=qr[id][2],c=qr[id][3];x++,y++;
  //if(w%2==0)assert(0);
  int lt=y-(w-1)/2,rt=y+(w-1)/2;
  for(int i=x;i<=n;i++)
  {
    if(lt>rt)break;upd(i,lt,rt,c);
    lt++,rt--;
  }
}
void drawCircle(int id)
{
  int x=qr[id][0],y=qr[id][1],r=qr[id][2],c=qr[id][3];x++,y++;
  int lt=y-r,rt=y+r;upd(x,lt,rt,c);
  for(int i=x+1;i<=n;i++)
  {
    while(true)
    {
      if((1LL*(x-i))*(x-i)+(1LL*(rt-y))*(rt-y)>1LL*r*r)
        rt--;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;
    while(true)
    {
      if((1LL*(x-i))*(x-i)+(1LL*(lt-y))*(lt-y)>1LL*r*r)
        lt++;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;
    upd(i,lt,rt,c);
  }
  lt=y-r,rt=y+r;
  for(int i=x-1;i>=1;i--)
  {
    while(true)
    {
      if((1LL*(x-i))*(x-i)+(1LL*(rt-y))*(rt-y)>1LL*r*r)
        rt--;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;
    while(true)
    {
      if((1LL*(x-i))*(x-i)+(1LL*(lt-y))*(lt-y)>1LL*r*r)
        lt++;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;

    upd(i,lt,rt,c);
  }
}
void drawDiamond(int id)
{
  int x=qr[id][0],y=qr[id][1],r=qr[id][2],c=qr[id][3];x++,y++;
  int lt=y-r,rt=y+r;upd(x,lt,rt,c);
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

    upd(i,lt,rt,c);
  }
  lt=y-r,rt=y+r;
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
      if(abs(x-i)+abs(lt-y)>r)
        lt++;
      else break;if(lt>rt)break;
    }
    if(lt>rt)break;

    upd(i,lt,rt,c);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;while(cin>>n>>m>>q)
  {
    for(int i=0;i<=n+1;i++)
      for(int j=0;j<=m+1;j++)mt[i][j]=0,par[i][j]=j;
    qr.resize(q);
    for(int i=0;i<q;i++)
    {
      cin>>s[i];
      if(s[i]=="Rectangle")
      {
        qr[i].resize(5);
        for(int j=0;j<5;j++)cin>>qr[i][j];
      }
      else
      {
        qr[i].resize(4);
        for(int j=0;j<4;j++)cin>>qr[i][j];
      }
    }
    for(int i=q-1;i>=0;i--)
    {
      if(s[i]=="Rectangle")drawRectangle(i);
      if(s[i]=="Triangle")drawTriangle(i);
      if(s[i]=="Circle")drawCircle(i);
      if(s[i]=="Diamond")drawDiamond(i);
    }
    print();
  }
  return 0;
}