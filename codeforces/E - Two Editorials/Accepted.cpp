/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2020 22:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1452/problem/E
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
const int N=2e3;
int sm[N+2];
void add1(int l,int r,int vl)
{
  sm[l]+=vl;sm[r+1]-=vl;
}
vector<int>bf[N+2];int die[N+2];
void add2(int l,int vl)
{
  bf[l].push_back(vl);
  die[l+vl]++;
}
vector<int>fb[N+2];int dei[N+2];
void add3(int r,int vl)
{
  fb[r].push_back(vl);
  dei[max(r-vl,0)]++;
}
int cal(int n)
{
  for(int i=1;i<=n;i++)sm[i]+=sm[i-1];
  int s=0,a=0;
  for(int i=1;i<=n;i++)
  {
    s-=a;for(auto x:bf[i])a++,s+=x;
    a-=die[i];sm[i]+=s;
  }
  s=0,a=0;
  for(int i=n;i>=1;i--)
  {
    s-=a;for(auto x:fb[i])a++,s+=x;
    a-=dei[i];sm[i]+=s;
  }
  return *max_element(sm+1,sm+n+1);
}
void clear(int n)
{
  for(int i=0;i<=n+1;i++)
    sm[i]=0,bf[i].clear(),die[i]=0,fb[i].clear(),dei[i]=0;
}
int l[N+2],r[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)cin>>l[i]>>r[i];
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    int now=0;
    for(int j=1;j<=m;j++)
    {
      int x=max(i,l[j]),y=min(i+k-1,r[j]);
      int fr=max(0,y-x+1);now+=fr;
       if(fr==k||fr==r[j]-l[j]+1)continue;
       if(l[j]-r[j]+1>=k)
      {
        int id=r[j]-k+1;
        if(k-fr>0)add1(l[j],id,k-fr);
        if(k-1-fr>0)add2(id+1,k-1-fr),add3(l[j]-1,k-1-fr);
      }
      else
      {
        int id=max(r[j]-k+1,1);
        if(r[j]-l[j]+1-fr>0)add1(id,l[j],r[j]-l[j]+1-fr);
        if(r[j]-l[j]+1-fr-1>0)
          add2(l[j]+1,r[j]-l[j]+1-fr-1),add3(id-1,r[j]-l[j]+1-fr-1);
      }
    }
    ans=max(ans,now+cal(n));
    clear(n);
  }
  cout<<ans<<endl;
  return 0;
}