/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-06 00:16:59                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2823
****************************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;
int n,k,arr[1000006],on[1000006],tw[1000006],id;
map<int,int>mp;
int main()
{
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
  for(int i=1;i<=n;i++)
  {
    if(i<k)mp[arr[i]]++;
    else if(i==k)
    {
      mp[arr[i]]++;
      id++;
      on[id]=mp.begin()->first;
      tw[id]=mp.rbegin()->first;
    }
    else
    {
      mp[arr[i]]++;
      mp[arr[i-k]]--;
      if(mp[arr[i-k]]==0)mp.erase(arr[i-k]);
      id++;
      on[id]=mp.begin()->first;
      tw[id]=mp.rbegin()->first;
    }
  }
  for(int i=1;i<=id;i++)
  {
    printf("%d",on[i]);
    if(i==id)printf("\n");
    else printf(" ");
  }
  for(int i=1;i<=id;i++)
  {
    printf("%d",tw[i]);
    if(i==id)printf("\n");
    else printf(" ");
  }
  return 0;
}