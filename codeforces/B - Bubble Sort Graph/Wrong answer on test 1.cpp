/****************************************************************************************
*  @author: kzvd4729                                         created: May/16/2019 22:16                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/341/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int bit[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    bit[x]=max(bit[x],vl);
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret=max(ret,bit[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;int mx=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    int now=get(x);mx=max(mx,now+1);
    upd(x,now+1);
  }
  cout<<mx<<endl;
  return 0;
}