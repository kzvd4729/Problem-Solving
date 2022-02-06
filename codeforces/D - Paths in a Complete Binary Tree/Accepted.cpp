/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/01/2018 19:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/792/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long pw[100],h,n,q,r,lu,lv,st,u;
string s;
void power_of_two(void)
{
  pw[0]=1LL;
  for(int i=1; ;i++)
  {
    pw[i]=pw[i-1]*2LL;
    if(pw[i]>=1e18)break;
  }
}
long tree_height(void)
{
  for(int i=0; ;i++)if(pw[i]==n)return i-1;
}
void find_height_state(void)
{
  r=n/2;
  lu=h;
  st=0;
  while(true)
  {
    if(r==u)return ;
    else if(r<u)r+=pw[--lu],st=1;
    else r-=pw[--lu],st=-1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   power_of_two();
  cin>>n>>q;
  n++;
  h=tree_height();
   while(q--)
  {
    cin>>u>>s;
    find_height_state();
    lv=lu;
    //cout<<lv<<endl;
    for(auto x:s)
    {
      if(x=='U')
      {
        find_height_state();
        if(st==0)continue;
        if(st==1)u-=pw[lv++];
        else u+=pw[lv++];
      }
      else if(x=='L')
      {
        if(lv==0)continue;
        u-=pw[--lv];
      }
      else
      {
        if(lv==0)continue;
        u+=pw[--lv];
      }
    }
    cout<<u<<endl;
  }
  return 0;
}