/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-06 00:05:25                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2823
****************************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define long long long
using namespace std;
long n,k,arr[1000006];
map<long,long>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;
  for(long i=1;i<=n;i++)cin>>arr[i];
  for(long i=1;i<=n;i++)
  {
    if(i<k)mp[arr[i]]++;
    else if(i==k)
    {
      mp[arr[i]]++;
      cout<<mp.begin()->first<<" ";
    }
    else
    {
      mp[arr[i]]++;
      mp[arr[i-k]]--;
      if(mp[arr[i-k]]==0)mp.erase(arr[i-k]);
      cout<<mp.begin()->first<<" ";
    }
  }
  cout<<endl;
  mp.clear();
  for(long i=1;i<=n;i++)
  {
    if(i<k)mp[arr[i]]++;
    else if(i==k)
    {
      mp[arr[i]]++;
      cout<<mp.rbegin()->first<<" ";
    }
    else
    {
      mp[arr[i]]++;
      mp[arr[i-k]]--;
      if(mp[arr[i-k]]==0)mp.erase(arr[i-k]);
      cout<<mp.rbegin()->first<<" ";
    }
  }
  cout<<endl;
  return 0;
}