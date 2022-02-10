/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-16 16:27:25                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1159
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=200;
const int con=100;
int t,tc;
char s[30],mat[30][30];
vector<int>adj[N+2]
void create_graph(int x)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(mat[i][j]=='G')
      {
        for(int k=j+1;k<=n;k++)
        {
          if(mat[i][k]=='#')break;
          if(abs(k-j)+2>x)break;
          if(mat[i][k]=='H')
          {
            adj[i+j].push_back(con+i+k);
            adj[con+i+k].push_back(i+j);
          }
        }
        for(int k=j-1;k>=1;k--)
        {
          if(mat[i][k]=='#')break;
          if(abs(k-j)+2>x)break;
          if(mat[i][k]=='H')
          {
            adj[i+j].push_back(con+i+k);
            adj[con+i+k].push_back(i+j);
          }
        }
        for(int k=i-1;k>=1;k--)
        {
          if(mat[k][j]=='#')break;
          if(abs(k-i)+2>x)break;
          if(mat[k][j]=='H')
          {
            adj[i+j].push_back(con+j+k);
            adj[con+j+k].push_back(i+j);
          }
        }
        for(int k=i+1;k<=n;k++)
        {
          if(mat[k][j]=='#')break;
          if(abs(k-i)+2>x)break;
          if(mat[k][j]=='H')
          {
            adj[i+j].push_back(con+j+k);
            adj[con+j+k].push_back(i+j);
          }
        }
      }
    }
  }
}
int main()
{
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%s",s);
      for(int j=1;j<=n;j++)
        mat[i][j]=s[j-1];
    }
    int lo=0,hi=1000,md;
    while(hi-lo>3)
    {
      md=(lo+hi)/2;
      create_graph(md);

    }
    printf("Case %d: %d\n",++tc,Hopcroft());
  }
  return 0;
}