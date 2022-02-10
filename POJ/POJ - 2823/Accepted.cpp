/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-14 20:34:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 11500                                      memory_used (MB): 9.8                             
*  problem: https://vjudge.net/problem/POJ-2823
****************************************************************************************/
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int n,k,arr[1000000+6];
deque<pair<int,int> >dq;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
  for(int i=1;i<=n;i++)
  {
    while(dq.size())
    {
      if(dq.back().first>=arr[i])dq.pop_back();else break;
    }
    dq.push_back(make_pair(arr[i],i));
    if(dq.front().second<=i-k)dq.pop_front();
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
    dq.push_back(make_pair(arr[i],i));
    if(dq.front().second<=i-k)dq.pop_front();
    if(i>=k)printf("%d ",dq.front().first);
  }
  printf("\n");
  return 0;
}