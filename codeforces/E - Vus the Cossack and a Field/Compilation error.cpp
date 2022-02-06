/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/01/2019 11:07                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1186/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const int N=1e3;
const long R=1e9;
int mt[N+2][N+2],qm[N+2][N+2];
long level[N+2],a,b,c,d;
int build(int n,int m)
{
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      qm[i][j]=mt[i][j]+qm[i][j-1];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      qm[i][j]=qm[i][j]+qm[i-1][j];
}
int get(int a,int b,int c,int d)
{
  return qm[c][d]-qm[a-1][d]-qm[c][b-1]+qm[a-1][b-1];
}
long dvd(int x,int y,int lv,int a,int b,int c,int d)
{
  if(lv==1)
  {
      }
  if(a==1&&b==1&&c==x&&d==y)return level[lv]
}
dont compile
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
      mt[i][j]=s[j-1]-'0';
  }
  build(n,m);
  while(q--)
  {
    cin>>a>>b>>c>>d;
    long lv=1,dn=n,dm=m;
    while(true)
    {
      if(c<=n&&d<=m)break;
      dn*=2,dm*=2;lv++;
    }
      }
  return 0;
}