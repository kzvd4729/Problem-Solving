/****************************************************************************************
*  @author: kzvd4729                                         created: 18-03-2018 21:51:03                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/COOK92A/problems/CO92SUBW
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=44725;
const long inf=2e9;
long arr[1000000],t,x,id;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  arr[1]=1;
  for(int i=2; ;i++)
  {
    arr[i]=arr[i-1]+i;
    if(arr[i]>inf)break;
  }
  cin>>t;
  while(t--)
  {
    cin>>x;
    long lo=0,hi=N,md;
    while(hi-lo>3)
    {
      md=(lo+hi)/2;
      if(arr[md]<x)lo=md;
      else hi=md;
    }
    for(int i=lo;i<=hi;i++)if(arr[i]<=x)id=i;
    cout<<id+min(x-arr[id],arr[id+1]-x+1)<<endl;
  }
  return 0;
}