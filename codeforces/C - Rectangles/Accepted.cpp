/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2018 12:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1248 ms                                         memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/1028/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const int inf=2e9;
int qs,n;
struct data
{
 int a,b,c,d;
}arr[N+2],sq[N+2],xx,yy,zz;
data intersect(data xx,data yy)
{
 data zz;zz.a=-inf,zz.c=inf,zz.b=-inf,zz.d=inf;
 if(xx.a<=yy.a&&xx.b<=yy.b&&xx.c>=yy.c&&xx.d>=yy.d)return yy;
 swap(xx,yy);
 if(xx.a<=yy.a&&xx.b<=yy.b&&xx.c>=yy.c&&xx.d>=yy.d)return yy;
 if(xx.a>yy.a)swap(xx,yy);
 zz.a=yy.a;zz.c=xx.c;
 if(xx.b>yy.b)swap(xx,yy);
 zz.b=yy.b;zz.d=xx.d;
 if(zz.a>zz.c||zz.b>zz.d)zz.a=inf;
 return zz;
}
data segment(int lt,int rt,int sk)
{
 data zz;
 zz.a=-inf,zz.c=inf,zz.b=-inf,zz.d=inf;
 for(int i=lt;i<=rt;i++)
 {
  if(i==sk)continue;
  xx=zz;yy=arr[i];
  zz=intersect(xx,yy);
 }
 //cout<<lt<<" "<<rt<<" "<<sk<<" "<<zz.a<<" "<<zz.b<<" "<<zz.c<<" "<<zz.d<<endl;
 return zz;
}
void whore(void)
{
 for(int i=0;i<=n;i++)
 {
  int l=qs*i,r=qs*(i+1)-1;
  l=max(l,1);r=min(r,n);
  if(l>n)break;
  sq[i]=segment(l,r,-1);
 }
 for(int j=1;j<=n;j++)
 {
  zz.a=-inf,zz.c=inf,zz.b=-inf,zz.d=inf;
  for(int i=0;i<=n;i++)
  {
   int l=qs*i,r=qs*(i+1)-1;
   l=max(l,1);r=min(r,n);
   if(l>n)break;
   if(j>=l&&j<=r)yy=segment(l,r,j);
   else yy=sq[i];xx=zz;
   if(yy.a>yy.c||yy.b>yy.d)
   {
    zz.a=inf;
    break;
   }
   //cout<<zz.a<<" "<<zz.b<<" "<<zz.c<<" "<<zz.d<<endl;
   //cout<<xx.a<<" "<<xx.b<<" "<<xx.c<<" "<<xx.d<<endl;
   //cout<<yy.a<<" "<<yy.b<<" "<<yy.c<<" "<<yy.d<<endl;
   zz=intersect(xx,yy);
   //cout<<" "<<zz.a<<" "<<zz.b<<" "<<zz.c<<" "<<zz.d<<endl;
   if(zz.a==inf)break;
  }
  if(zz.a!=inf)cout<<zz.a<<" "<<zz.b<<endl,exit(0);
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n;qs=sqrt(n+1);
 for(int i=1;i<=n;i++)
  cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d;
 whore();
 return 0;
}