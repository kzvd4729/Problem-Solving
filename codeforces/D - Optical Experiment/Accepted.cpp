/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2018 20:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1060 ms                                         memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/67/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bit[N+2],pos[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    bit[x]=max(bit[x],vl);
}
int qry(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret=max(ret,bit[x]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;pos[x]=i;
  }
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    aa[i]=pos[x];
  }
  int mx=0;
  for(int i=n;i>=1;i--)
  {
    int xx=qry(aa[i])+1;
    mx=max(mx,xx);upd(aa[i],xx);
  }
  cout<<mx<<endl;
  return 0;
}