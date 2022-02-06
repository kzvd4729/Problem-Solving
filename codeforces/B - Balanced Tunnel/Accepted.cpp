/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2019 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1237/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],bit[N+2],n,pos[N+2];
void upd(int x,int vl)
{
  for( ;x<=n;x+=x&-x)
    bit[x]+=vl;
}
int get(int x)
{
  int sum=0;
  for( ;x>0;x-=x&-x)
    sum+=bit[x];
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i],pos[aa[i]]=i;
    upd(i,1);//upd(i+1,-1);
  }
  //cout<<"*"<<get(3)<<endl;
  for(int i=1;i<=n;i++)cin>>bb[i];
   int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(get(pos[bb[i]]-1))ans++;
    upd(pos[bb[i]],-1);
  }
  cout<<ans<<endl;
  return 0;
}