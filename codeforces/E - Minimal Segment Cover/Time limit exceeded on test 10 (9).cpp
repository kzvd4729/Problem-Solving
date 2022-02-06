/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2019 22:51                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 259500 KB                            
*  problem: https://codeforces.com/contest/1175/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5,pas=320;
int aa[N+2],mx[N+2],nex[200000+2][pas+2],con[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<int>tmp;
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;
    aa[a]=max(aa[a],b);
    tmp.push_back(b);
  }
  sort(tmp.begin(),tmp.end());
  tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
  for(int i=0;i<tmp.size();i++)
    con[tmp[i]]=i+1;
  mx[0]=aa[0];
  for(int i=1;i<=N;i++)
    mx[i]=max(mx[i-1],aa[i]);
  for(int i=0;i<=N;i++)
  {
    int id=con[i];if(!id)continue;
    nex[id][1]=mx[i];
    for(int j=2;j<=pas;j++)
    {
      nex[id][j]=mx[nex[id][j-1]];
    }
  }
  while(m--)
  {
    int x,y;cin>>x>>y;
    int pr=0,ans=0,f=0;
    x=mx[x];ans++;
    if(x>=y)
    {
      cout<<ans<<" ";continue;
    }
    while(true)
    {
      if(nex[con[x]][pas]==pr){f=1;break;}
      if(nex[con[x]][pas]>=y)
      {
        int lo=1,hi=pas,md;
        while(hi-lo>2)
        {
          md=(lo+hi)/2;
          if(nex[con[x]][md]>=y)hi=md;
          else lo=md;
        }
        for(md=lo;md<=hi;md++)
          if(nex[con[x]][md]>=y)break;
        ans+=md;break;
      }
      else
      {
        int nx=nex[con[x]][pas];
        if(nx==pr){f=1;break;}
        pr=nx;x=nex[con[x]][pas];
        ans+=pas;
      }
    }
    if(f)cout<<-1<<" ";
    else cout<<ans<<" ";
  }
  return 0;
}