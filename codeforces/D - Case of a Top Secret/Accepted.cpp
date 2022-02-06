/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/15/2020 17:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/555/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
int po[N+2],aa[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>pp[i].first,pp[i].second=i;
   sort(pp+1,pp+n+1);
  for(int i=1;i<=n;i++)aa[i]=pp[i].first,po[pp[i].second]=i;
  //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  while(m--)
  {
    int id,l;cin>>id>>l;id=po[id];int f=1;
    while(true)
    {
      int a=0,b=0;
      if(id<n&&aa[id]+l>=aa[id+1])a=1;
      if(id>1&&aa[id-1]+l>=aa[id])b=1;
      if(!(a+b)){cout<<pp[id].second<<"\n";break;}
      if(f)
      {
        int tm=upper_bound(aa+1,aa+n+1,aa[id]+l)-aa;tm--;
        int an=lower_bound(aa+1,aa+n+1,aa[tm]-(l-(aa[tm]-aa[id])))-aa;
         if(an==id)
        {
          int c=l/(aa[tm]-aa[id]);l%=(aa[tm]-aa[id]);
          if(c%2)id=tm,f^=1;
        }
        else
        {
          l-=(aa[tm]-aa[id]),f^=1,id=tm;
        }
      }
      else
      {
        int tm=lower_bound(aa+1,aa+n+1,aa[id]-l)-aa;
        int an=upper_bound(aa+1,aa+n+1,aa[tm]+(l-(aa[id]-aa[tm])))-aa;an--;
         if(an==id)
        {
          int c=l/(aa[id]-aa[tm]);l%=(aa[id]-aa[tm]);
          if(c%2)id=tm,f^=1;
        }
        else
        {
          l-=(aa[id]-aa[tm]),f^=1,id=tm;
        }
      }
    }
  }
  return 0;
}