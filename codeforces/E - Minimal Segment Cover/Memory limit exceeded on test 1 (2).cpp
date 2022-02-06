/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2019 21:17                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/1175/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5,pas=140;
int aa[N+2],mx[N+2],nex[N+2][pas+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;
    aa[a]=max(aa[a],b);
  }
  mx[0]=aa[0];
  for(int i=1;i<=N;i++)
    mx[i]=max(mx[i-1],aa[i]);
  for(int i=0;i<=N;i++)
  {
    nex[i][1]=mx[i];
    for(int j=2;j<=pas;j++)
    {
      nex[i][j]=mx[nex[i][j-1]];
    }
  }
  /*for(int i=0;i<=10;i++)
  {
    for(int j=1;j<=3;j++)
    {
      cout<<nex[i][j]<<" ";
    }
    cout<<endl;
  }*/
  while(m--)
  {
    int x,y;cin>>x>>y;
    int pr=0,ans=0,f=0;
    while(true)
    {
      if(nex[x][pas]==pr){f=1;break;}
      if(nex[x][pas]>=y)
      {
        while(true)
        {
          x=nex[x][1];ans++;
          if(x>=y)break;
        }
        break;
      }
      else
      {
        int nx=nex[x][pas];
        if(nx==pr){f=1;break;}
        pr=nx;x=nex[x][pas];
        ans+=pas;
      }
    }
    if(f)cout<<-1<<"\n";
    else cout<<ans<<"\n";
  }
  return 0;
}