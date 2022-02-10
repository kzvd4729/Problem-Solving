/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-21 17:53:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 120                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1397
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=9;
int mat[N+2][N+2],t,tc,cnt,ok;
int row[N+2],col[N+2],hm[N+2],rem[N+2][N+2];
char s[N+2];
void selector(void)
{
  for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
      rem[i][j]=1;
  for(int i=1;i<=3;i++)
    for(int j=4;j<=6;j++)
      rem[i][j]=2;
  for(int i=1;i<=3;i++)
    for(int j=7;j<=9;j++)
      rem[i][j]=3;


  for(int i=4;i<=6;i++)
    for(int j=1;j<=3;j++)
      rem[i][j]=4;
  for(int i=4;i<=6;i++)
    for(int j=4;j<=6;j++)
      rem[i][j]=5;
  for(int i=4;i<=6;i++)
    for(int j=7;j<=9;j++)
      rem[i][j]=6;


  for(int i=7;i<=9;i++)
    for(int j=1;j<=3;j++)
      rem[i][j]=7;
  for(int i=7;i<=9;i++)
    for(int j=4;j<=6;j++)
      rem[i][j]=8;
  for(int i=7;i<=9;i++)
    for(int j=7;j<=9;j++)
      rem[i][j]=9;
}
void dfs(int cnt)
{
  if(cnt==81)
  {
    for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
      {
        printf("%d",mat[i][j]);
      }
      printf("\n");
    }
    ok=1;
    return ;
  }
//cout<<endl;
//cout<<cnt<<endl;
//  for(int i=1;i<=N;i++)
//    {
//      for(int j=1;j<=N;j++)
//      {
//        printf("%d",mat[i][j]);
//      }
//      printf("\n");
//    }
//    getchar();
  if(ok)return ;
  int r,c,mn=10;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      if(mat[i][j]==0)
      {
        int here=0;
        for(int k=1;k<=9;k++)
        {
          int tmp1=row[i]^(1<<k);
          int tmp2=col[j]^(1<<k);
          int tmp3=hm[rem[i][j]]^(1<<k);
          if((tmp1&(1<<k))&&(tmp2&(1<<k))&&(tmp3&(1<<k)))here++;
        }
        if(here<mn)
        {
          mn=here;
          r=i;
          c=j;
        }
        ////cout<<here<<endl;
      }
    }
  }
  //cout<<mn<<endl;
//  cout<<r<<" "<<c<<endl;
//  getchar();
  if(mn==0)return ;
  int i=r;
  int j=c;
  for(int k=1;k<=N;k++)
  {
    if(ok)return ;
    if((row[i]&(1<<k))||(col[j]&(1<<k))||(hm[rem[i][j]]&(1<<k)))continue;
    mat[i][j]=k;
    row[i]|=(1<<k);
    col[j]|=(1<<k);
    hm[rem[i][j]]|=(1<<k);
    dfs(cnt+1);
    row[i]^=(1<<k);
    col[j]^=(1<<k);
    hm[rem[i][j]]^=(1<<k);
  }
  mat[i][j]=0;
  //getchar();
}
int main()
{
  selector();
  scanf("%d",&t);
  while(t--)
  {
    cnt=0;
    ok=0;
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    memset(hm,0,sizeof(hm));
    for(int i=1;i<=N;i++)
    {
      scanf("%s",s);
      for(int j=1;j<=N;j++)
      {
        if(s[j-1]=='.')
          mat[i][j]=0;
        else
        {
          cnt++;
          mat[i][j]=s[j-1]-'0';
          row[i]|=(1<<mat[i][j]);
          col[j]|=(1<<mat[i][j]);
          hm[rem[i][j]]|=(1<<mat[i][j]);
        }
      }
    }
    printf("Case %d:\n",++tc);
    dfs(cnt);
  }
  return 0;
}