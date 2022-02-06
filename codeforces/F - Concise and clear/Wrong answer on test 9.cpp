/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2020 13:22                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/991/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
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
#include<random>
#define long long long
using namespace std;
const int N=1e6;
string dp[N+2];
int d(long n)
{
  int r=0;
  while(n)r++,n/=10;
  return r;
}
int ans;string pr;
string con(long n)
{
  string tmp;
  while(n)
  {
    tmp.push_back((char)((n%10)+'0'));
    n/=10;
  }
  reverse(tmp.begin(),tmp.end());
  return tmp;
}
void upd(long ml,long b,long p,long ad)
{
  string tmp;
  if(ml>1)
  {
    tmp=con(ml);tmp.push_back('*');
  }
  tmp+=con(b);tmp.push_back('^');
  tmp+=con(p);
  if(ad)
  {
    tmp.push_back('+');tmp+=con(ad);
  }
  if(tmp.size()<ans)ans=tmp.size(),pr=tmp;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;ans=d(n);pr=con(n);
  for(int i=2;i<=n;i++)
  {
    if(1LL*i*i>n)break;
     long p=i;int di=d(i);
    for(int j=2; ;j++)
    {
      p*=i;if(p>n)break;
      upd(1,i,j,n-p);int dj=d(j);
      if(n%p==0)upd(n/p,i,j,0);
            for(long ml=2; ;ml++)
      {
        if(p*ml>n)break;
        if(di+1+dj+1+d(ml)+2>=ans)break;
        upd(ml,i,j,n-p*ml);
      }
    }
  }
  cout<<pr<<endl;
  return 0;
}