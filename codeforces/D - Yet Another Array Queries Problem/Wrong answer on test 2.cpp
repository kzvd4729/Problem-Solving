/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 20:20                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/863/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,q,m,arr[N+2];
int mm[N+2];
struct data
{
  int ty,l,r;
}qu[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=1;i<=q;i++)
    cin>>qu[i].ty>>qu[i].l>>qu[i].r;
  for(int i=1;i<=m;i++)
    cin>>mm[i];
   for(int i=1;i<=q;i++)
  {
    if(qu[i].ty==1)
    {
      for(int j=1;j<=m;j++)
      {
        if(mm[j]>=qu[i].l&&mm[j]<=qu[i].r)
        {
          if(mm[j]==qu[i].r)
            mm[j]=qu[i].l;
          else mm[j]++;
        }
      }
    }
    else
    {
      for(int j=1;j<=m;j++)
      {
        if(mm[j]>=qu[i].l&&mm[j]<=qu[i].r)
          mm[j]=qu[i].r-(mm[j]-qu[i].l);
      }
    }
//    for(int j=1;j<=m;j++)
//      cout<<arr[mm[j]]<<" ";
//    cout<<endl;
  }
  for(int i=1;i<=m;i++)
    cout<<arr[mm[i]]<<" ";
  return 0;
}