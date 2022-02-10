/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-06 00:08:54                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2823
****************************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,k,arr[1000006];
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
      printf("%d",mp.begin()->first);
      if(i==n)printf("\n");
      else printf(" ");
    }
    else
    {
      mp[arr[i]]++;
      mp[arr[i-k]]--;
      if(mp[arr[i-k]]==0)mp.erase(arr[i-k]);
      printf("%d",mp.begin()->first);
      if(i==n)printf("\n");
      else printf(" ");
    }
  }
  mp.clear();
  for(int i=1;i<=n;i++)
  {
    if(i<k)mp[arr[i]]++;
    else if(i==k)
    {
      mp[arr[i]]++;
      printf("%d",mp.rbegin()->first);
      if(i==n)printf("\n");
      else printf(" ");
    }
    else
    {
      mp[arr[i]]++;
      mp[arr[i-k]]--;
      if(mp[arr[i-k]]==0)mp.erase(arr[i-k]);
      printf("%d",mp.rbegin()->first);
      if(i==n)printf("\n");
      else printf(" ");
    }
  }
  return 0;
}