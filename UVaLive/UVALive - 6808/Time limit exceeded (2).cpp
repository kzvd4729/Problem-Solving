/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-24 10:50:35                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6808
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
char mt[N+2][N+2];
bitset<N+2>bt[3][N+2],pt[3][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
    {
      mt[i][j]=s[j-1];
      if(mt[i][j]=='G')bt[1][i][j]=1;
      else bt[2][i][j]=1;
    }
  }
  int q,tc=0;cin>>q;
  while(q--)
  {
    int x,y;cin>>x>>y;
    for(int i=1;i<=x;i++)
    pt[1][i].reset(),pt[2][i].reset();
    for(int i=1;i<=x;i++)
    {
      string s;cin>>s;
      for(int j=1;j<=y;j++)
      {
        mt[i][j]=s[j-1];
        if(mt[i][j]=='G')pt[1][i][j]=1;
        else pt[2][i][j]=1;
      }
    }
    int mx=-1,a=-1,b=-1,gg,ll;
    for(int i=1;i<=n;i++)
    {
      if(i+x-1>n)break;
      for(int j=1;j<=m;j++)
      {
        if(j+y-1>m)break;int now=0,g=0,l=0;
        for(int ii=i;ii<i+x;ii++)
        {
          int one=((bt[1][ii]>>(j-1))&pt[1][ii-i+1]).count();
          int two=((bt[2][ii]>>(j-1))&pt[2][ii-i+1]).count();
          g+=one,l+=two;now+=one+two;
        }
        if(now>mx)
        {
          mx=now,a=i,b=j;
          gg=g,ll=l;
        }
      }
    }
    cout<<"Case #"<<++tc<<": "<<a<<" "<<b<<" "<<gg<<" "<<ll<<"\n";
  }
  return 0;
}