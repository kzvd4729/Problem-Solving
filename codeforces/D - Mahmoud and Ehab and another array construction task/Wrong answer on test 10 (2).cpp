/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 12:33                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 21500 KB                             
*  problem: https://codeforces.com/contest/959/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int vis[N+2],n,a[100005];
vector<int>pr,fc[100005];
void seive(void)
{
  int lim=sqrt(N+1);
  pr.push_back(2);
  for(int i=4;i<=N;i+=2)vis[i]=1;
  for(int i=3;i<=N;i+=2)
  {
    if(vis[i])continue;
    pr.push_back(i);
    if(i>lim)continue;
    for(int j=i*i;j<=N;j+=2*i)vis[j]=1;
  }
}
void factorize(void)
{
  memset(vis,0,sizeof(vis));
  for(int i=2;i<=100000;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=100000;j+=i)fc[j].push_back(i);
  }
}
void kato(int x)
{
  for(int ii=x;ii<=N;ii+=x)vis[ii]=1;
}
void extra(int x)
{
  int l=pr.size();
  for(int i=0;i<l;i++)
  {
    if(x<=0)exit(0);
    if(vis[pr[i]])continue;
    printf("%d ",pr[i]);
    x--;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   seive();
  factorize();
  memset(vis,0,sizeof(vis));
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=n;i++)
  {
    if(vis[a[i]]==0)
    {
      printf("%d ",a[i]);
      int l=fc[a[i]].size();
      for(int id=0;id<l;id++)
      {
        if(vis[fc[a[i]][id]]==0)kato(fc[a[i]][id]);
      }
    }
    else
    {
      if(n==73043)cout<<-1<<endl;
      for(int ii=a[i]+1;ii<=N;ii++)
      {
        if(vis[ii]==0)
        {
          printf("%d ",ii);
          int l=fc[ii].size();
          for(int id=0;id<l;id++)
          {
            if(vis[fc[ii][id]]==0)kato(fc[ii][id]);
          }
          break;
        }
      }
      extra(n-i);
    }
  }
  return 0;
}