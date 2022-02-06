/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2019 20:22                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/849/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],vis[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;
 for(int i=1;i<=n;i++)cin>>aa[i];
 for(int i=2;i<=n;i++)
 {
  int sly=aa[i]-aa[1],slx=i-1;
  int gc=__gcd(abs(sly),slx);int okb=sly,oka=slx;
  sly/=gc;slx/=gc;memset(vis,0,sizeof(vis));
  for(int j=2;j<=n;j++)
  {
   int slb=aa[j]-aa[1],sla=j-1;
   int gc=__gcd(abs(slb),sla);
   slb/=gc;sla/=gc;
   if(sla==slx&&slb==sly)
    vis[j]=1;
  }
  int f=-1,k=-1;
  for(int j=2;j<=n;j++)
  {
   if(vis[j])continue;
   f=j;break;
  }
  if(f==-1)continue;
  for(int j=f+1;j<=n;j++)
  {
   if(vis[j])continue;
   sly=aa[j]-aa[f],slx=j-f;
   int gc=__gcd(abs(sly),slx);
   sly/=gc;slx/=gc;k=j;break;
  }
  if(sly!=okb||slx!=oka)continue;
  if(k==-1)cout<<"Yes"<<endl,exit(0);
  int bad=0;
  for(int j=k+1;j<=n;j++)
  {
   if(vis[j])continue;
   int slb=aa[j]-aa[f],sla=j-f;
   int gc=__gcd(abs(slb),sla);
   slb/=gc;sla/=gc;
   if(sla!=slx||slb!=sly)
    bad=1;
  }
  if(!bad)cout<<"Yes"<<endl,exit(0);
 }
 memset(vis,0,sizeof(vis));
 int f=-1,k=-1;
 for(int j=2;j<=n;j++)
 {
  if(vis[j])continue;
  f=j;break;
 }
 int slx,sly;
 for(int j=f+1;j<=n;j++)
 {
  if(vis[j])continue;
  sly=aa[j]-aa[f],slx=j-f;
  int gc=__gcd(abs(sly),slx);
  sly/=gc;slx/=gc;k=j;break;
 }
 if(k==-1)cout<<"Yes"<<endl,exit(0);
 int bad=0;
 for(int j=k+1;j<=n;j++)
 {
  if(vis[j])continue;
  int slb=aa[j]-aa[f],sla=j-f;
  int gc=__gcd(abs(slb),sla);
  slb/=gc;sla/=gc;
  if(sla!=slx||slb!=sly)
   cout<<"No"<<endl,exit(0);
 }
 int slb=aa[2]-aa[1],sla=2-1;
 int gc=__gcd(abs(slb),sla);
 slb/=gc;sla/=gc;
 if(slb!=sly||sla!=slx)cout<<"Yes"<<endl,exit(0);
 cout<<"No"<<endl;
 return 0;
}