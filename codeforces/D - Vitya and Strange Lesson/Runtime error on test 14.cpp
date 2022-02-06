/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2019 19:56                        
*  solution_verdict: Runtime error on test 14                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 5900 KB                              
*  problem: https://codeforces.com/contest/842/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int cnt=2;
const int N=3e5;
int tr[N+2][4],nw,vis[N+2];
void add(int x)
{
  int now=0;
  for(int i=20;i>=0;i--)
  {
    bool z=x&(1<<i);
    if(!tr[now][z])tr[now][z]=++nw;
    tr[now][z+cnt]++;
    //cout<<tr[now][z+cnt]<<endl;
    now=tr[now][z];
  }
  //cout<<" nw "<<nw<<endl;
}
int qry(int x,int md)
{
  int now=0,ret=0,tt=0;
  for(int i=20;i>=0;i--)
  {
    bool z=x&(1<<i);
    if((ret|(1<<i))<=md)
    {
      tt+=tr[now][z+cnt];ret|=(1<<i);
      now=tr[now][z^1];
    }
    else now=tr[now][z];
     if(now==0)return tt;
    //cout<<"        "<<now<<endl;
  }
  return tt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;if(vis[x])continue;
    add(x);vis[x]=1;
  }
  int xx=0;
  while(m--)
  {
    int x;cin>>x;xx^=x;
    /*if(!vis[xx])
    {
      cout<<0<<endl;continue;
    }*/
    int lo=1,hi=3e5,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      //cout<<lo<<" "<<hi;
      if(qry(xx,md)==md)lo=md;
      else hi=md;
       //cout<<" "<<qry(xx,md)<<endl;
    }
    for(md=lo;md<=hi;md++)
    {
      //cout<<md<<" "<<qry(xx,md)<<endl;
      if(qry(xx,md)<md)
      {
        cout<<md-1<<"\n";break;
      }
    }
  }
  return 0;
}