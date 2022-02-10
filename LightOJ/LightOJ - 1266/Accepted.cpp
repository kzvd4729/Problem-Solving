/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-15 18:54:34                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 293                                        memory_used (MB): 7                               
*  problem: https://vjudge.net/problem/LightOJ-1266
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3+1;
int bit[N+2][N+2];bool vis[N+2][N+2];
void upd(int x,int y)
{
  for( ;x<=N;x+=x&-x)
  {
    int yy=y;
    for( ;y<=N;y+=y&-y)
      bit[x][y]++;
    y=yy;
  }
}
int get(int x,int y)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
  {
    int yy=y;
    for( ;y>0;y-=y&-y)
      ret+=bit[x][y];
    y=yy;
  }
  return ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int q;scanf("%d",&q);
    memset(bit,0,sizeof(bit));
    memset(vis,0,sizeof(vis));
    printf("Case %d:\n",++tc);
    while(q--)
    {
      int ty;scanf("%d",&ty);
      if(!ty)
      {
        int x,y;scanf("%d%d",&x,&y);x++,y++;
        if(vis[x][y])continue;
        upd(x,y);vis[x][y]=1;
      }
      else
      {
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        a++,b++,c++,d++;
        printf("%d\n",get(c,d)-get(a-1,d)-get(c,b-1)+get(a-1,b-1));
      }
    }
  }
  return 0;
}