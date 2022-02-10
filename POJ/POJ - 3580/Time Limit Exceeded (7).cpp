/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-28 20:52:45                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-3580
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
//#include<unordered_map>
//#include<unordered_set>
//#include<chrono>
#include<stack>
#include<deque>
//#include<random>
#define long long long 
using namespace std;
const long N=2e5;
const long inf=1e18;

void tle(){for(int i=1; ;i++);}

vector<long>a;long tmp[N+2];
void add(long x,long y,long d)
{
  //assert(d>=0);
  for(int i=x;i<=y;i++)a[i]+=d;
}
void reverse(long x,long y)
{
  int id=0;
  for(int i=x;i<=y;i++)tmp[++id]=a[i];
  id=0;
  for(int i=y;i>=x;i--)
    a[i]=tmp[++id];
}
void revolve(long x,long y,long t)
{
  //assert(t<=(y-x+1));
  //if(t<0||t>y-x+1)tle();
  t=(t%(y-x+1)+y-x+1)%(y-x+1);
  if(t==0)return ;
  int id=0;
  for(int i=y-t+1;i<=y;i++)tmp[++id]=a[i];
  for(int i=x;i<y-t+1;i++)tmp[++id]=a[i];

  id=0;
  for(int i=x;i<=y;i++)a[i]=tmp[++id];
}
void insert(long x,long vl)
{
  a.insert(a.begin()+x+1,vl);
}
void del(long x)
{
  a.erase(a.begin()+x);
}
long mini(long x,long y)
{
  long mn=inf;
  for(int i=x;i<=y;i++)mn=min(mn,a[i]);
  return mn;
}
int main()  
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //init();//assert(0);

  a.push_back(0);

  long n;cin>>n;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    insert(i-1,x);
  }
  long m;cin>>m;
  while(m--)
  {
    string s;cin>>s;
    if(s=="ADD")
    {
      long x,y,d;cin>>x>>y>>d;
      add(x,y,d);
    }
    else if(s=="REVERSE")
    {
      long x,y;cin>>x>>y;
      reverse(x,y);
    }
    else if(s=="REVOLVE")
    {
      long x,y,t;cin>>x>>y>>t;
      revolve(x,y,t);
    }
    else if(s=="INSERT")
    {
      long x,p;cin>>x>>p;
      insert(x,p);
    }
    else if(s=="DELETE")
    {
      long x;cin>>x;
      del(x);
    }
    else 
    {
      long x,y;cin>>x>>y;
      cout<<mini(x,y)<<endl;
    }
  }
  return 0;
}