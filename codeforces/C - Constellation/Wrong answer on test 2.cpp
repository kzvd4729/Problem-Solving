/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2018 14:46                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 900 KB                               
*  problem: https://codeforces.com/contest/618/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
struct data
{
  int x,y,id;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.x<B.x;
}
bool ok(data a,data b,data c)
{
  a.x-=c.x;b.x-=c.x;
  a.y-=c.y;b.y-=c.y;
  return a.x*1LL*b.y-b.x*1LL*c.y;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i].x>>aa[i].y;
    aa[i].id=i;
  }
  sort(aa+1,aa+n+1,cmp);
  for(int i=1;i<=n-2;i++)
  {
    if(ok(aa[i],aa[i+1],aa[i+2]))
    {
      cout<<aa[i].id<<" "<<aa[i+1].id<<" "<<aa[i+2].id<<endl;
      exit(0);
    }
  }
  return 0;
}