/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-06 20:09:29                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2823
****************************************************************************************/
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int n,k,arr[1000006];
deque<pair<int,int> >dq;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
  for(int i=1;i<=n;i++)
  {
    while(dq.size())
    {
      if(dq.back().first>=arr[i])dq.pop_back();
      else break;
    }
    dq.push_back({arr[i],i});
    while(dq.size())
    {
      if(dq.front().second<=i-k)dq.pop_front();
      else break;
    }
    if(i>=k)printf("%d ",dq.front().first);
  }
  printf("\n");
  while(dq.size())dq.pop_back();
  for(int i=1;i<=n;i++)
  {
    while(dq.size())
    {
      if(dq.back().first<=arr[i])dq.pop_back();
      else break;
    }
    dq.push_back({arr[i],i});
    while(dq.size())
    {
      if(dq.front().second<=i-k)dq.pop_front();
      else break;
    }
    if(i>=k)printf("%d ",dq.front().first);
  }
  printf("\n");
  return 0;
}