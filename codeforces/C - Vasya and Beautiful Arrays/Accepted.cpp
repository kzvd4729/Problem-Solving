/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/13/2018 12:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/354/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,bit[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    bit[x]+=vl;
}
int qry(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;int mn=N+2;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;upd(max(x-k,1),1);upd(x+1,-1);
    mn=min(mn,x);
  }
  while(mn>k)
  {
    int sum=0;
    for(int i=mn;i<=N;i+=mn)
      sum+=qry(i);
    if(sum>=n)break;
    mn--;
  }
  cout<<mn<<endl;
  return 0;
}