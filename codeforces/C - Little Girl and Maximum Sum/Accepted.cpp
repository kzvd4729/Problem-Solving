/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2018 22:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/276/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int bit[N+2],arr[N+2];
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
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>arr[i];
  sort(arr+1,arr+n+1);
  while(q--)
  {
    int lt,rt;cin>>lt>>rt;
    upd(lt,1);upd(rt+1,-1);
  }
  priority_queue<int>pq;
  for(int i=1;i<=n;i++)
    pq.push(qry(i));
  long sum=0;
  for(int i=n;i>=1;i--)
  {
    sum+=(pq.top()*(arr[i]*1LL));
    pq.pop();
  }
  cout<<sum<<endl;
  return 0;
}