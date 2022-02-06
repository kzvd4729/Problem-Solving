/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2020 19:47                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1292/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2],sf[2][N+2];
set<int>bl;
void upd(int i)
{
  int f=0;
  if(aa[i]&&(bb[i]|bb[i+1]|bb[i-1]))f=1;
  if(bb[i]&&(aa[i]|aa[i+1]|aa[i-1]))f=1;
   if(f)bl.insert(i);
  else
  {
    if(bl.find(i)!=bl.end())bl.erase(i);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  while(q--)
  {
    int a,b;cin>>a>>b;
    if(a==1){aa[b]^=1;upd(b);}
    else {bb[b]^=1;upd(b);}
    if(bl.size()==0)cout<<"Yes\n";
    else cout<<"No\n";
  }
  return 0;
}