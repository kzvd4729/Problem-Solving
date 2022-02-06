/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2019 18:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1278 ms                                         memory_used: 48100 KB                             
*  problem: https://codeforces.com/contest/1083/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
 /************ Convex Hull Trick ***********/
int hsz,cur;
const long inf=2e18;
struct line
{
  long m,c;
};
vector<line>hull;
bool isBad(line &p,line &q,line &r)
{
  return (p.c-r.c)*1.0/(r.m-p.m)>=(p.c-q.c)*1.0/(q.m-p.m);
  //return (p.c-q.c)*(r.m-p.m)>=(p.c-r.c)*(q.m-p.m);//Overflow
}
void addLine(long m,long c)
{
  m*=-1LL,c*=-1LL;
  if((int)hull.size()&&hull.back().m==m)
  {
    if(hull.back().c>c)hull.pop_back();
    else return ;
  }
  hull.push_back({m,c});hsz++;
  while(hsz>2&&isBad(hull[hsz-3],hull[hsz-2],hull[hsz-1]))
  {
    swap(hull[hsz-2], hull[hsz-1]);
    hull.pop_back();hsz--;
  }
}
long Qry1(long x)
{
  if(hsz==0)assert(0);
  int l=-1,r=hsz-1;
  while(r-l>1)
  {
    int m=(l+r)/2;
    if(hull[m].m*x+hull[m].c>=hull[m+1].m*x+hull[m+1].c)
      l=m;
    else r=m;
  }
  return -(hull[r].m*x+hull[r].c);
}
long Qry2(long x)
{
  if(hsz==0)assert(0);
  if(cur>=hsz)cur=hsz-1;
  while(cur+1<hsz)
  {
    if(hull[cur].m*x+hull[cur].c>hull[cur+1].m*x+hull[cur+1].c)
      cur++;
    else break;
  }
  return -(hull[cur].m*x+hull[cur].c);
}
////////////////////////////////////////////
struct data
{
  long a,b,c;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.a<B.a;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i].a>>aa[i].b>>aa[i].c;
  sort(aa+1,aa+n+1,cmp);addLine(0,0);long ans=0;
  for(int i=1;i<=n;i++)
  {
    long now=Qry1(aa[i].b)+aa[i].a*aa[i].b-aa[i].c;
    addLine(-aa[i].a,now);ans=max(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}