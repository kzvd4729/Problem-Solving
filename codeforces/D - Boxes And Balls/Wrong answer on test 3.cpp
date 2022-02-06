/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 12:16                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/884/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+1];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;priority_queue<long>pq;long sm=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];sm+=aa[i];
  }
  sort(aa+1,aa+n+1);long ans=0;pq.push(sm);
  int id=n;
  while(id)
  {
    long x=pq.top();pq.pop();
    if(x==aa[id])id--;
    else
    {
      ans+=x;long md=x/3;
      if(aa[id]<md)
      {
        pq.push(md);x-=md;md=x/2;pq.push(md);
        x-=md;pq.push(x);
      }
      else
      {
        x-=aa[id];id--;if(id==0)break;
        md=x/2;
        if(aa[id]<md)
        {
          pq.push(md);pq.push(x-md);
        }
        else
        {
          pq.push(x-aa[id]);id--;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}