/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2019 00:23                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1186/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3;
const long R=1e9;
long mt[N+2][N+2],qm[N+2][N+2];
long level[N+2],a,b,c,d;
long build(long n,long m)
{
  for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
      qm[i][j]=mt[i][j]+qm[i][j-1];
  for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
      qm[i][j]=qm[i][j]+qm[i-1][j];
}
long get(long a,long b,long c,long d)
{
  return qm[c][d]-qm[a-1][d]-qm[c][b-1]+qm[a-1][b-1];
}
long dvd(long x,long y,long lv,long a,long b,long c,long d,long rv)
{
  if(lv==1)
  {
    long ok=get(a,b,c,d);
    if(rv)ok=(c-a+1)*(d-b+1)-ok;
    return ok;
  }
  if(a==1&&b==1&&c==x&&d==y)return level[lv];
  long xx=x/2,yy=y/2;
  long ret=0;
  if(a<=xx&&b<=yy)
  {
    ret+=dvd(xx,yy,lv-1,a,b,min(c,xx),min(d,yy),rv);
    //if(lv==2)cout<<a<<" "<<b<<" "<<min(c,xx)<<" "<<min(d,yy)<<endl;
  }
  if(a<=xx&&d>yy)
  {
    ret+=dvd(xx,yy,lv-1,a,max(1LL,b-yy),min(c,xx),d-yy,rv^1);
    //if(lv==3)cout<<"here"<<endl;
  }
  if(c>xx&&b<=yy)
  {
    ret+=dvd(xx,yy,lv-1,max(1LL,a-xx),b,c-xx,min(d,yy),rv^1);
    //if(lv==3)cout<<"here"<<endl;
  }
  if(c>xx&&d>yy)
  {
    ret+=dvd(xx,yy,lv-1,max(1LL,a-xx),max(1LL,b-yy),c-xx,d-yy,rv);
    /*if(lv==3)
    {
      cout<<max(1LL,a-xx)<<" "<<max(1LL,b-yy)<<" "<<c-xx<<" "<<d-yy<<endl,exit(0);
    }*/
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,q;cin>>n>>m>>q;long one=0,zero=0;
  for(long i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(long j=1;j<=m;j++)
    {
      mt[i][j]=s[j-1]-'0';
      one+=mt[i][j];
    }
  }
  zero=n*m-one;
  build(n,m);level[1]=one;
  for(long i=2;i<=60;i++)
  {
    one=one+one+zero+zero;zero=one;
    level[i]=one;
  }
  /*for(int i=1;i<=5;i++)
    cout<<level[i]<<" ";
  cout<<endl;*/
  while(q--)
  {
    cin>>a>>b>>c>>d;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    long lv=1,dn=n,dm=m;
    while(true)
    {
      if(c<=dn&&d<=dm)break;
      dn*=2,dm*=2;lv++;
    }
    //cout<<dn<<" "<<dm<<endl;
    cout<<dvd(dn,dm,lv,a,b,c,d,0)<<"\n";
  }
  return 0;
}