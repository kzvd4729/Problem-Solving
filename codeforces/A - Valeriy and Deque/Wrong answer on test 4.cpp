/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/23/2019 23:00                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1179/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q,mx=0;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i],mx=max(mx,aa[i]);
  deque<int>dq;
  for(int i=1;i<=n;i++)
    dq.push_back(aa[i]);
  int id=0;
  while(true)
  {
    if(dq.front()==mx)break;
    int a=dq.front();dq.pop_front();
    int b=dq.front();dq.pop_front();
    ++id;bb[id]=a,cc[id]=b;
    if(a<b)swap(a,b);dq.push_back(b);
    dq.push_front(a);
  }
  for(int i=1;i<=n;i++)
  {
    aa[i]=dq.front();dq.pop_front();
  }
  /*cout<<id<<endl;
  for(int i=1;i<=n;i++)cout<<aa[i];
  cout<<endl;*/
  while(q--)
  {
    long x;cin>>x;
    if(x<=id)cout<<bb[x]<<" "<<cc[x]<<"\n";
    else
    {
      x-=id;x=x%(n-1);x--;
      cout<<aa[1]<<" "<<aa[2+x]<<"\n";
    }
  }
  return 0;
}