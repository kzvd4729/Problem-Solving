/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2020 22:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 29200 KB                             
*  problem: https://codeforces.com/contest/1450/problem/D
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
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=3e5;
int a[N+2];
int sp[N+2][20+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=a[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     int lo=2,hi=n,md;build(n);
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      for(int i=1;i<=n;i++)vs[i]=0;
      int cnt=0;
      for(int i=1;i<=n-md+1;i++)
        vs[get(i,i+md-1)]=1,cnt++;
      int f=0;
      for(int i=1;i<=cnt;i++)if(vs[i]==0)f=1;
      if(f)lo=md;else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      for(int i=1;i<=n;i++)vs[i]=0;
      int cnt=0;
      for(int i=1;i<=n-md+1;i++)
        vs[get(i,i+md-1)]=1,cnt++;
      int f=0;
      for(int i=1;i<=cnt;i++)if(vs[i]==0)f=1;
      if(f==0)break;
    }
    //cout<<md<<endl;
    string s;
    for(int i=1;i<=n;i++)s.push_back('0');
    for(int i=md;i<=n;i++)s[i-1]='1';
     sort(a+1,a+n+1);int f=0;
    for(int i=1;i<=n;i++)if(a[i]!=i)f=1;
    if(f==0)s[0]='1';
    cout<<s<<endl;
  } 
  return 0;
}